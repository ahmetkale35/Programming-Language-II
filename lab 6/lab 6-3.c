//First, allocate the minimum memory space required for your name with malloc. Then expand this memory 
//area with realloc to include your last name.

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char *a;
	
	a = (char*)malloc(5*sizeof(char));
	strcpy(a,"Ahmet");
	printf("%s\n" ,a);
	
	a = (char*)realloc(a,10*sizeof(char));
	
	strcpy(a,"Ahmet Kale");
	
	printf("%s\n" ,a);
	
	free(a);
	
	return 0;
}
