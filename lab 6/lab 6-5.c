// First, define an array and ask the user for array size. Then, get the elements of array from user, 
//too. After that, allocate new space in the array and get new elements. Finally, dump the resulting array to 
//scree. (Use dynamic memory allocation.)


#include <stdio.h>
#include <stdlib.h>

int main(){
	int *a,i,s1,s2;
	
	printf("Dizinin boyutunu giriniz : ");
	scanf("%d" ,&s1);
	
	a = (int*)malloc(s1*sizeof(int));
	
	for(i=0; i<s1; i++){
		printf("%d . elemani giriniz : ",i+1);
		scanf("%d" ,a+i);
	}
	
	printf("Dizinin boyutu ne kadar arttirilsin = ");
	scanf("%d" ,&s2);
	printf("Dizinin yeni boyutu : %d\n" ,s1+s2);
	a = (int*)realloc(a,s2*sizeof(int));
	
	for(i=s1; i<s1+s2; i++){
		printf("%d . elemani giriniz : " ,i+1);
		scanf("%d" ,a+i);
	}
	
	for(i=0; i<s1+s2; i++){
		printf("%d . eleman : %d\n" ,i+1,*(a+i));
		
	}
	return 0;
}
