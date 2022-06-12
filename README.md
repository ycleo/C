# C
## Basic Concepts
- [Compilation process](https://www.javatpoint.com/compilation-process-in-c)
- [Using Clang in VS Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)
- Preprocessor
    - Preprocessor statements are identified by the ==pound sign(#)==
    - 1st challenge used a preprocessor directive, specifically **#include** 
    - Create constants and macros by **#def**
    - Conditional statements: **#ifdef**, **#endif**, **#else**, **#ifndef**

## Variables and Data Types
### Memory
- A program needs to stroe the instructions of its program and the data that is acts upon while your computer is executing that program.
    - This information is stored in memory
    - **RAM** (Random Access Memory) contents are lost when the computer is turned off
    - **Hard drives** store persistent data
- bits in memory are grouped into sets of **eight** -> called **byte**
- each byte has been labeled with a number -> called **address**
### Naming Rules
1. Must begin with a letter or underscore ( _ )
2. Can only contain letters, underscore, and digits 0~9
```c=
/* 
 * Invalid variable names
 */

temp$value // $ in not a valid character
my flag    // spaces are not permitted
6cool      // cannot start with a number
int        // int is a reserved key word
```
### Data Types
- Declaration: specifies to the compiler how a particular variable will be used by the program. 
```c=
int name;
// int is type specifier or data type
// name is identifier or variable name
```
- It is best to avoid putting initialized and noninitialized variables in the same declaration statement
```c=
int x = 1;
int y = 2, z = 5;
int p, k = 6; // valid, but poor form
```
- The difference between the types are [size](https://docs.oracle.com/cd/E18752_01/html/817-6223/chp-typeopexpr-2.html) and [range](https://byjus.com/gate/size-of-data-types-in-c/)
- a **long** integer might take up **32-bit** or **64-bit** in different computers
- [Boolean in C](https://www.educative.io/edpresso/what-is-boolean-in-c)
```c=
#include <stdio.h>
#include <stdbool.h>

// Basic data types

short        // 2 byte
int          // 4 byte
long         // 4 or 8 byte
long long    // 8 byte
    
float        // 4 byte
double       // 8 byte
long double  // 16 byte
    
char         // 1 byte
bool   
```
- float expression:
```c=
float f1 = 12.5, f2 = 3., f3 = -.0001;
float f4 = 1.7e-5; 
// 1.7*(10^(-5)) -> scientific notation
```
- All floating-point constants are taken as **double** values by the C compiler
- To explicitly express a float instead of a double -> **append f or F** to the end
```c=
#include <stdio.h>

int main() {
    printf("%d-byte\n", sizeof(1.2e5F)); // 4-byte (float)
    printf("%d-byte\n", sizeof(1.2e5));  // 8-byte (double)
    
    return 0;
}
```
- Key adjective: **short**, **long**, **unsigned**, **signed**
- Enums:
```c=
#include <stdio.h>

int main() {
    enum day { mon, tue, wed = 5, thu, fri, sat, sun };
    enum day workDay = mon; 
    
    // The compiler treats enumeration identifiers as integer constants
    printf("%d ", workDay); // 0
    
    workDay = tue;
    printf("%d ", workDay); // 1
    
    workDay = wed;
    printf("%d ", workDay); // 5
    
    workDay = thur;
    printf("%d ", workDay); // 6
    
    return 0;
}
```
### [Format specifiers in C](https://www.tutorialspoint.com/format-specifiers-in-c)
### Escape character
![](https://i.imgur.com/sJw1xiX.png)
### Command Line Arguments
- When `main()` is called  by the runtime system, **2** arguments are passed to the function
    1. `argc`: an integer specifies the number of arguments typed on the command line
    2. `argv`: an array of character pointers (strings)
```c=
#include <stdio.h>
int main(int argc, char *argv[]) 
{
    int numOfArgs = argc;
    char *arg1 = argv[0];
    char *arg2 = argv[1];
    
    printf("Number of Arguments: %d\n", numOfArgs);
    printf("Argument 1 is the program name: %s\n", arg1);
    printf("Argument 2 is the command line argument: %s\n", arg2);

    return 0;
}
```
## Control Loop
- `for` loop is better when the loop involves initializing and updating a variable (**counter** controlled loop)
- `while` loop is better when the conditions are otherwise (**logic** controlled loop)
- `continue`, `break`

## Arrays
- Nice way to initialize an array
```c=
// all elements will be initialized to 0
int arr[10] = {0};  
int twoDimentionalArr[5][4] = {};
```
```c=
#include <stdio.h>

int main() {
    int arr[3][4] = {
        {1, 2}, 
        {3, 5}
    };
    
    for (int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
// 1 2 0 0 
// 3 5 0 0 
// 0 0 0 0
```

## Functions
### Arguments and Parameters
- **Parameters**: Variables in function declaration and function definition/implementation
- **Arguments**: The actual data value that get passed to the function
### Avoid Using Global Variables
1. Promote **coupling** between functions (dependencies)
2. Hard to debug
- Use parameters in function instead
- If a lot of data, use a **struct**

## Character Strings
### Initialize a String
- You can specify the size of the string explicitly, just make sure you leave an extra space for the terminating null character (**`\0`**).
```c=
#include <stdio.h>

int main() {
    char word[3] = { "Hi" };  // 'H', 'i', '\0'

    char str[50] = "Good"; 
    /**********************
    1. initialize the first 4 elements (str[0] to str[3])
    2. str[4] -> '\0'
    3. space is still allocated for all 50 elements 
    ***********************/
    printf("%s\n", str); // Good
    
    return 0;
}
```
- If the size specified is too small, the compiler **won't** put the **`\0`** at the end (and it doesn't complain about it either)
- So, **do not specifiy the size**, let the compiler figure out

### Input a String
```c=
#include <stdio.h>

int main() {

    char name[50]; 
    printf("Input your name: "); 
    scanf("%s", name);
    printf("Hi! %s\n", name);
    
    return 0;
}
```
- The **`%s`** format specifier is for inputting string
- No need to use the **`&`**(address of operator) on a string

### String Functions
- The C library supplies string-handling function prototypes in the **`string.h`** header file
1. Length: `strlen`
2. Copy: `strcpy` and `strncpy`
3. Concatenate: `strcat` and `strncat`
4. Compare: `strcmp` and `strncmp`
5. Search: `strchr` and `strstr`
6. Tokenize: `strtok`
7. Analyze: `islower`, `isupper`, `isalpha`, `isdigit`
---
#### 1. Get string length: [`strlen`](https://www.cplusplus.com/reference/cstring/strlen/)
`size_t strlen (const char * str);`

![](https://i.imgur.com/5POOp6Y.png)

```c=
#include <stdio.h>
#include <string.h>

int main ()
{
  char szInput[256];
  printf ("Enter a sentence: ");
  gets(szInput);
  printf ("The sentence entered is %u characters long.\n",(unsigned)strlen(szInput));
  return 0;
}
```
#### 2. Copy characters from string: [`strncpy`](https://www.cplusplus.com/reference/cstring/strncpy/?kw=strncpy)
`char * strncpy (char * destination, const char * source, size_t num);`

![](https://i.imgur.com/NztI4GX.png)

```c=
#include <stdio.h>
#include <string.h>

int main () {
    char str1[] = "Hello";
    char str2[6];
    printf("The size of str1 is %lu byte\n", sizeof(str1));
    printf("The size of str2 is %lu byte\n", sizeof(str2)); 
    
    /********************************************
    The str2 size must be at least 6 char, 
    otherwise it will print out incorrect result
    *********************************************/
    
    strncpy(str2, str1, sizeof(str2) - 1);
    //     (dest, src,  max_size_to_copy)
    
    printf ("str2: %s\n", str2);
    return 0;
    
    // The size of str1 is 6 byte
    // The size of str2 is 6 byte
    // str2: Hello
}
```
#### 3.Append characters from string: [`strncat`](https://www.cplusplus.com/reference/cstring/strncat/?kw=strncat)
`char * strncat (char * destination, const char * source, size_t num);`

![](https://i.imgur.com/No6hrzS.png)

```c=
#include <stdio.h>
#include <string.h>

int main ()
{
    char dest[20];
    char src[20];
    strcpy (dest, "To be ");
    strcpy (src, "or not to be");
    strncat (dest, src, 6);
    puts (dest);  // To be or not
    return 0;
}
```

#### 4-1. Compare two strings: [`strcmp`](https://www.cplusplus.com/reference/cstring/strcmp/?kw=strcmp)
`int strcmp (const char * str1, const char * str2);`

![](https://i.imgur.com/JWyVj6X.png)

#### 4-2. Compare characters of two strings: [`strncmp`](https://www.cplusplus.com/reference/cstring/strncmp/?kw=strncmp)
`int strncmp (const char * str1, const char * str2, size_t num);`

![](https://i.imgur.com/0kysKCW.png)

#### 5-1. Locate first occurrence of character in string: [`strchr`](https://www.cplusplus.com/reference/cstring/strchr/?kw=strchr)
`char * strchr (const char * str, int character);`

![](https://i.imgur.com/zpIMuw6.png)

```c=
#include <stdio.h>
#include <string.h>

int main () {
    char str[] = "an example";   // The string to be searched
    char chr = 'e';              // The target character (int chr = 'e';)
    char *pGotChar = NULL;       // Declare the pointer and initialize to NULL
    pGotChar = strchr(str, chr); // Store address where chr is found

    printf("The address of str: %p\n", str); 
    printf("The address of chr: %p\n", pGotChar); 
    printf("The position of chr in the str: %ld\n", pGotChar - str); // 3

    printf("The ASCII of chr: %c\n", *pGotChar);  // e
    printf("The value of chr: %d\n", *pGotChar);  // 101

    // (note) ASCII: American Standard Code for Information Interchange

    return 0;
}
```

#### 5-2. Locate substring: [`strstr`](https://www.cplusplus.com/reference/cstring/strstr/?kw=strstr)  

`char * strstr (const char * str1, const char * str2);`

![](https://i.imgur.com/T47249H.png)


#### 6. Split string into tokens: [`strtok`](https://www.cplusplus.com/reference/cstring/strtok/?kw=strtok)
`char * strtok (char * str, const char * delimiters);`

![](https://i.imgur.com/gDrlDR7.png)
```c=
#include <stdio.h>
#include <string.h>

int main () {
    char str[] = "Hello-- How are you - my name is Leo -!";
    const char del[2] = "-";
    char *token;

    // get the first token
    token = strtok(str, del);

    // walk through other tokens
    while (token != NULL) {
        printf("%s\n", token);  
        token = strtok(NULL, del);
    }
    
    /*****************************
    Hello
     How are you 
     my name is Leo 
    !
    *******************************/
    
    return 0;
}
```



---

## Pointers
### What is pointers?
- In programming languages, **indirection** is the ability to **reference** something using a name, reference, or container, instead of the value itself
- A pointer provides an **indirect** means of accessing the value of a particular data item
- Pointer is a **special variable** whose value is a **memory address** where certain type of value is located at

```c=
int var1 = 100;
int *ptr = &var1;
```
![](https://i.imgur.com/isFSNCE.png)

- The **`&`** operator is used to get the address of the variable
- The **`*`** symbol may mean 3 things depending on its position in the program
    1. Multiply
    2. **Declare a pointer**
    3. **Dereference a pointer** (indirection operator)


- **In the second case (Declare a pointer)**, when it is preceded by a keyword that denotes a data type, it indicates that the name placed after the `*` will represent the address of an entity of that type in your program. This is known as a pointer to a value of that type.

    For example,

    `int * myPtr;`

    Indicates that `myPtr` (the name) refers to a memory location, not the content of that location.

- **In the third case (Dereference a pointer)**, the `*` symbol indicates the **content** of the memory location pointed to by the given pointer.

    For example,

    `squared_myPtr = (*myPtr) * (*myPtr);`

    would multiply the contents of memory location pointed to by `myPtr` by itself.

```c=
#include <stdio.h>

int main () {
    int var1 = 100;
    // In here, * is used to declare a pointer variable
    int *ptr = &var1; 

    printf("var1 == %d\n", var1);     // 100
    printf("&var1 == %p\n", &var1);   // 0x123
    printf("ptr == %p\n", ptr);       // 0x123
    printf("&ptr == %p\n", &ptr);     // 0x155
    
    // In here, * is used to dereference the pointer
    printf("*ptr == %d\n", *ptr);     // 100
    
    return 0;
}
```

### Why use pointers?
1. Using pointers has the ability to access any memory location and perform arthimetic operations
2. Pointers allow you to refer to the same space in memory from multiple locations in your program
3. Pointers allow functions to modify data passed to them as variables (**pass by reference**)
4. Optimize a program to **run faster** or use **less memory** than it would otherwise
5. Pointers allow us to get **multiple values** from the function
6. Dynamic memory allocation

### Pointers Details
- Pointers occupy **8 bytes** and the addresses have **16 hexadecimal digits**
    - 64-bit OS machine -> compiler supports **64-bit addresses**
    - 32-bit OS machine -> compiler supports **32-bit addresses**
- A pointer really is a new type, **not an integer type**
- `%p` represents the fromat specifier for pointers
- You should **always initialize** a pointer when you declare it
```c=
#include <stddef.h>

int *ptr = NULL; // or int *ptr = 0;
```
- `NULL` is a constant that is defined in the standard library, and is the equivalent of **`0`** for a pointer -> guranteed not to point to any location in memory
- **(important!!!)** Before you use a pointer, it should be assigned a memory location that has been already allocated
    1. Assign the address of an existing variable
    2. Use **`malloc()`** function to allocate memory first 
- Check for `NULL` before you **dereference** a pointer (often when pointers are passed to functions)
```c=
int *ptr = NULL; // or int *ptr = 0;
if(!ptr) {...}
```
- Issues of array and `sizeof()`:
    - `sizeof()` is a keyword, not a function!
```c=
#include <stdio.h>
#include <string.h>

void printStrLength(char str[]) {

    printf("In printStrLength(), sizeof(str) = %lu (size of a pointer)\n", sizeof(str)); // size of a pointer
    printf("In printStrLength(), strlen(str) = %lu\n", strlen(str)); // expected length
    // why: sizeof is a keyword, not a function!
    // 1. https://www.cplusplus.com/forum/general/28539/
    // 2. https://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters-in-c/
}

int main () {
    char str[] = "Hello World";
    char s[50];
    char *ptr = str;

    printf("In main(), sizeof(ptr) = %lu (size of a pointer)\n", sizeof(ptr));   // 8
    printf("In main(), sizeof(str) = %lu\n", sizeof(str));   // 12
    printf("In main(), strlen(str) = %lu\n\n", strlen(str)); // 11

    printStrLength(str);

    printf("\n&str = %x\n", &str);  // be69c71c
    printf("str = %x\n", str);      // be69c71c
    printf("ptr = %x\n", ptr);      // be69c71c
    printf("&ptr = %x\n", &ptr);    // be69c6d0

    printf("\n*ptr = %d\n", *ptr); // 72
    printf("*ptr = %x\n", *ptr); // 48
    printf("*ptr = %c\n\n", *ptr); // 'H'

    int i;
    for(i = 0; i <= strlen(str); i++)
        s[i] = *(ptr + i);
        
    printf("%s\n", s); // Hello World
    
    return 0;
}
```
### Pointers and Const
```c=
int num = 10;
const int *ptr1 = &num; // Case 1: Value of num cannot be changed
int *const ptr2 = &num; // Case 2: Pointer address cannot be changed 
const int *const ptr3 = &num; // Case 3: 1 + 2
```
- Case 1: `const int *ptr`
```c=
#include <stdio.h>

int main () {
    int num = 10;
    int num1 = 666;
    const int *pNum = &num;
    /***********************************
     Can change the pointer value
     Cannot change the dereference value
    ************************************/

    // Legal operation
    num = 5;
    printf("num = %d\n", num);      // num = 5
    printf("*pNum = %d\n", *pNum);  // *pNum = 5
    
    // Can change the pointer value
    pNum = &num1;
    printf("*pNum = %d\n", *pNum); // *pNum = 666
    
    // Cannot change the dereference value
    *pNum = 7; // error: read-only variable is not assignable

    return 0;
}
```
- Case 2: `int *const ptr`
```c=
#include <stdio.h>

int main () {
    int num = 10;
    int num1 = 666;
    int *const pNum = &num;
    /***********************************
     Can change the dereference value
     Cannot change the pointer value
    ************************************/

    // Legal operation
    num = 5;
    printf("num = %d\n", num);      // num = 5
    printf("*pNum = %d\n", *pNum);  // *pNum = 5

    // Can change the dereference value
    *pNum = 7; 
    printf("*pNum = %d\n", *pNum);
    
    // Cannot change the pointer value
    pNum = &num1; // error: cannot assign to variable 'pNum' with const-qualified type 'int *const'
    
    return 0;
}
```

### Void Pointers
- `void *vPtr`: The type name **`void`** means absence of any type
- Void pointer can contain the address of a data item of any type
- **Note**:
    1. The void pointer **cannot be dereferenced directly** since it doesn't know what type of object it is pointing to
    2. The void pointer must first **be explicitly cast to another pointer type before it is dereferenced**
- `*(int *)vptr`: `(int *)` is **casting**; the foremost `*` is **dereferencing**
```c=
#include <stdio.h>

int main() {
    // declare variables
    int integer = 10;
    float floater = 8.6666;
    char character = 'x';

    void *vptr; // void pointer doesn't need to be initialized

    // point to int type
    vptr = &integer;
    printf("Value of integer: %d\n", *(int *)vptr);
    printf("Void pointer is now pointing to: %p\n", vptr);
    // 0x7ff7b3c92728

    // point to float type
    vptr = &floater;
    printf("Value of floater: %f\n", *(float *)vptr);
    printf("Void pointer is now pointing to: %p\n", vptr);
    // 0x7ff7b3c92724

    // point to char type
    vptr = &character;
    printf("Value of character: %c\n", *(char *)vptr);
    printf("Void pointer is now pointing to: %p\n", vptr);
    // 0x7ff7b3c92723

    return 0;
}
```

### Pointers and Arrays
```c=
#include <stdio.h>

int main() {
    // char arr[] = "Hello World";
    int arr[] = { 2, 3, 4, 5 };
    int *arrPtr = arr;

    printf("The array pointer is pointing to: %p\n", arrPtr);
    printf("The number that pointed by the array pointer: %d\n\n", *arrPtr);
    
    arrPtr++;

    printf("The array pointer is pointing to: %p\n", arrPtr);
    printf("The number that pointed by the array pointer: %d\n\n", *arrPtr);

    printf("The (array pointer + 1) is pointing to: %p\n", arrPtr + 1);
    printf("The number that pointed by the (array pointer + 1): %d\n\n", *(arrPtr + 1));

    printf("The (array pointer + 2) is pointing to: %p\n", arrPtr + 2);
    printf("The number that pointed by the (array pointer + 2): %d\n\n", *(arrPtr + 2));

    return 0;
}
```

```c=
#include <stdio.h>

// int arrayPartialSum(int arr[], const int n);
int arrayPartialSum(int *arr, const int n);

int main() {
    int values[] = {1, 2, 3, 4, 5};
    int partialSum = arrayPartialSum(values, 3);
    printf("The sum of values is: %d\n", partialSum);

    return 0;
}

int arrayPartialSum(int *arr, const int n) {
    int sum = 0;
    int *const arrEnd = arr + n; // the pointer that points to the target end of the array

    for (; arr < arrEnd; arr++) 
        sum += *arr;
    
    return sum;
}
```
- Valid and Invalid Operations
```c=
int urn[3];
int *ptr1, *ptr2;

// Valid
ptr1++;
ptr2 = ptr1 + 2;
ptr2 = urn + 1;

// Invalid
urn++; 
ptr2 = ptr2 + ptr1;
ptr2 = urn * ptr1;
```

## Debugging

### Common Problems
1. Logic Errors
2. Syntax Errors
3. Memory Corruption
4. Performance / Scalability
5. Lack of Cohesion
6. Tight Coupling (dependencies)

### Debugging Process
1. Understand the problem
2. Reproduce the problem
3. Simplify the problem (divide and conquer, isolate the source) 

### Compiler
- Always use `-Wall` for the compiler to notify all cases
- The compiler shows 2 types of problems
    1. errors
    2. warnings
