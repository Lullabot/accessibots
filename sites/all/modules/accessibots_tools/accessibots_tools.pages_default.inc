<?php
/**
 * @file
 * accessibots_tools.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function accessibots_tools_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'tools';
  $page->task = 'page';
  $page->admin_title = 'Tools';
  $page->admin_description = '';
  $page->path = 'tools';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Tools',
    'name' => 'main-menu',
    'weight' => '5',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_tools__panel_context_bddc8f1f-e6f5-403f-ac4e-ea2178ade671';
  $handler->task = 'page';
  $handler->subtask = 'tools';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'ab_onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Tools';
  $display->uuid = '31f26d42-1709-4652-aeba-09e50be1d472';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-db0f12a7-55fe-49bd-ba11-c3d73049c7f9';
    $pane->panel = 'main';
    $pane->type = 'views';
    $pane->subtype = 'tools';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
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
    $pane->uuid = 'db0f12a7-55fe-49bd-ba11-c3d73049c7f9';
    $display->content['new-db0f12a7-55fe-49bd-ba11-c3d73049c7f9'] = $pane;
    $display->panels['main'][0] = 'new-db0f12a7-55fe-49bd-ba11-c3d73049c7f9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-db0f12a7-55fe-49bd-ba11-c3d73049c7f9';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tools'] = $page;

  return $pages;

}
