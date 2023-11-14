#include "hw6-main.h"

int main(int argv, char **argc){
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
    
}