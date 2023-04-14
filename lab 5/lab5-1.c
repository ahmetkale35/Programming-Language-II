//Write a program in C to add two numbers using pointers.

#include <stdio.h>
int main()
{
 int a=5 , b=6;
 int *aptr;
 int *bptr;
 aptr = &a;
 bptr = &b;
 printf("%d" ,(*bptr + *aptr));
 return 0;
}

