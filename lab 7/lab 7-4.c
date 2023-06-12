//Write the C program using dynamic memory, which counts the words in a given text or sentence

#include <stdio.h>
#include <stdlib.h>


int main(){
	
	char *text;
	char ch;
	int words,size=0;
	
	text = (char *)malloc((size+1) * sizeof(char));
	
	printf("Enter a string : ");
	
	while((text[size] = getchar()) != '\n'){
	
		size++;
		text = realloc(text, (size+2) *sizeof(char));
		if(!text){
			free(text);
			text = NULL;
			break;
		}
		if(text[size-1] == ' ' || (text[size] == '\0' && text[size+1] != '\0')){
			words++;
		}
			
	}
	text[size] == '\0';
	printf("Number of word :%d" ,words);
	free(text);
	return 0;
}
