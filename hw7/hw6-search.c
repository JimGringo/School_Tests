#include "hw6-search.h"

void SEARCH(struct _data *BlackBox, char *name, int size){
    for (int i = 0; i < size; i++){
        if (strcmp(BlackBox[i].name, name) == 0){
            printf("The name was found at the %d entry.\n", i);
            return;
        }   
    }
    printf("The name was NOT found.\n");
}