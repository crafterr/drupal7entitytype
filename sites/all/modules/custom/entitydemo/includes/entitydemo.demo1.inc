<?php
function entitydemo_page1() {
  $node = node_load(1);
  //return 'Hello world - '.$node->title;
  $view = node_view($node, 'teaser');
  return drupal_render($view);
  //return theme('node', array('#node' => $node,'#view_mode'=>'default'));
}