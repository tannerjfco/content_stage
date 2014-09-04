# Drupal Content Staging Migration #
This module is a migration to be used with [Migrate](https://www.drupal.org/project/migrate). The goal is to provide a simple starting point to use for staging content during the development process, while also providing a simple use case as an introduction for people new to using the Migrate module.

Utilizing this approach for gathering and staging content during development for a site allows you and your clients to work on building out content as soon as your content structure is defined. Since the migration source is a simple CSV, this allows for utilizing services like [Google Docs/Drive](http://drive.google.com) to provide a centralized collaborative point for building content.

## Current Scope / Status ##

This migration is an example that can be run against a Drupal 7 Standard Install. It can be used as a starting point for your own migrations by either creating your own module & classes that extend off of content_stage (preferred), or you can jump right in and suit it to your needs.

I've attempted to document the migration code as best as possible so it's easy to understand and jump in. It also shows a few scenarious such as fields with multiple values, subfields, and default values that should serve as good examples when needed to expand upon for other fields.

Future updates may be added to address more contrib fields, entities etc in a submodule that could be optionally enabled or reviewed for examples.

## Feedback ##

This is a first stab at creating a migration for content staging that could be generally useful to anybody to use as a starting point. Feedback is welcomed and appreciated.

## Note on Sample Content ##

Sample content is either created by me or used from Wikinews under Creative Commons and is attributed as applicable. If any content happens to not be properly attributed, please let me know and I will correct as necessary.