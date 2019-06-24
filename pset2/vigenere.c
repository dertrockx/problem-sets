#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_TEXT_SIZE 256

void vigenere(char text[], char key[], int textSize, int keySize){
	printf("Before hashed: %s with key %s\n", text, key);
	int i = 0, j=0;
	while(i < textSize){
		if (isalpha(text[i])){
			if(j == keySize){
				j = 0;
			}
			//printf("Cyphering char %c with key %c\n", text[i], key[j]);
			text[i] = text[i] + (key[j] - 97);
			if(text[i] > 122){
				text[i] -= 26;
			}
			j++;
		}
		i++;
		
	}
	printf("After hashed: %s\n", text);
}
int main(int argc, char* argv[]){
	char *text = malloc(MAX_TEXT_SIZE);
	char *key = malloc(MAX_TEXT_SIZE);
	if (text == NULL){
		printf("No memory\n");
		return 1;
	}
	key = argv[1];
	printf("Text to hash ");
	fgets(text, MAX_TEXT_SIZE, stdin);

	printf("\nHashing...\n");
	printf("%s\n", text);
	vigenere(text, key, strlen(text), strlen(key));
	return 0;
}

