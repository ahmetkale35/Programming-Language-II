//Write a program in C to compute the sum of all elements in an array
//using pointers.

#include <stdio.h>

int main() {
    int a[] = {1, 2, 3, 4, 5},i;
    int *aptr = &a; 
    int sum = 0;
   
    
    for (i = 0; i < 5; i++) {
        sum += *(aptr + i); 
    }
    
    printf("Sum : %d", sum);
    
    return 0;
}

