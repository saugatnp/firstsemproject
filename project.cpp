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
}item;

FILE * fp;
char choose;
void display();
void clr(){
	system("cls");
}
//change color
void changeColor(char color[]){
	char variable[17]="color ";
    strcat(variable,color);
    system(variable);
	
}
void changeToDefaultColor(){
	changeColor("0f");
}
// display heading
void notice(char s[]){
	printf("\t\t\t\t------------- %s -------------\n\n",s);
	printf("\t\t\t*********************************************************\n\n\n\n");
}

//to print data centrally alligned
void print(char s[]){
  printf("\t\t\t%s",s);	
}
//ascii art
void asciiArt(){
  changeColor("0b");
  printf("\n");
  printf("\t __ ___  __   __  __    _   _  __   _     __   __  __ _   _  __  _    ___    __      __ ___  __ _   _\n");
  printf("\t/__  |  /  | |_/ |_     ||_|| |__| | | | |__| / _ |_  ||_|| |_  | | |  |    /__ |_| /__  |  |_  ||_||\n");
  printf("\t__/  |  |__/ | | |__    |   | |  | | |_| |  | |__||__ |   | |__ | |_|  |    __/  /  __/  |  |__ |   |\n\n");
}


int main() {
   clr(); 	
  asciiArt();
  //changeColor("0f");
  notice("MAIN MENU");
  print("What would you like to do?\n");
  print("Enter the number to perform operation.\n");
  print("Enter 1 to add items. \n");
  print("Enter 2 to edit items. \n");
  print("Enter 3 to display items.\n");
  print("Enter 4 to exit.\n\t\t\t");
  choose=getch();
  switch(choose){
  	case '1':
  		additem();
  		break;
  	case '2':
	  edititem();
	  break;	
	case '3':
		display();
		break;
	case '4':
		exit(0);
	default:
		clr();
		main();
  }

  
}
// main menu
void gotoMenu(){
		print("Do you want to go back to main menu(y/n)?");
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

}

//to edit items
void edititem(){
	clr();
	asciiArt();
	notice("EDIT ITEMS");
	char newn[100];
	print("Enter the name of item to edit : ");
	scanf("%s",newn);
	fflush(stdin);
	fp=fopen("D:\\project.txt", "a+");
	rewind(fp);
	while(fread(&item,sizeof(struct ITEM),1,fp)!=NULL){
		if(strcmp(item.name,newn)==1){
			notice("Item Details ");
			printf("\t\t\tName : %s ",item.name);
		    printf("\t\t\tQuantity : %d\n",item.quantity); 
			printf("\t\t\tRate : %d \n\n",item.price);
			print("Enter new name : ");
			fflush(stdin);
            fgets(item.name, sizeof(item.name),stdin);
			print("\n\t\t\tEnter new quantity : ");
			scanf("%d",&item.quantity);
			printf("\n\t\t\tEnter new price : ");
			scanf("%d",&item.price);
			ftell(fp);
			fseek(fp,0,SEEK_CUR);
			fwrite(&item,sizeof(struct ITEM),1,fp);
			rewind(fp);
			fclose(fp);
			clr();
			print("Item Succesfully updated ");
		   	gotoMenu();	
		}
		else {
			printf("\n\t\t\tThe item does not exists");
			gotoMenu();
		}
	}
}


// to display items
void display(){
  clr();
  asciiArt();
  notice("DISPLAYING ITEMS");
  printf("Items are :\n");
	printf("ItemNo.\t Name.\t Quantity.\tPrice.\n");
	int i=1;
	fp=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(item),1,fp)!=NULL){
		printf("\n%d",i);
		printf("\t%s",item->name);
		printf("\t\t   %d",item->quantity);
		printf("\t\t%d\t\n",item->price);
		i++;
	}
	gotoMenu();
	fclose(fp);
  	
}


// to add items
void additem() {	
  clr();
  asciiArt();
  notice("Adding a Item");
  fp = fopen("D:\\project.txt", "a");
    print("Enter the name : ");
    fflush(stdin);
    fgets(item.name, sizeof(item.name),stdin);
    print("Enter the price : ");
    scanf("%d", & item.price);
    print("Enter the quantity : ");
    scanf("%d", & item.quantity);
    fwrite( & item, sizeof(struct ITEM), 1, fp);
    fclose(fp);
    print("Enter New Record(Y/N)?\n");
    choose=getch();
    switch(toupper(choose)){
    	case 'Y':
    		additem();
    	default:
    		gotoMenu();
    		clr();
	}
}
