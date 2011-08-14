PGMarkdown - A PostgreSQL extension defining a Markdown datatype.
================================================================================

## Summary ##

PGMarkdown implements the conversion of Markdown into HTML inside the database.

The code is Copyright (c) 2011 Stephen Belcher, but is licensed under similar
terms as PostgreSQL. Please see the LICENSE file for more details.

## Usage ##

    CREATE TABLE blog_posts (
      id SERIAL PRIMARY KEY,
      post MARKDOWN
    );

    INSERT INTO blog_posts (post)
    VALUES ($$POST$$
    ## Welcome ##
    Welcome to my fancy blog. It has [links]][] and **fancy** emphasis, all with
    plain text. See what someone who is me says about this web site in the handy
    block quote:

    > This blog is frankly amazing.

    [links]: /
    $$POST$$);

    SELECT to_html(post) FROM blog_posts WHERE id = 1;

## Datatypes ##

* MARKDOWN

## Functions ##

* TO_HTML(MARKDOWN) RETURNS TEXT
* TO_TEXT(MARKDOWN) RETURNS TEXT
