api = 2
core = 7.x

; ===================
; Contributed modules
; ===================

defaults[projects][subdir] = contributed

projects[block_class][version] = 2.1
projects[hierarchical_select][version] = 3.0-beta1
projects[menu_trail_by_path][version] = 2.0
projects[pathologic][version] = 2.12

; For Media Browser Plus
projects[views_tree][subdir] = "contrib"
projects[views_tree][version] = 2.0
 
projects[media_browser_plus][subdir] = "contrib"
projects[media_browser_plus][version] = 3.0-beta4
projects[media_browser_plus][patch][] = "https://www.drupal.org/files/issues/download-files-in-media-basket-does-not-work-2821063-2.patch"
 
projects[multiform][subdir] = "contrib"
projects[multiform][version] = 1.1

