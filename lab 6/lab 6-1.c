/*By taking the total number of elements from the user, take the necessary place by using the calloc function 
from memory. The number of elements in this memory area you allocate is taken from the user. Then find 
the largest value entered using the pointer variable you have defined and print it on the screen.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int es,i,max;
	int *aptr;
	printf("Enter number of elements :");
	scanf("%d" ,&es);
	
	aptr = (int*)calloc(es,sizeof(int));
	if(aptr == NULL){
		printf("No memory left ");
		exit(0);
	}
	
	for(i=0; i<es; i++){
		printf("%d. sayi :" ,i+1);
		scanf("%d" ,aptr+i);
	}

	for(i=0; i<es; i++){
		if(aptr+i>aptr){
			max=i;
		}
	}
	
	printf("%d" ,*(aptr+max));
	free(aptr);
	return 0;
}
