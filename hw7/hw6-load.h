#ifndef HW6_LOAD_H
#define HW6_LOAD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw6-scan.h"

struct _data {
    char *name;
    long number;
};

struct _data *LOAD(FILE *stream, int size);

#endif