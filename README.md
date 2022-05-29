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
