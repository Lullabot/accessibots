<?php
/**
 * @file
 * accessibots_tools.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function accessibots_tools_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__tool';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Tool',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'tool',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'tool' => 'tool',
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
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'header' => NULL,
      'main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '1720caef-8d2b-43fa-96bd-d2b7c2d1df8b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-881e3752-22d4-444a-bbc3-e3d0095cca84';
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
    $pane->uuid = '881e3752-22d4-444a-bbc3-e3d0095cca84';
    $display->content['new-881e3752-22d4-444a-bbc3-e3d0095cca84'] = $pane;
    $display->panels['header'][0] = 'new-881e3752-22d4-444a-bbc3-e3d0095cca84';
    $pane = new stdClass();
    $pane->pid = 'new-776d1068-1ffe-41f7-97e3-6d4f49aac27b';
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
    $pane->uuid = '776d1068-1ffe-41f7-97e3-6d4f49aac27b';
    $display->content['new-776d1068-1ffe-41f7-97e3-6d4f49aac27b'] = $pane;
    $display->panels['main'][0] = 'new-776d1068-1ffe-41f7-97e3-6d4f49aac27b';
    $pane = new stdClass();
    $pane->pid = 'new-2fb02137-4ca5-4653-a493-1ab51526b159';
    $pane->panel = 'main';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '2fb02137-4ca5-4653-a493-1ab51526b159';
    $display->content['new-2fb02137-4ca5-4653-a493-1ab51526b159'] = $pane;
    $display->panels['main'][1] = 'new-2fb02137-4ca5-4653-a493-1ab51526b159';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-776d1068-1ffe-41f7-97e3-6d4f49aac27b';
  $handler->conf['display'] = $display;
  $export['node_view__tool'] = $handler;

  return $export;
}

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
  $display->title = '';
  $display->uuid = '31f26d42-1709-4652-aeba-09e50be1d472';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-75fb76a8-f20a-41d9-b8d7-1f2781ffd8df';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'tools-panel_pane_1';
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
    $pane->css = array(
      'css_id' => '',
      'css_class' => '',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '75fb76a8-f20a-41d9-b8d7-1f2781ffd8df';
    $display->content['new-75fb76a8-f20a-41d9-b8d7-1f2781ffd8df'] = $pane;
    $display->panels['main'][0] = 'new-75fb76a8-f20a-41d9-b8d7-1f2781ffd8df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['tools'] = $page;

  return $pages;

}
