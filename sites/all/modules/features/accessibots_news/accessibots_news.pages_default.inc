<?php
/**
 * @file
 * accessibots_news.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function accessibots_news_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__news_events';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'News & Events',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'news_events',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'news' => 'news',
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
  $display->uuid = 'be0a0bff-ab96-498d-b601-444e31a6bdb6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-350c5669-34c0-4c90-a504-067d1cba937e';
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
    $pane->uuid = '350c5669-34c0-4c90-a504-067d1cba937e';
    $display->content['new-350c5669-34c0-4c90-a504-067d1cba937e'] = $pane;
    $display->panels['header'][0] = 'new-350c5669-34c0-4c90-a504-067d1cba937e';
    $pane = new stdClass();
    $pane->pid = 'new-c99e99af-a3b4-48ee-be0e-ad95f44adf21';
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
    $pane->uuid = 'c99e99af-a3b4-48ee-be0e-ad95f44adf21';
    $display->content['new-c99e99af-a3b4-48ee-be0e-ad95f44adf21'] = $pane;
    $display->panels['main'][0] = 'new-c99e99af-a3b4-48ee-be0e-ad95f44adf21';
    $pane = new stdClass();
    $pane->pid = 'new-baba0ca7-860a-4fb1-9baf-6a036b7034cc';
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
    $pane->uuid = 'baba0ca7-860a-4fb1-9baf-6a036b7034cc';
    $display->content['new-baba0ca7-860a-4fb1-9baf-6a036b7034cc'] = $pane;
    $display->panels['main'][1] = 'new-baba0ca7-860a-4fb1-9baf-6a036b7034cc';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-350c5669-34c0-4c90-a504-067d1cba937e';
  $handler->conf['display'] = $display;
  $export['node_view__news_events'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function accessibots_news_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'news_events';
  $page->task = 'page';
  $page->admin_title = 'News & Events';
  $page->admin_description = '';
  $page->path = 'news';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'News & Events',
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
  $handler->name = 'page_news_events__panel_context_5e704b09-a686-4802-952a-59909ee4b9c6';
  $handler->task = 'page';
  $handler->subtask = 'news_events';
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
  $display->title = 'News & Events';
  $display->uuid = '614a5a11-036f-4272-927a-d9f44266548b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2a60e66f-b96f-4901-8a9d-58b4cee71130';
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
    $pane->uuid = '2a60e66f-b96f-4901-8a9d-58b4cee71130';
    $display->content['new-2a60e66f-b96f-4901-8a9d-58b4cee71130'] = $pane;
    $display->panels['header'][0] = 'new-2a60e66f-b96f-4901-8a9d-58b4cee71130';
    $pane = new stdClass();
    $pane->pid = 'new-f3dd66f7-8ad6-447c-9cab-c0310a9988e7';
    $pane->panel = 'main';
    $pane->type = 'views_panes';
    $pane->subtype = 'news_events-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'staggered',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f3dd66f7-8ad6-447c-9cab-c0310a9988e7';
    $display->content['new-f3dd66f7-8ad6-447c-9cab-c0310a9988e7'] = $pane;
    $display->panels['main'][0] = 'new-f3dd66f7-8ad6-447c-9cab-c0310a9988e7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-f3dd66f7-8ad6-447c-9cab-c0310a9988e7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['news_events'] = $page;

  return $pages;

}
