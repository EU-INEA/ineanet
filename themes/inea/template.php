<?php
/**
 * @file
 * Default theme functions.
 */

/**
 * Implements theme_menu_tree_main_menu().
 */
function inea_menu_tree__main_menu($variables) {
  if (strpos($variables['tree'], 'main_menu_dropdown')) {
    // There is a dropdown in this tree.
    // (using a specific term "main_menu_dropdown" to avoid mistakes).
    $variables['tree'] = str_replace('<ul class="nav navbar-nav">', '<ul class="block-menu">', $variables['tree']);
    return '<ul class="nav navbar-nav">' . $variables['tree'] . '</ul>';
  }
  else {
    // There is no dropdown in this tree, simply return it in a <ul>.
    return '<ul class="nav navbar-nav">' . $variables['tree'] . '</ul>';
  }
}

/**
 * Implements theme_preprocess_page().
 */
function inea_preprocess_page(&$variables) {
  // Bottom region.
  $variables['regions']['site_bottom'] = (isset($variables['page']['site_bottom']) ? render($variables['page']['site_bottom']) : '');

  // Sidebars.
  $variables['cols']['sidebar_left'] = array(
    'lg' => (!empty($variables['regions']['sidebar_left']) ? 2 : 0),
    'md' => (!empty($variables['regions']['sidebar_left']) ? 3 : 0),
    'sm' => 0,
    'xs' => 0,
  );
  $variables['cols']['sidebar_right'] = array(
    'lg' => (!empty($variables['regions']['sidebar_right']) ? 2 : 0),
    'md' => (!empty($variables['regions']['sidebar_right']) ? (!empty($variables['regions']['sidebar_left']) ? 12 : 3) : 0),
    'sm' => 0,
    'xs' => 0,
  );

  // Content.
  $variables['cols']['content_main'] = array(
    'lg' => 12 - $variables['cols']['sidebar_left']['lg'] - $variables['cols']['sidebar_right']['lg'],
    'md' => ($variables['cols']['sidebar_right']['md'] == 3 ? 9 : 12 - $variables['cols']['sidebar_left']['md']),
    'sm' => 12,
    'xs' => 12,
  );
  $variables['cols']['content_right'] = array(
    'lg' => (!empty($variables['regions']['content_right']) ? 6 : 0),
    'md' => (!empty($variables['regions']['content_right']) ? 6 : 0),
    'sm' => (!empty($variables['regions']['content_right']) ? 12 : 0),
    'xs' => (!empty($variables['regions']['content_right']) ? 12 : 0),
  );
  $variables['cols']['content'] = array(
    'lg' => 12 - $variables['cols']['content_right']['lg'],
    'md' => 12 - $variables['cols']['content_right']['md'],
    'sm' => 12,
    'xs' => 12,
  );

  // Title.
  $variables['cols']['title'] = array(
    'lg' => 12,
    'md' => 12,
    'sm' => 12,
    'xs' => 12,
  );

  $variables['page_type'] = 'common';
  $variables['title_image'] = '';

  if (isset($variables['node']) && $variables['node']->type == "project") {
    $variables['page_type'] = 'project';
    $node = $variables['node'];
    if (!empty($node->field_tag_transport_mode)) {
      $tid = $node->field_tag_transport_mode['und'][0]['tid'];
    }
    elseif (!empty($node->field_tag_energy_type)) {
      $tid = $node->field_tag_energy_type['und'][0]['tid'];
    }
    $term_image = taxonomy_term_load($tid);
  }
  else {
    $path = explode("/", current_path());
    $term_name = end($path);
    $terms = taxonomy_get_term_by_name($term_name);
    if (empty($terms)) {
      $term_name = str_replace("-", " ", $term_name);
      $terms = taxonomy_get_term_by_name($term_name);
    }
    if (!empty($terms)) {
      $term_image = reset($terms);
    }
  }
  if (!empty($term_image) && isset($term_image->field_term_image['und'][0]['uri'])) {
    $image = theme('image', array(
      'path' => $term_image->field_term_image['und'][0]['uri'],
      'alt' => $term_image->name,
      'title' => $term_image->name,
    ));
    $path = _inea_generate_term_path($term_image);
    $variables['title_image'] = theme('link', array(
      'path' => $path,
      'text' => $image,
      'options' => array('html' => TRUE),
    ));
  }
}

