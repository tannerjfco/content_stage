<?php

/*
 * Migration for taxonomy terms into "Tags" vocabulary
 */

class StageTagMigration extends Migration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		// Source id mapping
		$this->map = new MigrateSQLMap($this->machineName, array(
				'tid' => array(
					'type' => 'varchar',
					'length' => 255,
					'not null' => TRUE,
				),
			), MigrateDestinationTerm::getKeySchema()
		);

		// Source
		$this->source = new MigrateSourceCSV(drupal_get_path('module', 'content_stage') . '/import/term_tags.csv', array(), array('header_rows' => 1));

		// Destination
		$this->destination = new MigrateDestinationTerm('tags');

		// Field Mappings
		$this->addSimpleMappings(array('name', 'description'));
	}
}