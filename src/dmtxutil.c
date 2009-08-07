#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <assert.h>
#include <dmtx.h>
#include "dmtxutil.h"

extern char *program_name;

extern void
fatal_error(int errorCode, char *fmt, ...)
{
   va_list va;

   va_start(va, fmt);
   fprintf(stderr, "%s: ", program_name);
   vfprintf(stderr, fmt, va);
   va_end(va);
   fprintf(stderr, "\n\n");
   fflush(stderr);

   exit(errorCode);
}

/* TODO: What this function does? */
extern DmtxPassFail
string_to_int(int *numberInt, const char *number_string, char **terminate)
{
   long number_long;

   if (!isdigit(*number_string)) {
      *numberInt = DmtxUndefined;
      return DmtxFail;
   }

   /* FIXME: it is wrong use errno */
   errno = 0;
   number_long = strtol(number_string, terminate, 10);

   while (isspace((int)**terminate))
      (*terminate)++;

   if (errno != 0 || (**terminate != '\0' && **terminate != '%')) {
      *numberInt = DmtxUndefined;
      return DmtxFail;
   }

   *numberInt = (int)number_long;

   return DmtxPass;
}

/* TODO: Check if there is a glib function to replace basename function */
extern char *
basename(char *path)
{
   assert(path);

   if (strrchr(path, '/'))
      path = strrchr(path, '/') + 1;

   if (strrchr(path, '\\'))
      path = strrchr(path, '\\') + 1;

   return path;
}
