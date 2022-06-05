#include <stdio.h>
#include <math.h>

int findGCD(int a, int b);
float absoluteValue(float num);

int main () {
    // declare variables
    int a = 83, b = 240;
    int gcd = 0;

    float c = 9;
    float abs = 0.0;

    float d = 13.0;
    float sqt = 0.0;

    // Find the greatest common divisor of a and b
    gcd = findGCD(a, b);
    printf("The GCD of %d and %d is %d.\n", a, b, gcd);

    // calculate the absolute value of c
    abs = absoluteValue(c);
    printf("The absolute value of %.2f is %.2f.\n", c, abs);

    // calculate the square root of d
    printf("The square root of %.2f is %.2f.\n", d, sqrt(d));

    return 0;
}

int findGCD(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

float absoluteValue(float num) {
    return num >= 0 ? num : -num;
}

