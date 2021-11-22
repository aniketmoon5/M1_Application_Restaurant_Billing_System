#include "main.h"

struct items
{
    char item[30];
    float price;
    int qty;
};

struct orders
{
    char customer[50];
    char date[50];
    int numOfItems;
    struct items itm[50];
};


int main()
{
    int total;
    int opt,n;
    struct orders ord;
    struct orders order;
    char save='y';
    char contFlag= 'y';
    char name[50];
    FILE *fp;   
    while(contFlag=='y'){
    float total =0;
    int invoiceFound=0;
    printf("\n\n");
    printf("        ||Rainbow Restaurant||        \n");
    printf("\n");
    printf("Please select the operation you would like to perform: \n");
    printf("\n1.Generate Invoice");
    printf("\n2.Show all Invoices");
    printf("\n3.Search a particular Invoice");
    printf("\n4.Exit\n\n");

    printf("\nYour choice: ");
    scanf("%d",&opt);
    fgetc(stdin);
    switch(opt){
        case 1:
    
        printf("\nPlease enter the name of the customer: ");
        fgets(ord.customer,50,stdin);
        ord.customer[strlen(ord.customer)-1]=0;
        strcpy(ord.date,__DATE__);
        printf("\nPlease enter the number of items: ");
        scanf("%d",&n);
        ord.numOfItems =n;
        for (int i=0;i<n;i++){
            fgetc(stdin);
            printf("\n\n");
            printf("Please enter the item %d: ",i+1);
            fgets(ord.itm[i].item,20,stdin);
            ord.itm[i].item[strlen(ord.itm[i].item)-1]=0;
            printf("Please enter the quantity: ");
            scanf("%d",&ord.itm[i].qty);
            printf("Please enter the unit price: ");
            scanf("%f",&ord.itm[i].price);
            total += ord.itm[i].qty * ord.itm[i].price;

        }
        generateBillHeader(ord.customer,ord.date);
        for(int i=0;i<ord.numOfItems;i++){
            generateBillBody(ord.itm[i].item,ord.itm[i].qty,ord.itm[i].price);
        }
        generateBillFooter(total);

        printf("\nDo you want to save the invoice [y/n]: ");
        scanf("%9s",&save);

        if(save == 'y'){
            fp = fopen("RestaurntBill.dat","a+");
            fwrite(&ord,sizeof(struct orders),1,fp);
            if(fwrite != 0)
            printf("\nSuccessfully Saved!");
            else
            printf("\nError Saving");
            fclose(fp);
        }
        break;

        case 2:    
        fp = fopen("RestaurantBill.dat","r");
        printf("\n   ***Previous Invoices***  \n");
        while(fread(&order,sizeof(struct orders),1,fp))
        {
            float tot=0;
            generateBillHeader(order.customer,order.date);
            for(int i=0;i<order.numOfItems;i++)
            {
                generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;
            }
            generateBillFooter(tot);
        }
        fclose(fp);
        break;

        case 3:
        printf("\nEnter the name of the customer: ");
        fgetc(stdin);
        fgets(name,50,stdin);
        name[strlen(name)-1] =0;
        fp = fopen("RestaurantBill.dat","r");
        printf("\n   ***Invoice of %s***  \n",name);
        while(fread(&order,sizeof(struct orders),1,fp))
        {
            float tot=0;
            if(!strcmp(order.customer,name)){
            generateBillHeader(order.customer,order.date);
            for(int i=0;i<order.numOfItems;i++)
            {
                generateBillBody(order.itm[i].item,order.itm[i].qty,order.itm[i].price);
                tot+=order.itm[i].qty * order.itm[i].price;


            }
            
            generateBillFooter(tot);
            invoiceFound=1;
            }
        }
        if(!invoiceFound){
            printf("Sorry the invoice for %s does not exist",name);
        }
        fclose(fp);
        break;


    case 4:
    printf("\n\nThankyou For Dining!\n\n");
    exit(0);
    break;

    default:
    printf("Sorry invalid option");
    break;
    } 
    printf("\nDo you want to perform another operation? ");
    scanf("%9s",&contFlag);
    }
    printf("\n\nThankyou For Dining!\n\n");
    printf("\n\n");   
    return 0;
}



