/* postgres includes */

#include "postgres.h"
#include "executor/spi.h"
#include "fmgr.h"
#include "funcapi.h"
#include "lib/stringinfo.h"
#include "miscadmin.h"
#include "utils/builtins.h"

/* markdown includes */

#include <stdio.h>
#include <string.h>
#include <mkdio.h>

/* set up our code as a PG module and declare function(s) */
PG_MODULE_MAGIC;
Datum to_html(PG_FUNCTION_ARGS);

PG_FUNCTION_INFO_V1(to_html);
Datum
to_html(PG_FUNCTION_ARGS)
{
    text      *text_arg = PG_GETARG_TEXT_P(0);
    char      *char_arg = text_to_cstring(text_arg);

    MMIOT     *doc       = NULL;
    char      *char_out  = NULL;
    text      *text_out  = NULL;
    int       outputsize;

    doc = mkd_string(char_arg, strlen(char_arg), 0);

    if (mkd_compile(doc, 0))
    {
        outputsize = mkd_document(doc, &char_out);

        if (outputsize != EOF)
            text_out = cstring_to_text(char_out);
        else
            PG_RETURN_NULL();
    }
    mkd_cleanup(doc);

    PG_RETURN_TEXT_P(text_out);
}
