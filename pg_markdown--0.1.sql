/* contrib/pg_markdown/pg_markdown--0.1.sql */

--SQL for Markdown parser

CREATE
  FUNCTION to_html(TEXT)
  RETURNS TEXT
  AS '$libdir/pg_markdown'
  LANGUAGE INTERNAL
  STRICT
  STABLE;
