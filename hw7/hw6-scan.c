#include "hw6-scan.h"

int SCAN(FILE *(*stream)){
    int lineCount = 0;
    char check;

    if ((*stream = fopen("hw4.data", "r")) == NULL){
        printf("Its broken brother\n");
        exit(0);
    }
    while ((check = fgetc(*stream)) != EOF){
        if (check == '\n'){
            lineCount++;
        }
    }
    return lineCount;
}