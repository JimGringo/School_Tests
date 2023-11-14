#include "hw6-free.h"

void FREE(struct _data *blackBox, int size){
    for(int i = 0; i < size; i++){
        free(blackBox[i].name);
    }
    free(blackBox);
    blackBox = NULL;
}