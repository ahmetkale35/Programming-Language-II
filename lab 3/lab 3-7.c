//What does the following function print for n=25?

#include<stdio.h>

void fun(int n){
	if( n == 0 )
		return;
	fun(n / 2);
	printf("%d", n % 2);
}
void main(){
	fun(25);
	
}

//11001
