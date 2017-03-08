#include "stdarg.h"

void print(char *msg,...)
{
    va_list argp;

    va_start(argp,msg);
    vfprintf(stderr, msg, argp);
    va_end(argp);

}
