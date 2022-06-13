#include <stdio.h>
#include <stdlib.h>

void square(double *numPtr);
// 1. square(const double *numPtr): 
// Valid to set the dereference value to be constant, 
// but is not the function intend to do

// 2. square(double *const numPtr):
// Valid to set the address of the pointer to be constant, 
// but is redundant since "pass by reference" is a process of copying the address

int main() {
    double *num = (double *)malloc(sizeof(double));
    
    if(num) {
        *num = 8.8;
        printf("The square of %.3f is ", *num);
        square(num);
        printf("%.3f\n", *num);
    } else if (num == NULL) {
        printf("Memory allocation failed ...\n");
        exit(1);
    }

    return 0;
}

void square(double *numPtr) {
    *numPtr = (*numPtr) * (*numPtr);
    return;
}