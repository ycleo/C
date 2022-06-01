#include <stdio.h>

#define PAYRATE 12.00
#define TAXRATE_300 .15
#define TAXRATE_150 .20
#define TAXRATE_REST .25
#define OVERTIME 40

int main() {

    // declare variables
    int hours = 0;
    double grossPay = 0.0;
    double taxes = 0.0;
    double netPay = 0.0;

    // get the working hours
    printf("How many hours did you work this week? ");
    scanf("%d", &hours);

    // calculate the gross pay
    if (hours <= 40) {
        grossPay = hours * PAYRATE;
    } else {
        double overWorkHours = hours - 40.0;
        grossPay = (40.0 * PAYRATE) + (overWorkHours * PAYRATE * 1.5);
    }
    
    // calculate the taxes
    if (grossPay <= 300) {
        taxes = grossPay * TAXRATE_300;
    } else if (grossPay > 300 && grossPay <= 450) {
        taxes = 300.0 * TAXRATE_300 + (grossPay - 300.0) * TAXRATE_150;
    } else {
        taxes = 300.0 * TAXRATE_300 + 150.0 * TAXRATE_150 + (grossPay - 450.0) * TAXRATE_REST;
    }

    // calculate the net pay and print the result
    netPay = grossPay - taxes;
    printf("Your gross pay is %.2f, but your taxes is %.2f, so your net pay is %.2f.\n", grossPay, taxes, netPay);

    return 0;
}