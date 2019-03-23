<?php
function entitydemo_page1() {
  $node = node_load(arg(1));

  $entity = entity_load('node',[1]);
  //give me the first object in arrray
  $entity = reset($entity);
  list($id,$vid,$bundle) = entity_extract_ids('node',$entity);

  //return 'Hello world - '.$node->title;
  $view = node_view($entity, 'teaser');
 // $view = node_view_multiple($nodes,'teaser');
  return drupal_render($view);
  //return theme('node', array('#node' => $node,'#view_mode'=>'default'));
}