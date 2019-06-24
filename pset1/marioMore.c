#include <stdio.h>
#include <stdlib.h>
#define MAX 256
const char * generateSpaces(int n){
	char *spaces = malloc(MAX);
	int i = 0;
	while (i < n){
		spaces[i] = ' ';
		i++;
	}
	return spaces;
}

const char * generateHashtag(int n){
	char *hashes = malloc(MAX);
	int i = 0;
	while (i < n){
		hashes[i] = '#';
		i++;
	}
	return hashes;	
}

void startGenerator(int height){
	int hashes = 1;
	int spaces = height - hashes;
	while (hashes <= height){
		printf("%s%s %s%s\n", generateSpaces(spaces), generateHashtag(hashes), generateHashtag(hashes), generateSpaces(spaces) );
		hashes++;
		spaces--;
	}
}

void main(int argc, char* argv[]){
	int height;
	height = atoi(argv[1]);

	startGenerator(height);

}