//Write a program in C to Calculate the length of the string using a pointer

#include <stdio.h>

int main(){
	int i=0;
	char a[100] ="3472fýhh23fhq";
	char *aptr;
	aptr = &a;

	while(aptr[i] != '\0'){
		i++;
	}
	
	printf("length : %d" ,i);

	return 0;
}
