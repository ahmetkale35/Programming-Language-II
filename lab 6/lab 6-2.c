/*Allocate the minimum char memory space required for your name and surname using the malloc function. 
Then use the strcpy function to write your name and surname with spaces to this variable.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char *a;
	a = (char*)malloc(10*sizeof(char));
	
	if(a == NULL)
		printf("Hafýzada yer ayrilmadi");
	else
		strcpy(a,"Ahmet Kale");
		
	printf("Dinamik olarak ayrilan alan :%s",a);
	
	free(a);
	
	return 0;
}
