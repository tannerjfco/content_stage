<?php

/*
 * Migration for Basic page content type
 */

class StageBasicPageMigration extends Migration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		// Tell Migration what source id field to use for tracking source/destination relationship
		$this->map = new MigrateSQLMap($this->machineName, array(
				'nid' => array(
					'type' => 'varchar',
					'length' => 255,
					'not null' => TRUE,
				),
			), MigrateDestinationNode::getKeySchema()
		);

		// Tell Migration our source. For content staging we're importing from CSVs
		$this->source = new MigrateSourceCSV(drupal_get_path('module', 'content_stage') . '/import/node_page.csv', array(), array('header_rows' => 1));

		// Now we define our destination. For this we're using the node destination and specifying the node type we're importing to.
		$this->destination = new MigrateDestinationNode('page');

		// Onto Field Mappings. This tells migrate what csv fields should be imported to which drupal fields.

		// Our source and destination field names are the same, so for most cases we can use addSimpleMappings()
		$this->addSimpleMappings(array('nid', 'title', 'path', 'body', 'created', 'changed'));

		// For these fields we'll set default values to be imported without a source field specified.
		$this->addFieldMapping('uid')
			 ->defaultValue(1);
		$this->addFieldMapping('is_new')
			 ->defaultValue(TRUE);
		$this->addFieldMapping('body:format')
			 ->defaultValue('full_html');

	}
}

/*
 * Migration for Article content type
 * We extend from the Basic page migration so as not to repeat ourselves
 */

class StageArticleMigration extends StageBasicPageMigration {
	public function __construct($arguments) {
		parent::__construct($arguments);

		// We're using the same id mapping as before so we can skip it here.

		// Source
		$this->source = new MigrateSourceCSV(drupal_get_path('module', 'content_stage') . '/import/node_article.csv', array(), array('header_rows' => 1));

		//Destination
		$this->destination = new MigrateDestinationNode('article');

		// Field Mappings

		/* You can unset mappings from a parent migration. In the Basic page migration 
		 * we mapped the 'nid' field, so nid 1 in source gets nid 1 in destination.
		 * This is useful when you have content you want a static Node ID for. For our 
		 * articles however, we're not concerned what Node ID they get so we'll unmap it.
		 */
		$this->removeFieldMapping('nid');

		// Use separator to handle fields with multiple values and separate your source content values accordingly
		$this->addFieldMapping('field_tags', 'field_tags')
			 ->separator(',')
			 ->sourceMigration('StageTag');

		// Many fields like files/images have "subfields" in the format of "field_name:subfield" used for metadata or migration settings.
		$this->addFieldMapping('field_image', 'field_image');
		$this->addFieldMapping('field_image:source_dir')
			 ->defaultValue(drupal_get_path('module', 'content_stage') . '/import/');
		$this->addFieldMapping('field_image:destination_dir')
			 ->defaultValue('public://images');


	}
}