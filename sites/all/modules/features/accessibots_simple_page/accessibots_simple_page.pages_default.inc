<?php
/**
 * @file
 * accessibots_simple_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function accessibots_simple_page_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__simple_page';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Simple Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'simple_page',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'simple_page' => 'simple_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'ab_onecol';
  $display->layout_settings = array(
    'golden_main_position' => 'left',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'first' => NULL,
      'second' => NULL,
      'bottom' => NULL,
      'header' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'a5a25ad2-75e9-49e4-9f26-6996ed7b4976';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-11f03129-15fe-4937-8af4-3a8af5e15448';
    $pane->panel = 'header';
    $pane->type = 'page_title';
    $pane->subtype = 'page_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'markup' => 'h1',
      'class' => '',
      'id' => '',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '11f03129-15fe-4937-8af4-3a8af5e15448';
    $display->content['new-11f03129-15fe-4937-8af4-3a8af5e15448'] = $pane;
    $display->panels['header'][0] = 'new-11f03129-15fe-4937-8af4-3a8af5e15448';
    $pane = new stdClass();
    $pane->pid = 'new-f2ca23fd-d3fe-4257-9b28-a6105b887849';
    $pane->panel = 'main';
    $pane->type = 'page_messages';
    $pane->subtype = 'page_messages';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f2ca23fd-d3fe-4257-9b28-a6105b887849';
    $display->content['new-f2ca23fd-d3fe-4257-9b28-a6105b887849'] = $pane;
    $display->panels['main'][0] = 'new-f2ca23fd-d3fe-4257-9b28-a6105b887849';
    $pane = new stdClass();
    $pane->pid = 'new-afbcdc50-08a0-459e-b51a-0866a0a4e258';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '%node:title',
      'override_title_heading' => 'h1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'afbcdc50-08a0-459e-b51a-0866a0a4e258';
    $display->content['new-afbcdc50-08a0-459e-b51a-0866a0a4e258'] = $pane;
    $display->panels['main'][1] = 'new-afbcdc50-08a0-459e-b51a-0866a0a4e258';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-afbcdc50-08a0-459e-b51a-0866a0a4e258';
  $handler->conf['display'] = $display;
  $export['node_view__simple_page'] = $handler;

  return $export;
}
