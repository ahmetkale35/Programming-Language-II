//The program code that identifies whether two string entered from the keyboard are the same or not, and which 
//one is longer as a word


#include <stdio.h>
#include <string.h>
int main(){
	int len1,len2,i=0;
	char f[20];
	char s[20];
	printf("Enter the first word : ");
	gets(f);
	printf("Enter the second word : ");
	gets(s);
	len1 = strlen(f);
	len2 = strlen(s);
	
	if (strlen(f) == strlen(s)){
		while(f[i] != '\0'){
			if (f[i] == s[i]){
			i++;
			}
		}
		printf("Both words are the same");
	}else{
		if (len1 > len2){
		printf("First Word Longer");
	}	else{
		printf("Second word Longer");
		}
	}
	return 0;
}
