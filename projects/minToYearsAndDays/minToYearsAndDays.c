#include <stdio.h>

int main() {
    // variables declaration
    double minsInYear = (double) (60 * 24 * 365);
    int mins = 0;
    double years = 0.0, days= 0.0; 

    // Enter the total minutes and calculate
    printf("Enter the total minutes: ");
    scanf("%d", &mins);
    years = mins / minsInYear;
    days = years * 365;

    // print the result
    printf("%d minutes Equals to %f years and %f days.\n", mins, years, days);
    return 0;
}