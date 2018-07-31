<?php
/**
 * @file
 * Rightsstatements badge admin options
 */
function islandora_rightsstatements_admin_form($form, $form_settings) {
  $form['islandora_rightsstatements_rights_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Solr field for Rightsstatements.org URI'),
    '#description' => t('The solr field that contains the Rightsstatements.org URI'),
    '#default_value' => variable_get('islandora_rightsstatements_rights_field', 'dc.rights'),
  );

  $form['islandora_rightsstatements_button_style'] = array(
    '#type' => 'radios',
    '#title' => t('Image style'),
    '#description' => t('The type of image returned as your Rights Statements badge.'),
    '#options' => array('icons' => t('Small icon'), 'buttons' => t('Large button with text')),
    '#default_value' => variable_get('islandora_rightsstatements_button_style', 'buttons'),
  );

  $form['islandora_rightsstatements_image_height'] = array(
    '#type' => 'textfield',
    '#title' => t('Image Height'),
    '#description' => t('The height in pixels for the Rightsstatements badge image.'),
    '#default_value' => variable_get('islandora_rightsstatements_image_height', '31'),
  );
  
  $form['islandora_rightsstatements_image_colour'] = array(
    '#type' => 'radios',
    '#title' => t('Image Colour'),
    '#description' => t('The colour of the text and image in the Rightsstatements badge.'),
    '#options' => array('dark' => t('Black with transparent icon interior'), 'white' => t('All white'), 
      'dark-white-interior' => t('Black with white icon interior'), 'dark-white-interior-blue-type' => t('Black with blue type (Button style only)')),
    '#default_value' => variable_get('islandora_rightsstatements_image_colour', 'dark'),                                           
  );

  return system_settings_form($form);
}

