#include "hw6-load.h"

struct _data *LOAD(FILE *stream, int size){
    rewind(stream);
    size_t charCount;
    struct _data *blackBox = (struct _data *)calloc(size, sizeof(struct _data));
    char *text, *phoneNum, *name;
    for(int i = 0; i < size; i++) {
        text = NULL;
        getline(&text, &charCount, stream);
        name = strtok(text, " ");
        phoneNum = strtok(NULL, "\n");
        if ((blackBox[i].name = (char*)calloc(strlen(name) + 1, sizeof(char))) == NULL){
            printf("Error allocating memory\n");
            exit(0);
        }
        strcpy(blackBox[i].name, name);
        blackBox[i].number = atol(phoneNum);
        free(text);
    }
    fclose(stream);
    return blackBox;
}