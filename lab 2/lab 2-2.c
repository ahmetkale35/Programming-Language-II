#include <stdio.h>
#include <stdlib.h>
int n;

int main(){
	int a[100],n,m,i,j;
	printf("Kac sayi gireceksiniz :");
	scanf("%d" ,&n);
	
	for(i=0; i<n; i++){
		printf("%d . sayiyi girniz :",i+1);
		scanf("%d", &a[i]);
	}
	e = max(a);
	printf("%d" ,m);

	return 0;
}

int max(int a[]){
static int i=0, e=-9999;
	if(i<n){
		if(a[i]>e){
			e = a[i];
			i++;
			max(a);
		}	
	}
	return e;
	
	
	
}
