#include <stdio.h>
#include <stdbool.h>

void printPrimes (int *primes, int primeIndex) {
    int i = 0;
    while(i < primeIndex) {
        printf("%d ", primes[i]);
        i++;
    }
    printf("\n");
}

int main() {
    int primes[50] = {0};
    int primeIndex = 2;
    bool isPrime;

    // hardcode prime numbers
    primes[0] = 2;
    primes[1] = 3;

    for (int num = 5; num <= 100; num += 2) {
        isPrime = true;
        for(int i = 1; isPrime && num / primes[i] >= primes[i]; i++) 
            if (num % primes[i] == 0) 
                isPrime = false;
        
        // insert the number into the prime array if it is a prime
        if (isPrime) {
            primes[primeIndex] = num;
            primeIndex++;
        }
    }
    printPrimes(primes, primeIndex);
    return 0;
}