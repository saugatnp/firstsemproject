#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>

#include<ctype.h>



void additem();
void edititem();
struct ITEM {
  char name[30];
  int price;
  int quantity;
}
item;
FILE * fp;
char choose;
void display();
void clr(){
	system("cls");
}

void changeColor(char color[]){
	char variable[17]="color ";
    strcat(variable,color);
    system(variable);
	
}
void changeToDefaultColor(){
	changeColor("0f");
}

int main() {
    	
  changeColor("0f");
  printf("\n\t\t\twhat would you like to do?\n");
  printf("\t\t\tenter the number to perform operation\n");
  printf("\t\t\tenter 1 to add items \n\t\t\t");
  printf("enter 2 to edit items \n\t\t\t");
  choose=getch();
  switch(choose){
  	case '1':
  		additem();
  	case '2':
	  edititem();	
	case '3':
		display();
  }
//  clr();
  
}
void edititem(){
	
}

void print(char s[]){
  printf("\t\t\t%s",s);	
}
void notice(char s[]){
	printf("\t\t\t------ %s ------\n\n",s);
}


void display(){
  clr();
  notice("Displaying");
  printf("Items are :\n");
	printf("ItemNo.\tName.\tQuantity.\tPrice.");
	int i=1;
	fp=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(item),1,fp)){
		printf("\n%d\t%s\t%d\t%d",i,item.name,item.quantity,item.price);
		i++;
	}
	fclose(fp);
  	
}




// Adding
void additem() {	
  clr();
  notice("Adding a Item");
  fp = fopen("D:\\project.txt", "a");
    print("enter the name");
    gets(item.name);
    print("enter the price");
    scanf("%d", & item.price);
    print("enter the quantity");
    scanf("%d", & item.quantity);
    fwrite( & item, sizeof(struct ITEM), 1, fp);
    fclose(fp);
    printf("Enter New Record(Y/N)?");
    choose=getch();
    switch(toupper(choose)){
    	case 'Y':
    		additem();
    	default:
    		main();
    		clr();
	}
}