//Cody Nelson 330
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct _data {                                 
   char *name;
   long number;
};

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

struct _data *LOAD(FILE *stream, int size){
    rewind(stream);
    size_t charCount;
    struct _data *blackBox = (struct _data *)calloc(size, sizeof(struct _data));
    char *text, *phoneNum, *name;
    int x = 0; 
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

void SEARCH(struct _data *BlackBox, char *name, int size){
    for (int i = 0; i < size; i++){
        if (strcmp(BlackBox[i].name, name) == 0){
            printf("The name was found at the %d entry.\n", i);
            return;
        }   
    }
    printf("The name was NOT found.\n");
}

void FREE(struct _data *blackBox, int size){
    for(int i = 0; i < size; i++){
        free(blackBox[i].name);
    }
    free(blackBox);
    blackBox = NULL;
}

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