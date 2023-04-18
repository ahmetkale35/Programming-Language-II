// Write a recursive function that takes 
//the address of the array and the number of elements as a parameter and returns the number of odd numbers in 
//the array. (Do not use global variable)

#include <stdio.h> 
int oddcounter(int a[],int s){
	if(s == 0){
		return 0;
	}
	int c = oddcounter(a,s-1);
	if(a[s-1] % 2 == 1){
		c++;
	}
	
	return c;
	}
	
int main(){
int a[] = {2,1,7,9,11,13,32,42,55,441,221};
int s = sizeof(a)/4;
int counter = 0;
counter = oddcounter(a,s);
printf("Count of odds :%d" ,counter);	
	
	return 0;
}
