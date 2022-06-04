#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define YEARS 5
#define MONTHS 12

double rand_double() {
    return (double)rand() / (double)RAND_MAX;
}

double rand_double_interval(double a, double b) {
    return rand_double() * (b - a) + a;
}

int main() {
    // declare variables 
    srand(time(NULL));
    double totalRain = 0.0;
    double yearlyRain[5] = {0.0};
    double monthlyRain[12] = {0.0};

    // initialize rainfall records
    double rainfall[YEARS][MONTHS];
    for (int row = 0; row < YEARS; row++) {
        for(int col = 0; col < MONTHS; col++) {
            rainfall[row][col] = rand_double_interval(1, 8);
            printf("%.2lf ", rainfall[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // total rainfall for each year
    for (int year = 0; year < YEARS; year++) {
        for (int month = 0; month < MONTHS; month++) {
            yearlyRain[year] += rainfall[year][month];
            monthlyRain[month] += rainfall[year][month];
        }
        
        printf("Year %d: %.2lf\n", year + 2010, yearlyRain[year]);
        totalRain += yearlyRain[year];
    }

    // average yearly rainfall
    printf("\nThe yearly average: %.2lf\n", totalRain / YEARS);

    // average rainfall for each month
    printf("\nMonthly averages:\n");
    for (int month = 0; month < MONTHS; month++) {
        printf("%.2lf ", monthlyRain[month] / YEARS);
    }
    printf("\n");

    return 0;
}