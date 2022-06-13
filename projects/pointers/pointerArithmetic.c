#include <stdio.h>

int strLength(const char *str);

int main() {
    const char str[] = "Nice";
    printf("The length of the string is %d\n", strLength(str));
    printf("The length of the string is %d\n", strLength(" "));
    printf("The length of the string is %d\n", strLength("Hello"));  

    return 0;
}

int strLength(const char *str) {
    int len;
    const char *strEnd = str;

    while(*strEnd) 
       strEnd++;

    len = strEnd - str;
    return len;
}