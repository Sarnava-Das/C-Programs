#include <stdio.h>

typedef struct {
    double real;
    double imag;
} Complex;


Complex addComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
    return result;
}


Complex subtractComplex(Complex a, Complex b) {
    Complex result;
    result.real = a.real - b.real;
    result.imag = a.imag - b.imag;
    return result;
}

int main() {
    Complex num1, num2, sum, difference;

    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%lf %lf", &num1.real, &num1.imag);

    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%lf %lf", &num2.real, &num2.imag);

   
    sum = addComplex(num1, num2);
    difference = subtractComplex(num1, num2);

    printf("\nComplex Number 1: %.2lf + %.2lfi\n", num1.real, num1.imag);
    printf("Complex Number 2: %.2lf + %.2lfi\n", num2.real, num2.imag);

    printf("Sum: %.2lf + %.2lfi\n", sum.real, sum.imag);
    printf("Difference: %.2lf + %.2lfi\n", difference.real, difference.imag);

    return 0;
}
