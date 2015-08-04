<?php

/**
 * Implements template_preprocess().
 * @param $vars
 */
function abtheme_preprocess(&$vars, $hook) {
  //dpm($hook);
  switch ($hook) {
    case 'cbase_panel_golden':
      // Load the messages.
      $vars['messages'] = theme('status_messages');
      $vars['tabs'] = menu_local_tabs();
      $vars['action_links'] = menu_local_actions();

      // Define attributes for the panel wrapper element.
      $vars['panel_attributes'] = array(
        'class' => $vars['classes_array'],
      );

      // Add the ID
      if (isset($vars['css_id'])) {
        $vars['panel_attributes']['id'] = $vars['css_id'];
      }

      // Check for the golden content position.
      if (isset($vars['settings']['golden_main_position'])) {
        $vars['panel_attributes']['class'][] = $vars['settings']['golden_main_position'];
      }

      // Set the appropriate elements based on whether this is a node rendering or not.
      if ($node = menu_get_object()) {
        $vars['node'] = $node;
        $vars['element'] = array(
          'main' => 'section',
          'content' => 'article',
        );
      }
      else {
        $vars['element'] = array(
          'main' => 'div',
          'content' => 'section',
        );
      }
      break;
  }
}

/**
 * Implements template_preprocess_page().
 * @param $vars
 */
function abtheme_preprocess_page(&$vars) {
  $vars['main_menu'] = menu_tree('main-menu');
}

/**
 * Implements template_preprocess_node().
 * @param $vars
 */
function abtheme_preprocess_node(&$vars) {
  $bundle = $vars['type'];
  $view_mode = $vars['view_mode'];
  $vars['background_image_path'] = '';

  // Build the classes array.
  foreach ($vars['classes_array'] as $key => &$class) {
    // Remove node-* classes.
    if (strpos($class, 'node-') === 0) {
      unset($vars['classes_array'][$key]);
    }

    switch ($class) {
      case 'sticky':
        $class = "{$bundle}--{$view_mode}--sticky";
        break;

      case 'promote':
        $class = "{$bundle}--{$view_mode}--promoted";
        break;

      case 'clearfix':
        unset($vars['classes_array'][$key]);
        break;
    }
  }

  // Add BEM classes
  $vars['classes_array'][] = "{$view_mode}";
  $vars['classes_array'][] = "{$bundle}--{$view_mode}";

  // Setup proper article attributes
  $vars['attributes_array']['class'] = $vars['classes_array'];


  // Check for a background image, though we should always have one.
  if (isset($vars['content']['field_background_image'][0]['#item'])) {
    // If the derivative has been generated, use that path.
    if (!empty($vars['content']['field_background_image'][0]['#path'])) {
      $vars['background_image_path'] = $vars['content']['field_background_image'][0]['#path'];
    }
    // Else, manually derive the image
    else {
      $style = $vars['content']['field_background_image'][0]['#image_style'];
      $uri = $vars['content']['field_background_image'][0]['#item']['uri'];

      $vars['background_image_path'] = image_style_url($style, $uri);
    }
  }
}

/**
 * Preprocess fields.
 */
function abtheme_preprocess_field(&$vars) {
  $bem_block          = drupal_html_class($vars['element']['#bundle']);
  $bem_block_modifier = drupal_html_class($vars['element']['#view_mode']);
  $bem_element        = 'field';
  $bem_element_m1     = drupal_html_class($vars['element']['#field_type']);
  $bem_element_m2     = drupal_html_class($vars['element']['#field_name']);

  $vars['attributes_array']['class'] = array(
    "{$bem_element}--{$bem_element_m1}",
    "{$bem_element}--{$bem_element_m1}--{$bem_element_m2}",
    "{$bem_block}--{$bem_block_modifier}__{$bem_element}--{$bem_element_m1}--{$bem_element_m2}",
  );
}

/**
 * Overrides hook_theme_menu_link().
 * Add an aria-label attribute for the menu items so that Voice Over won't read
 * three letter words as acronymns.  Otherwise VO would read "W-H-O We Are"
 * instead of "Who We Are".
 */
function abtheme_menu_link__main_menu(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $element['#localized_options'] = array_merge($element['#localized_options'], array('attributes' => array('aria-label' => $element['#title'])));
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
