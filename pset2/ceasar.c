#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ceasar(char text[], int size, int base);

void main(int argc, char *argv[]){
    int base = atoi(argv[1]);
    /*
    char text[20], newText[20];

    printf("plaintext: ");
    */
    char source[1000];

    printf("plaintext: \n");
    scanf("%s", source);
    ceasar(source, strlen(source), base);

    
};

void ceasar(char text[], int size, int base){
    char newText[size];
    for(int i = 0; i < size; i++){
        newText[i] = text[i] + base;
    };
    printf("%s\n", newText);
};