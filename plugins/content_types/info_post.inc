<?php

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Info about page'),
  'description' => t('Info about page'),
  'category' => t('Node'),
  'icon' => '',
  'render callback' => 'info_post_block',
  'required context' => new ctools_context_required(t('Node'), 'node'),
  'defaults' => array(),
);

/**
 * render callback
 */
function info_post_block($subtype, $conf, $panel_args, $context) {
  // Check context.
  if (empty($context) || empty($context->data)) {
    return;
  }

  // Get node tags
  $all_tags = $context->data->field_tags['und'];
  // need 3
  array_splice($all_tags, 3);
  // prepare array
  foreach($all_tags as &$tag){
    $tag = $tag['tid'];
  }

  $terms = taxonomy_term_load_multiple($all_tags);
  // build string
  if(!empty($terms)) {
    $context->data->tags = '<ul>';
    foreach ($terms as $term) {
      $context->data->tags .= '<li>' . l($term->name, 'taxonomy/term/' . $term->tid) . '</li>';
    }
    $context->data->tags .= '</ul>';
  }
  // get to block
  $content = array(
    '#theme' => 'info_post_block',
    '#content' => $context->data,
  );

  // Create block end send to node
  $block = new stdClass();
  $block->module = 'info_post';
  $block->content = $content;
  $block->title = t('Info about page');
  return $block;
}