/**
 * Implements theme_preprocess_menu_block_wrapper().
 */
function inea_preprocess_menu_block_wrapper(&$variables) {
  $variables['parent_link'] = '';
  $variables['container'] = 0;
  if ($variables['config']['level'] == 1 && $variables['config']['depth'] == 1) {
    // If block is for main menu.
    $variables['id'] = 'main-menu';
    $variables['container'] = 1;
  }
  elseif ($variables['config']['level'] == 2 && $variables['config']['depth'] == 2) {
    // If block is for left sidebar navigation.
    $main_menu = menu_tree_page_data('main-menu');
    foreach ($main_menu as $menu_item) {
      if ($menu_item['link']['in_active_trail'] == 1) {
        $parent_link = $menu_item['link'];
      }
    }
    if (!empty($parent_link)) {
      $options = array(
        'attributes' => array(
          'class' => array('parent-link'),
        ),
      );
      $variables['parent_link'] = l($parent_link['link_title'], $parent_link['link_path'], $options);
      $variables['parent_link'] .= '<div class="greyline"></div>';
      $variables['id'] = 'left-navigation';
    }
  }
}

/**
 * Implements theme_preprocess_taxonomy_term().
 */
function inea_preprocess_taxonomy_term(&$variables) {
  $variables['page'] = TRUE;
}

/**
 * Implements theme_preprocess_views_view().
 */
function inea_preprocess_views_view(&$variables) {
  if (isset($variables['view']->name)) {
    $function = '_inea_preprocess_views_view__' . $variables['view']->name;
    if (function_exists($function)) {
      $function($variables);
    }
    $function = '_inea_preprocess_views_view__' . $variables['view']->name . '__' . $variables['view']->current_display;
    if (function_exists($function)) {
      $function($variables);
    }
  }
}

/**
 * Helper function to preprocess the latest news view.
 */
function _inea_preprocess_views_view__latest_news__block(&$variables) {
  $variables['footer'] = l(t("See more news"), "news-events/newsroom");
}

/**
 * Helper function to preprocess CEF project views.
 */
function _inea_preprocess_views_view__cef_energy_countries(&$variables) {
  $term = _inea_generate_view_term($variables['view']);
  $variables['header'] = $term . $variables['header'];
}

/**
 * Helper function to preprocess TEN-T project views.
 */
function _inea_preprocess_views_view__ten_t_projects_by_programme_and_other_tag(&$variables) {
  $term = _inea_generate_view_term($variables['view']);
  $variables['header'] = $term . $variables['header'];
}

/**
 * Helper function to render a term associated with a view.
 */
function _inea_generate_view_term($view) {
  if (is_array($view->args) && count($view->args) > 1) {
    $term_name = end($view->args);
  }
  if (!empty($term_name)) {
    $terms = taxonomy_get_term_by_name($term_name);
    if (!empty($terms)) {
      $term = reset($terms);
      $term_view = taxonomy_term_view($term);
      return render($term_view);
    }
  }
  return '';
}

/**
 * Helper function to generate the view path for a term.
 */
function _inea_generate_term_path($term) {
  $alias = explode("/", drupal_get_path_alias(current_path()));
  $path[] = $alias[0];
  $path[] = $alias[1];
  $vid = $term->vid;
  $vocabulary = taxonomy_vocabulary_load($vid);
  $machine_name = str_replace("_", "-", $vocabulary->machine_name);
  $path[] = 'projects-by-' . $machine_name;
  $path[] = strtolower($term->name);
  return implode("/", $path);
}

/**
 * Implements theme_preprocess_node().
 */
function inea_preprocess_node(&$variables) {
  if ($variables['node']->type == 'news') {
    $creation_date = date("F j, Y", $variables['created']);
    $variables['creation_date'] = '<b>Creation date: </b>' . $creation_date;
  }
}

/**
 * Implements theme_preprocess_node().
 */
function inea_preprocess_field(&$variables, $hook) {
  $element = $variables['element'];
  if ($element['#field_name'] == 'field_project_map' || $element['#field_name'] == 'field_is_map') {
    $variables['items'][0]['#suffix'] = '<p>Click map to view enlarged version<p>';
  }
  if ($element['#field_name'] == 'field_project_summary') {
    $variables['items'][0]['#suffix'] = '<hr>';
  }
}
