<?php
/**
 * Our custom controller for the admin ui.
 *
 * The EntityDefaultUIController can be found in
 * sites/all/modules/contrib/entity/includes/entity.ui.inc
 */
class VideoEntityUIController extends EntityDefaultUIController {

  public function overviewTableHeaders($conditions, $rows, $additional_header = []) {
    $header =  parent::overviewTableHeaders($conditions, $rows, $additional_header);
    $header[0] = 'Video';
    return $header;
  }
}