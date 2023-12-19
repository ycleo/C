#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    char *name;
    int quantity;
    float price;
    float amount;
};

void readItem(struct Item *pItem);
void printItem(struct Item *pItem);

int main()
{
    // struct Item *pItem = (struct Item *)malloc(sizeof(struct Item));
    struct Item item;
    struct Item *pItem = &item;

    pItem->name = (char *)malloc(20 * sizeof(char));

    if (!pItem->name)
        exit(-1);
    // printItem(pItem);
    readItem(pItem);
    printItem(pItem);

    free(pItem->name);

    return 0;
}

void readItem(struct Item *pItem)
{
    printf("\nItem name: ");
    scanf("%s", pItem->name);

    printf("\nQuantity: ");
    scanf("%d", &((*pItem).quantity)); // dereferences the pointer "pItem" to access the quantity member. (not recommended)

    printf("\nPrice: ");
    scanf("%f", &(pItem->price));

    pItem->amount = (pItem->price) * (pItem->quantity);
    // There are 2 ways of accessing member of the "now" data structure
    // (*pointer).dataVariable
    // pointer -> dataVariable
    return;
}

void printItem(struct Item *pItem)
{
    printf("\nThe info of the item: \n");
    printf("- Item name: %s\n", pItem->name);
    printf("- Quantity: %d\n", (*pItem).quantity);
    printf("- Price: %.2f\n", pItem->price);
    printf("- Amount: %.2f\n", pItem->amount);
    return;
}
