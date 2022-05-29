#include <stdio.h>
int main(int argc, char *argv[]) 
{
    printf("Hello, World!\n");

    int numOfArgs = argc;
    char *arg1 = argv[0];
    char *arg2 = argv[1];
    
    printf("Number of Arguments: %d\n", numOfArgs);
    printf("Argument 1 is the program name: %s\n", arg1);
    printf("Argument 2 is the command line argument: %s\n", arg2);

    return 0;
}
