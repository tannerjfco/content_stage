<?php

/*
 * Implements hook_migrate_api()
 *
 * Register your migration classes here so Migrate is aware of them and can use them.
 * In the 'migrations' array, you'll define the name of the migration shown in Migrate UI
 * /drush, and tie it to the name of your migration class. You can also define dependencies here to ensure certain migrations run before others.
 *
 */
function content_stage_migrate_api() {
	$api = array(
		'api' => 2,
		'groups' => array(
			'content_stage' => array(
				'title' => t('Content Staging'),
			),
		),
		'migrations' => array(
			'StageTag' => array(
				'class_name' => 'StageTagMigration',
				'group_name' => 'content_stage'
			),
			'StageBasicPage' => array(
				'class_name' => 'StageBasicPageMigration',
				'group_name' => 'content_stage'
			),
			'StageArticle' => array(
				'class_name' => 'StageArticleMigration',
				'group_name' => 'content_stage',
				'dependencies' => array(
					'StageTag',
					'StageBasicPage',
				),
			),
		),
	);
	return $api;
}