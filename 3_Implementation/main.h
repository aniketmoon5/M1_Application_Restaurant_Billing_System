#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void generateBillHeader(char name[50],char date[30])
{
    printf("\n\n");
        printf("        || Rainbow Restaurant||       ");
        printf("\n---------------------------------------");
        printf("\nDate: %s",date);
        printf("\nInvoice to: %s",name);
        printf("\n");
        printf("---------------------------------------\n");
        printf("Items\t\t");
        printf("Quantity\t");
        printf("Total\t\t");
        printf("\n---------------------------------------");
        printf("\n\n");
}
void generateBillBody(char item[30],int qty,float price)
{
    printf("%s\t\t",item);
        printf("%d\t\t",qty);
        printf("%.2f\t\t",qty*price);
        printf("\n");
}

void generateBillFooter(float total)
{
    printf("\n");
    float dis=0.1*total;
    float netTotal=total-dis;
    float cgst=0.09*netTotal;
    float grandTotal=netTotal+ 2*cgst;
    printf("---------------------------------------\n");
    printf("Sub Total\t\t\t%.2f",total);
    printf("\nDiscount @10%s\t\t\t%.2f","%",dis);
    printf("\n\n");
    printf("Net Total\t\t\t%.2f",netTotal);
    printf("\nCGST @9%s\t\t\t%.2f","%",cgst);
    printf("\nSGST @9%s\t\t\t%.2f","%",cgst);
    printf("\n");
    printf("Grand Total\t\t\t%.2f",grandTotal);
    printf("\n---------------------------------------\n");
}
