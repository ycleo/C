#include <stdio.h>

int main() {
    int *pNum = NULL; // int *pNum = 0;
    int num = 10;

    // print out &pNum, pNum
    printf("- The address of the pointer (&pNum): %p\n", (void*)&pNum);
    printf("- The value of the pointer, or the address that the pointer points to (pNum): %p\n", pNum);
    // printf("- *pNum = %d\n", *pNum);  -> segmentation fault
    printf("\n\n");

    // check if the pointer is pointing to NULL(0)
    if (!pNum) {  
        pNum = &num;
        // print out &pNum, pNum, *pNum, &num, num
        printf("- The address of the pointer (&pNum): %p\n", (void*)&pNum);
        printf("- The value of the pointer, or the address that the pointer points to (pNum): %p\n", pNum);
        printf("- The dereference value of the pointer (*pNum): %d\n", *pNum);
        printf("\n\n");

        printf("- The address of the integer data (&num): %p\n", (void*)&num);
        printf("- The value of the integer data (num): %d\n", num);
    }

    return 0;
}