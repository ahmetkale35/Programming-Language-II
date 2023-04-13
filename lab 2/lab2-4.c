#include <stdio.h>
#include <stdlib.h>

int main (){
	int n1,n2,result;
	printf(" enter first number :\n");
	scanf("%d\n" ,&n1);
	
	printf("enter second number :\n");
	scanf("%d\n" ,&n2);
	
	result = lcd(n1,n2);
	printf("Result : %d" ,result);
	
	return 0;
}

	lcd(int a,int b){
		if(b==0){
			return a;
		}else{
			return lcd(a,a%b);
		}
		
	}
