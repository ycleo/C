#include <stdio.h>
#include <string.h>

struct Employee {
    char *name;
    int hireDate;
    float salary;
};

int main() {
    char employeeName[] = "Leo";

    struct Employee engineer = { employeeName, 6, 20000.5 };
    printf("\nThe member was hired on %d is %s. His salary is %.2f.\n", engineer.hireDate, engineer.name, engineer.salary);

    memset(employeeName, 0, sizeof(employeeName));
    printf("New employee's name: ");
    scanf("%s", employeeName);
    engineer.name = employeeName;
    
    printf("New employee's hire date: ");
    scanf("%d", &engineer.hireDate);
    
    printf("New employee's salary: ");
    scanf("%f", &engineer.salary);

    printf("\nThe new member was hired on %d is %s. His salary is %.2f.\n", engineer.hireDate, engineer.name, engineer.salary);

    return 0;
}