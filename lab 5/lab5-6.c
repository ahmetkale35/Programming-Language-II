//Write a program in C to print a string in reverse using a pointer.


#include <stdio.h>
#include <string.h>

int main() {
    char str[100], *p;
    int l;

    printf("Enter a string: ");
    scanf("%s", str);
	p = str;
	l = strlen(str) - 1;
	 while(l>=0){
	 	printf("%c" ,p[l]);
	 	l--;
	 }

    return 0;
}

