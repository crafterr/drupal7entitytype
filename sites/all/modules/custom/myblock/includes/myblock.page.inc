<?php
function myblock_page()
{

  $block = block_load('myblock', 'myblock');

//  $variables['myblock'] = _block_get_renderable_array(_block_render_blocks(array($block)));
  return _block_get_renderable_array(_block_render_blocks(array($block)));
}