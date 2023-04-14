//Write a program in C to store n elements in an array and print the
//elements using pointer


#include <stdio.h>
int main(){
	int a[10] = {1,2,3,4,5,6,7,8,9,10},i;
	int *aptr;
	aptr = &a;
	
	for(i=0; i<10; i++){
		printf("%d\n" ,*aptr);
		aptr++;
	}
	
	return 0;
}
