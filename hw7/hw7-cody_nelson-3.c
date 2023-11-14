#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "hw6-main.h"  // Assuming it has necessary type definitions

int main(int argv, char **argc) {
    void *handle;
    int (*SCAN)(FILE **);
    struct _data *(*LOAD)(FILE *, int);
    void (*SEARCH)(struct _data *, char *, int);
    void (*FREE)(struct _data *, int);

    handle = dlopen("hw7-lib-yourname.so", RTLD_LAZY);

    SCAN = (int (*)(FILE **)) dlsym(handle, "SCAN");
    LOAD = (struct _data *(*)(FILE *, int)) dlsym(handle, "LOAD");
    SEARCH = (void (*)(struct _data *, char *, int)) dlsym(handle, "SEARCH");
    FREE = (void (*)(struct _data *, int)) dlsym(handle, "FREE");


    FILE *stream;
    if (argv == 1){
        printf("Must enter a name\n");
    }
    else if (argv == 2){
        int size = SCAN(&stream);
        struct _data *blackBox = LOAD(stream, size);
        SEARCH(blackBox, argc[1], size);
        FREE(blackBox, size);
    }
    else{
        printf("You did something wrong brother\n");
    }

    dlclose(handle);
    return 0;
}