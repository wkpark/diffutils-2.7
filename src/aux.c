/* GNU DIFF exit routine. */
#include "diff.h"

#if HAVE_VPRINTF || HAVE_DOPRNT || _LIBC
# if __STDC__
#  include <stdarg.h>
#  define VA_START(args, lastarg) va_start(args, lastarg)
# else
#  include <varargs.h>
#  define VA_START(args, lastarg) va_start(args)
# endif
#else
# define va_alist a1, a2, a3, a4, a5, a6, a7, a8
# define va_dcl char *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
#endif

#if STDC_HEADERS || _LIBC
# include <stdlib.h>
# include <string.h>
#else
void exit ();
#endif

void
diff_exit(status)
    int status;
{
  exit(status);
}

void
#if defined(VA_START) && __STDC__
diff_printf (const char *message, ...)
#else
diff_printf (message, va_alist)
     char *message;
     va_dcl
#endif
{
#ifdef VA_START
  va_list args;
#endif

#ifdef VA_START
  VA_START (args, message);
# if HAVE_VPRINTF || _LIBC
  vfprintf (outfile, message, args);
# else
  _doprnt (message, args, stderr);
# endif
  va_end (args);
#else
  fprintf (outfile, message, a1, a2, a3, a4, a5, a6, a7, a8);
#endif
}

void
diff_puts (str)
    const char *str;
{
  fputs(str, outfile);
}
