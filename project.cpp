#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<conio.h>

#include<ctype.h>





void additem();
void edititem();
struct ITEM {
  char name[100];
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
//colour 
void changeColor(char color[]){
	char variable[17]="color ";
    strcat(variable,color);
    system(variable);
	
}
void changeToDefaultColor(){
	changeColor("0f");
}


void print(char s[]){
  printf("\t\t\t%s",s);	
}

int main() {
    	
  changeColor("0f");
  printf("\t __ ___  __   __  __    _   _  __   _     __   __  __ _   _  __  _    ___    __      __ ___  __ _   _\n");
  printf("\t/__  |  /  | |_/ |_     ||_|| |__| | | | |__| / _ |_  ||_|| |_  | | |  |    /__ |_| /__  |  |_  ||_||\n");
  printf("\t__/  |  |__/ | | |__    |   | |  | | |_| |  | |__||__ |   | |__ | |_|  |    __/  /  __/  |  |__ |   |\n\n");



  print("what would you like to do?\n");
  print("enter the number to perform operation\n");
  print("enter 1 to add items \n");
  print("enter 2 to edit items \n");
  print("enter 3 to display items\n\t\t\t");
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
//to edit items
void edititem(){
	char newn[100];
	fflush(stdin);
	printf("enter the name of item to edit");
	scanf("%s",newn);
	printf("name to edit is",newn);
	fp=fopen("D:\\project.txt", "r+b");
	rewind(fp);
	while(fread(&item,sizeof(item),1,fp)){
		//fscanf(fp,"%s%d%d",item.name,item.quantity,item.price);
		if(strcmp(item.name,newn)==0){
			printf("\nname is %s \n quantity is %d \nrate is %d ",item.name,item.quantity,item.price);
			print("enter new name");
			scanf("%s",item.name);
			fwrite(&item,sizeof(item),1,fp);
			print("enter new quantity");
			scanf("%d",item.quantity);
			fwrite(&item,sizeof(item),1,fp);
			printf("enter new price");
			scanf("%d",item.price);
			fwrite(&item,sizeof(item),1,fp);
			fclose(fp);
		}
	}
}


void notice(char s[]){
	printf("\t\t\t------ %s ------\n\n",s);
}

// to display items
void display(){
  clr();
  notice("Displaying");
  printf("Items are :\n");
	printf("ItemNo.\t Name.\t Quantity.\tPrice.\n");
	int i=1;
	fp=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(item),1,fp)!=NULL){
		printf("\n%d\t%s",i,item.name);
		printf("\t%d\t%d",item.quantity,item.price);
		i++;
	}
	printf("\ndo you want to go back to main menu(y/n)\n");
	choose=getch();
	switch(choose){
		case 'y':
			clr();
			main();
		case 'Y':
			clr();
		    main();
		default:
		    exit(0);	
	}
	fclose(fp);
  	
}




// to add items
void additem() {	
  clr();
  notice("Adding a Item");
  fp = fopen("D:\\project.txt", "a");
    print("enter the name");
   // gets(item.name);
    fflush(stdin);
    fgets(item.name, sizeof(item.name),stdin);
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
