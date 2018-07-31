<?php

/**
 * @file
 * Utility functions.
 */

/**
 * Take URI, return HTML code for a rights statement badge.
 * @return string
 */
function islandora_rightsstatements_get_html($uri) {
  $height = variable_get('islandora_rightsstatements_image_height', '31');
  $colour = variable_get('islandora_rightsstatements_image_colour', 'dark');
  $style = variable_get('islandora_rightsstatements_button_style', 'buttons');

  // Extract just the statement terms from the URI to use in image URL
  $terms = substr($uri, strpos($uri, "/vocab/")+7);
  $terms = substr($terms, 0, strlen($terms)-5);
  if ($style == 'icons') {
    $style_filename = "Icon-Only.";
    // In case an unavailable colour is picked.
    if ($colour == 'dark-white-interior-blue-type') {
      $colour = 'dark-white-interior';
    }
    // Choose appropriate icon since they are less precise than buttons.
    if ($terms == 'CNE' || $terms == 'UND' || $terms == 'NKC') {
      $terms = 'Other';
    }
    elseif (strpos($terms, 'InC') !== false) {
      $terms = 'InC';
    }
    elseif (strpos($terms, 'NoC') !== false) {
      $terms = 'NoC';
    }
  }
  else {
    $style_filename = "";
  }
  $imagepath = drupal_get_path('module', 'islandora_rightsstatements');
  $image = $imagepath . '/images/' . $style . '/' . $terms . '.' . $style_filename . $colour . '.png';
  $options = array(
    'method' => 'GET',
    'headers' => array(
      'Accept' => 'application/json',
    ),
  );
  // The result has lots of objects that must be turned into arrays.
  $result = get_object_vars(drupal_http_request($uri, $options));
  $result_json = get_object_vars(drupal_http_request($result['headers']['location']));
  $result_json = get_object_vars(json_decode($result_json['data']));
  $definition = get_object_vars($result_json['definition']['2'])['@value'];
  $note = get_object_vars($result_json['note']['0'])['@value'];
  $title = get_object_vars($result_json['prefLabel']['1'])['@value'];
  $alt_text = $title . '<p>' . $definition . '</p><p>' . $note . '</p>';

  $img = array(
    '#theme' => 'image',
    '#path' => $image,
    '#alt' => $alt_text,
    '#height' => $height,
    '#title' => $title,
  );
  $badge = array(
    '#type' => 'link',
    '#title' => drupal_render($img),
    '#href' => $uri,
    '#options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
      'html' => TRUE,
    ),
  );
  return $badge;
}

/**
 * Get URI from the configured Solr field.
 * @return string
 */
function islandora_rightsstatements_get_uri(AbstractObject $object) {
  // Gets the rightsstatements.org URI from the configured Solr field.
  $qp = new islandoraSolrQueryProcessor();
  $qp->buildQuery(format_string('@field:"@pid"', array(
    '@field' => 'PID',
    '@pid' =>"{$object->id}")
  ));
  $uri_field = variable_get('islandora_rightsstatements_rights_field', 'dc.rights');
  $qp->solrParams['fl'] = implode(', ', array(
    'PID',
    $uri_field,
  ));
  $qp->solrStart = 0;
  $qp->solrLimit = 100000;
  $qp->executeQuery(FALSE);
  if ($qp->islandoraSolrResult['response']['numFound'] > 0) {
    if (array_key_exists($uri_field, $qp->islandoraSolrResult['response']['objects']['0']['solr_doc'])) {
      $rights_uri_array = ($qp->islandoraSolrResult['response']['objects']['0']['solr_doc'][$uri_field]);
      foreach ($rights_uri_array as $uri) {
        if (strpos($uri, 'rightsstatements.org')) {
          $rights_uri = $uri;
        }
      }
    }
  }
  if (!isset($rights_uri)) {
    return;
  }
  else {
    return $rights_uri;
  }
}
