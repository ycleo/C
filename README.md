# C

## Basic Concepts

- [Compilation process](https://www.javatpoint.com/compilation-process-in-c)
- [Using Clang in VS Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)
- [Preprocessor](https://www.tutorialspoint.com/cprogramming/c_preprocessors.htm)
  - Preprocessor statements are identified by the **pound sign(#)**
  - 1st challenge used a preprocessor directive, specifically **#include**
  - Create constants and macros by **#def**
  - Conditional statements: **#ifdef**, **#endif**, **#else**, **#ifndef**
- [Header files](https://www.tutorialspoint.com/cprogramming/c_header_files.htm)
  - Define information about some of the functions that are provided by the files, and its name should always be **lowercase**
  - **#include <file.h>** tells the preprocessor to look for the file in one or more standard system directories
  - **#include "file.h"** tells the preprocessor to first look into the current directory
  - We should use **#ifndef** and **#define** to protect multiple inclusions of a header file

## Variables and Data Types

### Memory

- A program needs to stroe the instructions of its program and the data that is acts upon while your computer is executing that program.
  - This information is stored in memory
  - **RAM** (Random Access Memory) contents are lost when the computer is turned off
  - **Hard drives** store persistent data
- bits in memory are grouped into sets of **eight** -> called **byte**
- each byte has been labeled with a number -> called **address**

### Naming Rules

1. Must begin with a letter or underscore ( \_ )
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

- When `main()` is called by the runtime system, **2** arguments are passed to the function
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
    /*****************************************************
    1. initialize the first 4 elements (str[0] to str[3])
    2. str[4] -> '\0'
    3. space is still allocated for all 50 elements
    ******************************************************/
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
const int *ptr1 = &num; // Case 1: The dereference value of the pointer cannot be changed
int *const ptr2 = &num; // Case 2: The address of the pointer cannot be changed
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
int len = ptr2 - ptr1;

// Invalid
urn++;
ptr2 = ptr2 + ptr1; // make no sense to add two addresses
ptr2 = urn * ptr1;
```

### Dynamic Memory Allocation

1. Allows memory for storing data to be **allocated dynamically when the program executes**
2. Allows programmers to create pointers at runtime that are just enough to hold the amount of required data -> **saving memory**

#### [Heap vs. Stack](https://stackoverflow.com/questions/79923/what-and-where-are-the-stack-and-heap)

- **Heap**
  - dynamic memory allocation reserves space in a memory area called heap
  - When you store data on the heap it allows for more change. You can arbitrarily change the size of data objects
  - It sticks around a lot longer when programmers allocate memory in a heap, and it is programmers' duty to keep track of when the allocated memory is no longer required
- **Stack**
  - **Function arguments** and **local varialbes in a function** are stored in stack
  - So when you execute a funtion, it gets put on the stack. You don't control stuff on the stack. It automatically gets allocated and deleted

![image](https://hackmd.io/_uploads/rye8GWmca.png)

![image](https://hackmd.io/_uploads/HkEvMbX5T.png)

#### [malloc](https://cplusplus.com/reference/cstdlib/malloc/?kw=malloc): Allocate memory block

- `void* malloc (size_t size);`
- Need to include `stdlib.h`
- The argument is the number of **bytes** of memory that you want to allocate
- Returns the **address (pointer)** of the first byte of allocated memory
- The content of the newly allocated block of memory is not initialized, remaining with **indeterminate values**.

![](https://i.imgur.com/nNrPSsX.png)

- If the memory cannot be allocated for any reason
  - `malloc()` returns a pointer with the value `NULL`
  - It is always a good idea to check any dynamic memory allocation request immediately with an `if` statement to **make sure the memory has been allocated**

```c=
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *pStr = (char *)malloc(-1)

    printf("pStr = %p\n", pStr);

    if (pStr == NULL) { // or (!pStr)
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Memory allocation succeeded\n");
    free(pStr);    // deallocate memory space
    pStr = NULL;   // make pStr points to nothing

    /***************************
     * pStr == 0x0
     * Memory allocation failed
     * *************************/

    return 0;
}
```

- Other related function: [calloc](https://cplusplus.com/reference/cstdlib/calloc/?kw=calloc), [realloc](https://cplusplus.com/reference/cstdlib/realloc/)

```c=
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *pStr = NULL;

    // initail memory allocation
    pStr = (char *)malloc(3 * sizeof(char));
    strcpy(pStr, "Hi");
    printf("String = %s, Address = %p\n", pStr, pStr);

    // reallocating memory
    pStr = (char *)realloc(pStr, 6 * sizeof(char));
    strcat(pStr, " Leo!");
    printf("String = %s, Address = %p\n", pStr, pStr);

    free(pStr);    // deallocate memory space
    pStr = NULL;   // make pStr points to nothing

    /*********************************************
     * String = Hi, Address = 0x600003664020
     * String = Hi Leo!, Address = 0x600003664020
     * *******************************************/

    return 0;
}
```

- Memory that you allocated on the heap will be automatically released when your program ends, but better to explicitly **release** the memory when it is no longer being used
- A **memory leak** occurs when you allocate some memory dynamically and you did **not retain the reference** to it, so you are unable to release the memory
  - often occurs within a loop, your program will consume more and more of the available memory on each loop iteration and eventually occupy it all
- To free the dynamically allocated memory, you must still have the access to the address that references to the memory block

#### [free](https://cplusplus.com/reference/cstdlib/free/?kw=free): Deallocate memory block

- `void free (void* ptr);`

![](https://i.imgur.com/VUzpyon.png)

- Interview Question: What are **memory leaks** and **buffer overflows**?
- Answers:
  - Memory Leak:
    - A memory leak occurs when a program allocates memory (using functions like malloc in C or new in C++) but fails to release or deallocate that memory when it is no longer needed.
    - Over time, if a program repeatedly allocates memory without releasing it, it can consume an increasing amount of memory, leading to performance degradation and eventually causing the program to run out of memory.
    - Memory leaks are a common source of issues in long-running programs, such as server applications or daemons, where the program continues to run for extended periods.
      Example:

```c=
void memoryLeakExample() {
    int *ptr = new int; // Allocate memory
    // No delete statement to release the allocated memory
}
```

- Buffer Overflow:
  - A buffer overflow occurs when a program writes more data into a buffer (e.g., an array) than it can hold, leading to the overwriting of adjacent memory.
  - Buffer overflows can result in unpredictable behavior, crashes, and security vulnerabilities. Attackers can exploit buffer overflows to inject malicious code into a program's memory, leading to security breaches.
  - Common scenarios for buffer overflows include using functions like strcpy or sprintf in C without proper bounds checking.
    Example:

```c=
void bufferOverflowExample() {
    char buffer[5]; // Buffer can hold only 4 characters plus the null terminator
    strcpy(buffer, "Overflow"); // Writing more than the buffer size
}
```

Both memory leaks and buffer overflows can be challenging to debug and fix. To mitigate these issues:

- For memory leaks, it's essential to track memory allocations and ensure that corresponding deallocation (using free in C or delete in C++) is performed when the memory is no longer needed.
- For buffer overflows, developers should use functions that perform bounds checking (e.g., strncpy instead of strcpy in C) and adopt safer alternatives such as using smart pointers in C++ or array classes that perform bounds checking.
- Additionally, modern programming languages and tools often include features or mechanisms to help prevent and detect these issues, such as automatic memory management (garbage collection) in languages like Java or C#, and bounds checking in languages like Rust.

---

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
 
## Structures
### Create and Update Structures
```c=
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Date {
    int day;
    int month;
    int year;
    char *pViewer;
};

int main() {

    /* initialize the today struct variable */
    struct Date today = { 13, .year = 2022, .pViewer = (char *)calloc(50, sizeof(char)) };
    // '.' is the member selection operator
    strcpy(today.pViewer, "Leo");
    today.month = 6;  
    printf("%s's notification: Today is %d-%d-%d.\n", today.pViewer, today.year, today.month, today.day);
    
    // Assignment with compund literals
    today = (struct Date) { 1, 1, 2023 };  
    printf("%s's notification: Today is %d-%d-%d.\n", today.pViewer, today.year, today.month, today.day);

    return 0;
}
```

### Structures and Pointers
- **Pointers to structures** are easier to manipulate than structures themselves
- Passing a pointer as an argument into a function is more efficient because you only pass in the address instead a whole data
- Hence, many data representations use structures containing pointers to other structures

```c=
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Time {
    int second;
    int minute;
    int hour;
} now = {30, 28, 11};

struct Date {
    int day;
    int month;
    int year;
    struct Time *time;
};

int main() {

    /* initialize the today struct variable */
    struct Date today = { 13, 6, 2022, .time = &now };
    
    printf("Today is %d-%d-%d\n", today.year, today.month, today.day);
    printf("Now is %d:%d:%d\n", (*today.time).hour, today.time -> minute, today.time -> second);
    // There are 2 ways of accessing member of the "now" data structure
    // (*pointer).dataVariable
    // pointer -> dataVariable

    return 0;
}
```
- (Note) member selection operator (`.`) has a **greater precedence** than the indirection operator (`*`)

### Character Arrays & Character Pointers in Structures
#### Character Array
```c=
struct Name {
    char firstName[20];
    char lastName[20];
};
``` 
- When initialize a `struct Name` type variables (ex) `struct Name manager = {"Bob", "Vander"};`
    - Strings are stored inside the structure
    - Structure has allocated total 40 bytes for the two character arrays
#### Character Pointer
```c=
struct PName {
    char *firstName;
    char *lastName;
};
```
- When initialize a `struct PName` type variables (ex) `struct PName engineer = {"Leo", "Lee"};`
    - Strings are stored wherever the compiler stores string constants
    - Structure has allocated total 16 bytes for the two character pointers
    - It can be used **only with strings that have had space allocated** for them elsewhere

```c=
#include <stdio.h>

struct Name {
    char firstName[20];
    char lastName[20];
};

struct PName {
    char *firstName;
    char *lastName;
};

int main() {

    char engineerFirstName[] = "Leo";
    char engineerLastName[] = "Lee";

    struct Name manager = { "Bob", "Vander" };
    struct PName engineer;

    engineer.firstName = engineerFirstName;
    engineer.lastName = engineerLastName;

    printf("%s and %s\n", manager.firstName, engineer.firstName);
    // Bob and Leo
    
    return 0;
}
```
