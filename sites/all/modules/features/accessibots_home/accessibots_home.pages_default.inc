<?php
/**
 * @file
 * accessibots_home.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function accessibots_home_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Home',
    'name' => 'main-menu',
    'weight' => '0',
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
  $handler->name = 'page_homepage__panel_context_fc875a39-1bd3-4009-83d1-00fd4b217057';
  $handler->task = 'page';
  $handler->subtask = 'homepage';
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
  $display->layout = 'cbase_golden';
  $display->layout_settings = array(
    'golden_main_position' => 'left',
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
      'top' => NULL,
      'first' => NULL,
      'second' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'We Are the Accessibots';
  $display->uuid = '1fe248b0-0155-4d94-afd0-d248531840b2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-8fc62e8b-5ee6-439d-b9d1-3c79e6f686fa';
    $pane->panel = 'first';
    $pane->type = 'node';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'nid' => '1',
      'links' => 0,
      'leave_node_title' => 0,
      'identifier' => '',
      'build_mode' => 'teaser',
      'link_node_title' => 0,
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
    $pane->uuid = '8fc62e8b-5ee6-439d-b9d1-3c79e6f686fa';
    $display->content['new-8fc62e8b-5ee6-439d-b9d1-3c79e6f686fa'] = $pane;
    $display->panels['first'][0] = 'new-8fc62e8b-5ee6-439d-b9d1-3c79e6f686fa';
    $pane = new stdClass();
    $pane->pid = 'new-017df947-2ffa-40f3-9630-15adecb49d73';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'bean-accessibots-twitter-feed';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
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
    $pane->uuid = '017df947-2ffa-40f3-9630-15adecb49d73';
    $display->content['new-017df947-2ffa-40f3-9630-15adecb49d73'] = $pane;
    $display->panels['second'][0] = 'new-017df947-2ffa-40f3-9630-15adecb49d73';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-8fc62e8b-5ee6-439d-b9d1-3c79e6f686fa';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}