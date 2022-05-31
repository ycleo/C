#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("bool size is: %lu byte\n", sizeof(bool));
    printf("_Bool size is: %lu byte\n", sizeof(_Bool));
    printf("char size is: %lu byte\n", sizeof(char));
    printf("short size is: %lu byte\n", sizeof(short));
    printf("int size is: %lu byte\n", sizeof(int));
    printf("long size is: %lu byte\n", sizeof(long));
    printf("long long size is: %lu byte\n", sizeof(long long));
    printf("float size is: %lu byte\n", sizeof(float));
    printf("double size is: %lu byte\n", sizeof(double));
    printf("long double size is: %lu byte\n", sizeof(long double));

    return 0;
}