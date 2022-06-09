#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define ROW 25
#define COL 50

int strLength(const char str[]);
void strCat(char result[], const char str1[], const char str2[]);
bool strComp(const char str1[], const char str2[]);
void strReverse(char str[]);
void strBubbleSort(int strNum, char strs[][COL]);

int main() {
    // declare variables
    char result[50];
    char str1[] = "I like to swim";
    char str2[] = "I like to swim";
    char strToReverse[50];
    
    int strNum;
    char strsToSort[ROW][COL];

    // calculate the length of strings
    printf("Calculate the length of two strings\n");
    printf("---------------------------------------------\n");
    printf("The length of str1 is %d\n", strLength(str1));
    printf("The length of str2 is %d\n\n\n", strLength(str2));

    // concatenate two strings
    printf("Concatenate str2 to str1\n");
    printf("---------------------------------------------\n");
    strCat(result, str1, str2);
    printf("%s\n\n\n", result);

    // compare two strings
    printf("Compare str1 and str2\n");
    printf("---------------------------------------------\n");
    if (strComp(str1, str2)) 
        printf("str1 and str2 are the same.\n\n\n");
    else    
        printf("str1 and str2 are not the same.\n\n\n");

    // Reverse a string
    printf("Reverse a string\n");
    printf("---------------------------------------------\n");
    printf("Type a word to reverse: ");
    scanf("%s", strToReverse);
    strReverse(strToReverse);
    printf("%s\n\n\n", strToReverse);

    // Bubble Sort an array of string
    printf("Bubble Sort an array of string\n");
    printf("---------------------------------------------\n");
    printf("Input number of strings: ");
    scanf("%d", &strNum);
    printf("Input your strings:\n");
    for(int i = 0; i < strNum; i++) {
        scanf("%s", strsToSort[i]);
    }

    strBubbleSort(strNum, strsToSort);

    printf("\nAfter Sorting: \n");
    for(int i = 0; i < strNum; i++) {
        printf("%s\n", strsToSort[i]);
    }

    return 0;
}

int strLength(const char str[]) {
    int length = 0;
    while(str[length] != '\0') 
        length++;
    return length;
}

void strCat(char result[], const char str1[], const char str2[]) {
    int i, j;
    for (i = 0; str1[i] != '\0'; i++) 
        result[i] = str1[i];
    
    for (j = 0; str2[j] != '\0'; j++, i++)
        result[i] = str2[j];

    result[i] = '\0';
}

bool strComp(const char str1[], const char str2[]) {
    bool result = true;
    
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
        i++;

    if (str1[i] != '\0' || str2[i] != '\0')
        result = false;
    
    return result;
}

void strReverse(char str[]) {
    int strLength = strlen(str);
    char strRev[strLength + 1];
    int i;
    for(i = 0; i < strLength; i++) {
        strRev[i] = str[strLength - 1 - i];
    }
    strRev[i] = '\0';

    printf("sizeof(str) = %lu\n", sizeof(str)); // size of a pointer
    printf("strlen(str) = %lu\n", strlen(str)); // expected length
    // why: 
    // 1. https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/
    // 2. https://www.cplusplus.com/forum/general/19458/

    strncpy(str, strRev, strLength);
}

void strBubbleSort(int strNum, char strs[][COL]) {
    char temp[COL];
    for(int i = 1; i <= strNum - 1; i++) {
        for(int j = 0; j <= strNum - i - 1; j++) {
            if(strcmp(strs[j], strs[j + 1]) > 0){
                strncpy(temp, strs[j], sizeof(temp) - 1);
                strncpy(strs[j], strs[j + 1], sizeof(strs[j]) - 1);
                strncpy(strs[j + 1], temp, sizeof(strs[j + 1]) - 1);
            }
        }
    }
}