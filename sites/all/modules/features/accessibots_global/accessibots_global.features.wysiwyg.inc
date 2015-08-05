<?php
/**
 * @file
 * accessibots_global.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function accessibots_global_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: html
  $profiles['html'] = array(
    'format' => 'html',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 1,
      'theme' => '',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'Underline' => 1,
          'Strike' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Unlink' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'HorizontalRule' => 1,
          'PasteFromWord' => 1,
          'RemoveFormat' => 1,
          'Format' => 1,
          'SpellChecker' => 1,
          'Scayt' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 1,
      'acf_mode' => 0,
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => '%sites/all/themes/abtheme/css/wysiwyg.css',
      'stylesSet' => '',
      'block_formats' => 'p,pre,h2,h3,h4,h5,h6,div',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 0,
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
