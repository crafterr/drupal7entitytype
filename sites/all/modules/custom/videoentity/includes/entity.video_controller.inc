<?php

/**
 * Our custom controller for the videoentity type.
 *
 * We're choosing to extend the controller provided by the entity module for
 * full CRUD support for videoentities.
 *
 * The EntityAPIController is found in
 * sites/all/modules/contrib/entity/includes/entity.controller.inc
 */
class VideoEntityController extends EntityAPIController {

  public function buildContent($entity, $view_mode = 'non_member', $langcode = NULL, $content = []) {
    $build =  parent::buildContent($entity, $view_mode, $langcode, $content);

    $build['duration'] = [
      '#type' => 'markup',
      '#markup' => format_interval($entity->duration)
    ];
    if ($view_mode=='member') {
      $build['embedcode'] = [
        '#type' => 'markup',
        '#markup' => '<iframe width="560" height="315" src="http://www.youtube.com/embed/' . check_url($entity->embedcode) . '" frameborder="0" allowfullscreen></iframe>'
      ];
    } else {
      $build['embedcode'] = [
        '#type' => 'markup',
        '#markup' => '<p><a href="http://www.youtube.com/embed/' . check_url($entity->embedcode) . '">Link to youtube video</a></p>'
      ];
    }
    return $build;
  }

  /**
   * @param \EntityInterface $entity
   * @param \DatabaseTransaction|NULL $transaction
   *
   * @return bool|int
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {

    if (isset($entity->is_new)) {
      $entity->created_at = REQUEST_TIME;
    }

    $entity->updated_at = REQUEST_TIME;
    return parent::save($entity, $transaction);
  }
}