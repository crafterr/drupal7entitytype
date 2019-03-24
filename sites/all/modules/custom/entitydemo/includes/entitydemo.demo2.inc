<?php
function entitydemo_page2()
{
  //documentation
  //https://www.drupal.org/node/1343708
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type','node');
  $result = $query->execute();

  $query2 = new EntityFieldQuery();
  $query2->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('promote',1)
   // ->fieldOrderBy('')
  ->range(0,10);
  $result = $query2->execute();
  $nids = array_keys($result['node']);

  //$nodes = node_load_multiple($nids);
  $nodes = entity_load('node',$nids);
  dpm($nodes);
  //if fields
 // $query2->fieldCondition('field_nameoffield','value','valueoffield','=');

  return 'weszlo';
}