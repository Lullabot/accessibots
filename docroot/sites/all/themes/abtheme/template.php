<?php

function abtheme_preprocess_page(&$vars) {
  $vars['main_menu'] = menu_tree('main-menu');
}
