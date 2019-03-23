<?php
function entitydemo_page2()
{
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type','node');
  $result = $query->execute();

  $query2 = new EntityFieldQuery();
  $query2->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'article')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->propertyCondition('title', 'My article', '=');
  //if fields
 // $query2->fieldCondition('field_nameoffield','value','valueoffield','=');

  dpm($query2->execute());
  return 'weszlo';
}