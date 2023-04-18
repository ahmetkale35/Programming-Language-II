//Write screen output, when fun is called in main function with n=0, a=5 and b=7.


#include<stdio.h>
void fun(int,int,int);
int main(){
	
	fun(0,5,7);
	
	return 0;
}
void fun(int n, int a, int b){
	
	if( n >= 10 )
		return;
		
	fun(n + 2,a,b+n);
	printf("%d %d %d\n", n, a, b);
}



/*
	8 5 19
	6 5 13
	4 5 9
	2 5 7
	0 5 7
*/
