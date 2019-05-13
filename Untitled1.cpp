#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
int additem();
//void edititem();
struct {
	char name;
	int price;
	int quantity;
}item ;
int main(){
	int a;
	FILE *fp;
	fp=fopen("B:\\project.txt","w");
	if(fp==NULL){
       printf("\n Cannot create or open file.");
       exit(0);
    }
	fputs("\nItem No.  \t Item Name  \t  Item Price  \t Quantity available",fp);
	fclose(fp);
	printf("\t\t\twhat would you like to do?\n");
	printf("\t\t\tenter the number to perform operation\n");
	printf("\t\t\tenter 1 to add items \n\t\t\t");
	printf("\t\t\tenter 2 to edit items \n\t\t\t");
	scanf("%d",&a);
	system("cls");
	if(a==1){
	additem();
}
  //  else if (a==2){
    //	edititem();
	//}
}
int additem(){
	FILE *fp;
	int price,quantity;
	char name;
	fp=fopen("B:\\project.txt","a");
	printf("\t\t\tdo you want to enter new item(y/n)?\n\t\t\t");
	while(toupper(getche())=='Y'){
			printf("\n\t\t\tenter the name\n\t\t\t");
	        scanf("%s",&item.name);
	        printf("\t\t\tenter the price\n\t\t\t");
	        scanf("%d",&item.price);
	        printf("\t\t\tenter the quantity\n\t\t\t");
	        scanf("%d",&item.quantity);
	        
	        fseek(fp,0,SEEK_END);
            fwrite(&item,sizeof(item),1,fp);
       //     fwrite(&price,1,sizeof(price),fp);
         //   fwrite(&quantity,1,sizeof(quantity),fp);
            printf("Enter New Record(Y/N)?");
            fclose(fp);
	}
	main();
}
/*void edititem(){
	FILE *fp;
	char na;
	int choice,size;
	printf("\t\t\tEDIT ITEMS\n");
	printf("enter the item name");
	scanf("%s",&na);
	fp=fopen("B:\\project.txt","r+b");
	rewind(fp);
	while(fread(&item,sizeof(item),1,fp)==1){
		if(strcmp(item.name,na)==0){
			printf("name = %s",item.name);
			printf("price = %d",item.price);
			printf("quantity =%d",item.quantity);
			printf("do you want to edit this item(y/n)?");
			fflush(fp);
            if(toupper(getche())=='Y'){
                    
                    printf("1- Edit Name ");
                    printf("2- Edit Rate ");
                    printf("3- Edit Quantity ");
                    printf(" Enter Your Choice(1, 2, 3) ");
                    scanf("%d",&choice);
                    switch(choice)
                    {
                    case 1:
                        system("cls");
                        printf("EDIT RECORDS");
                        printf(" Enter New Name: ");
                        scanf("%s",item.name);
                        size=sizeof(item);
                        fseek(fp,-size,1);
                        fwrite(&item,sizeof(item),1,fp);
                        break;
                    case 2:
                        system("cls");
                        printf("EDIT RECORDS");
                        printf(" Enter New Rate: ");
                        scanf("%f",&item.price);
                        size=sizeof(item);
                        fseek(fp,-size,1);
                        fwrite(&item,sizeof(item),1,fp);
                        break;
                    case 3:
                        system("cls");
                        printf("EDIT RECORDS");
                        printf(" Enter New Quantity: ");
                        scanf("%d",&item.quantity);
                        size=sizeof(item);
                        fseek(fp,-size,1);
                        fwrite(&item,sizeof(item),1,fp);
                        break;
                    }
                    printf("item edited");
                }
            }
		}
	}*/

	

