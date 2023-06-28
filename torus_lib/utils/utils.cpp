#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "utils.h"

void throw_error(char* msg)
{
    fprintf(stderr, "<Error> %s: '%s'", strerror(errno));
    exit(1);
}