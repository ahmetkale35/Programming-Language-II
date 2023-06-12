//Write a program that searches for the given string in the given sentence and if the word is found then prints the 
//starting index of the places of this word to the screen

#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	char w[20];
	int v=0,i=0,len;
	int static j=0;
	int t=0;
	int indis=0;
	
	printf("Enter the string : ");
	gets(s);
	printf("Enter the word : ");
	gets(w);
	len = strlen(w);
	
	while(s[i] != '\0'){
	
		if(s[i] == w[j] && s[i] != ' '){
			i++;
			j++;
			v++;
			indis = i;
			if(v == len && s[i] == ' ' || s[i] == '\0'){
				printf("The word you are looking for exists in a sentence \n");
				t++;
				printf("starting index : %d" ,indis-len);
				i++;
				}
		}	else{
			i++;
			if(s[i] == '\0' && t == 0){
				printf("The word you are looking for is not in the sentence");
				return 0;
			}
				
		}

	}
	
	return 0;
}
