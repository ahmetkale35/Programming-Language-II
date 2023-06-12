//Write C program to add two Complex Numbers by passing structure to a function. (In this example, you 
//should take two complex numbers as structures and add them by creating a user-defined function.

#include <stdio.h>


typedef struct {
    float real;
    float imaginary;
} Complex;


Complex addComplex(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

int main() {
    Complex num1, num2, sum;

    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imaginary);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imaginary);

    
    sum = addComplex(num1, num2);
    printf("Sum = %.2f + %.2fi\n", sum.real, sum.imaginary);

    return 0;
}

