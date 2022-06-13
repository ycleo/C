#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // declare variables
    char *pStr = NULL;
    int strLimit = 0;

    // input the string size limit
    printf("\nEnter the string size limit: ");
    scanf("%d", &strLimit);

    // allocate memory space
    pStr = (char *)calloc(strLimit + 1, sizeof(char));  // pStr = (char *)malloc((strLimit + 1) * sizeof(char));
    printf("string has been zero-initialized: %s\n\n\n", pStr);
    
    // check memory allocation succeeded or not
    if(pStr == NULL) {
        printf("Memory allocation failed...\n");
        exit(1);
    }

    // type in string and print out the result
    printf("Enter the string content: ");
    scanf(" ");
    if (fgets(pStr, strLimit + 1, stdin) != NULL)
        printf("\nFinal String Result: %s\n", pStr);
    
    // deallocate memory
    free(pStr);
    pStr = NULL;

    return 0;
}