<?php

/**
 * Our custom entity class.
 *
 * The Entity class we're overriding is in
 * sites/all/modules/contrib/entity/includes/entity.inc
 */
class VideoEntity extends Entity {
  /**
   * Override this in order to implement a custom default URI.
   */
  protected function defaultUri() {
    return array('path' => 'video/' . $this->identifier());
  }
}