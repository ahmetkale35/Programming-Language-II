// Write a program that reads a string entered from the keyboard and find frequency of characters in this string 
//using dynamic memory management.

#include <stdio.h>
#include <stdlib.h>


int main() {
	
    char*text = NULL;
    int size = 0;
    char ch = 's',c;
    int freq = 0;
    text = (char *)malloc((size+1) * sizeof(char));
    
    printf("Enter a character to find its frequency : ");
    scanf("%c" ,&c);
    getchar();
    
    printf("Enter a string :");
    while(ch){
    	ch = getchar();
    	
    	if(ch == '\0' || ch == '\n')
    		ch = 0;
	
		size++;
		text = realloc(text, (size+1) * sizeof(char));
		if(!text){
			free(text);
			text = NULL;
			break;
		}
    	
    	text[size-1] = ch;
    	if(ch == c)
    		freq++;
    }
	printf("Frequency Of %c in %s is %d," ,c,text,freq);
	free(text);
    return 0;
}

