//What should be the screen output of code below?

#include <stdio.h>

void main(){
	int c,*b,**a;
	c=4;
	b=&c;
	a=&b;
	
	printf("%d",f(c,b,c));
	
}
int f(int x, int *py, int **ppz){
	**ppz += 1;
	x=*py***ppz;
	*py *= 2;
	x*=*py+3;
	return (x+*py+**ppz);
	
}
/*
a   b   c
4   4   4
25  5   5
325 10  10

=325+10+10
345
*/
