#include <stdio.h>
#include <stdlib.h>

int main(){
	int t,n;
	
	printf("Enter a number :");
	scanf("%d" ,&n);
	
	t = sum(n);
	printf("%d" ,t);

	return 0;
}

int sum(int n){
	int t,a;
	if(n>0){
		a = n % 10;
		n = n / 10;
		return a + sum(n);
	}else{
		return 0;
	}
	
}
