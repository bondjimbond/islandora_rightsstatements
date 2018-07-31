# Islandora Rights Statements Badge

## Introduction

Islandora Rightsstatements provides block containing a Rightsstatements.org button with a link to the statement URI and its details.
It reads the Rightsstatements.org URI from a Solr field, and builds the HTML from the appropriate assets at Rightsstatements.org.

Example badge image:

![Example badge](https://raw.githubusercontent.com/rightsstatements/rightsstatements.github.io/master/files/buttons/InC.dark.png)

The badge will only display on objects with a Rightsstatements.org URI in some defined element.

## Requirements

This module requires the following modules/libraries:

* [Islandora](https://github.com/islandora/islandora)
* [Islandora Solr](https://github.com/islandora/islandora_solr)
* [Islandora Badges](../../)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

Configuration path is admin/islandora/tools/badges/creativecommons (Administration > Islandora > Islandora Utility Modules > Islandora Badges Configuration > CC Badge).

* Solr field for Rightsstatements.org URI: Defaults to mods_accessCondition_ms. dc.rights would also be a good choice. Prefer a multivalued field.
* Image style: Choose small icon (just the symbol) or Large button (symbol plus text).
* Image Height: Set the image height in pixels.
* Image Colour: Rightsstatements.org provides black or white icons, and buttons with black text or blue text.

## Troubleshooting/Issues

Having problems or solved a problem? Check out the Islandora google groups for a solution.

* [Islandora Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora)
* [Islandora Dev Group](https://groups.google.com/forum/?hl=en&fromgroups#!forum/islandora-dev)

## Maintainers/Sponsors

Current maintainers:

* [Brandon Weigel](https://github.com/bondjimbond)

## Development

If you would like to contribute to this module, please check out [CONTRIBUTING.md](CONTRIBUTING.md). In addition, we have helpful [Documentation for Developers](https://github.com/Islandora/islandora/wiki#wiki-documentation-for-developers) info, as well as our [Developers](http://islandora.ca/developers) section on the [Islandora.ca](http://islandora.ca) site.

## License

[GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
