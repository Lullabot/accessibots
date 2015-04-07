<?php
/**
 * @file
 * Twitter Pull bean plugin.
 */

class TwitterTimelineBean extends BeanPlugin {
  /**
   * Declares default block settings.
   */
  public function values() {
    return array(
      'settings' => array(
        'widget_id' => '',
        'placeholder_text' => '',
        'placeholder_url' => '',
      ),
    );
  }

  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = array();
    $form['settings'] = array(
      '#type' => 'fieldset',
      '#tree' => 1,
      '#title' => t('Options'),
    );

    $form['settings']['widget_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Widget ID'),
      '#description' => t('ID of the widget to embed.'),
      '#size' => 25,
      '#maxlength' => 25,
      '#default_value' => isset($bean->settings['widget_id']) ? $bean->settings['widget_id'] : '',
    );

    $form['settings']['placeholder_text'] = array(
      '#type' => 'textfield',
      '#title' => t('Placeholder text'),
      '#description' => t('Text to display while the twitter widget loads.'),
      '#default_value' => isset($bean->settings['placeholder_text']) ? $bean->settings['placeholder_text'] : '',
    );

    $form['settings']['placeholder_url'] = array(
      '#type' => 'textfield',
      '#title' => t('Placeholder url'),
      '#description' => t('Link for the placeholder text.'),
      '#default_value' => isset($bean->settings['placeholder_url']) ? $bean->settings['placeholder_url'] : '',
    );

    return $form;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $content['twitter_timeline']['#markup'] = twitter_timeline_render($bean->settings['widget_id'], $bean->settings['placeholder_text'], $bean->settings['placeholder_url']);
    return $content;
  }
}
