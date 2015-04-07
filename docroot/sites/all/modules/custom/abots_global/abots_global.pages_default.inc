<?php
/**
 * @file
 * abots_global.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function abots_global_default_page_manager_handlers() {
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
  $display->layout = 'cbase_golden';
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
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'a5a25ad2-75e9-49e4-9f26-6996ed7b4976';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-afbcdc50-08a0-459e-b51a-0866a0a4e258';
    $pane->panel = 'first';
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
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'afbcdc50-08a0-459e-b51a-0866a0a4e258';
    $display->content['new-afbcdc50-08a0-459e-b51a-0866a0a4e258'] = $pane;
    $display->panels['first'][0] = 'new-afbcdc50-08a0-459e-b51a-0866a0a4e258';
    $pane = new stdClass();
    $pane->pid = 'new-ef9314d4-4102-4767-bb43-eee33dc9d1e0';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'bean-accessibots';
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
    $pane->uuid = 'ef9314d4-4102-4767-bb43-eee33dc9d1e0';
    $display->content['new-ef9314d4-4102-4767-bb43-eee33dc9d1e0'] = $pane;
    $display->panels['second'][0] = 'new-ef9314d4-4102-4767-bb43-eee33dc9d1e0';
    $pane = new stdClass();
    $pane->pid = 'new-11f03129-15fe-4937-8af4-3a8af5e15448';
    $pane->panel = 'top';
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
    $display->panels['top'][0] = 'new-11f03129-15fe-4937-8af4-3a8af5e15448';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-afbcdc50-08a0-459e-b51a-0866a0a4e258';
  $handler->conf['display'] = $display;
  $export['node_view__simple_page'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function abots_global_default_page_manager_pages() {
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
    $pane->pid = 'new-34275fba-af9e-4b2d-8cfd-2a662a5c0ff2';
    $pane->panel = 'second';
    $pane->type = 'block';
    $pane->subtype = 'bean-accessibots';
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
    $pane->uuid = '34275fba-af9e-4b2d-8cfd-2a662a5c0ff2';
    $display->content['new-34275fba-af9e-4b2d-8cfd-2a662a5c0ff2'] = $pane;
    $display->panels['second'][0] = 'new-34275fba-af9e-4b2d-8cfd-2a662a5c0ff2';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-8fc62e8b-5ee6-439d-b9d1-3c79e6f686fa';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['homepage'] = $page;

  return $pages;

}
