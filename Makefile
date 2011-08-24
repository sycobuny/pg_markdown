# contrib/pg_markdown/Makefile

MODULE_big = pg_markdown
OBJS = pg_markdown.o

EXTENSION = pg_markdown
DATA = pg_markdown--0.1.sql pg_markdown--unpackaged--0.1.sql

REGRESS = pg_markdown

SHLIB_LINK += $(filter -lmarkdown, $(LIBS))

ifdef USE_PGXS
PG_CONFIG = pg_config
PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)
else
subdir = contrib/pg_markdown
top_builddir = ../..
include $(top_builddir)/src/Makefile.global
include $(top_srcdir)/contrib/contrib-global.mk
endif
