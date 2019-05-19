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

//to print data centrally alligned
void print(char s[]){
  printf("\t\t\t%s",s);	
}



int main() {
    	
  changeColor("0f");
  // ascii art
  printf("\n");
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
  		break;
  	case '2':
	  edititem();
	  break;	
	case '3':
		display();
		break;
	default:
		clr();
		main();
  }
//  clr();
  
}
// main menu
void gotoMenu(){
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

}

//to edit items
void edititem(){
	char newn[100];
	printf("enter the name of item to edit");
	scanf("%s",newn);
	fflush(stdin);
	fp=fopen("D:\\project.txt", "a+");
	rewind(fp);
	while(fread(&item,sizeof(struct ITEM),1,fp)!=NULL){
		//printf("%s",strcmp(item.name,newn));
		//fscanf(fp,"%s%d%d",item.name,item.quantity,item.price);
		if(strcmp(item.name,newn)==1){
			//ftell(fp);
			//fseek(fp,0,SEEK_CUR);
			printf("\nname is %s \n quantity is %d \nrate is %d ",item.name,item.quantity,item.price);
			print("enter new name : ");
			fflush(stdin);
            fgets(item.name, sizeof(item.name),stdin);
			print("enter new quantity : ");
			scanf("%d",&item.quantity);
			printf("enter new price : ");
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
			printf("the item does not exists");
			gotoMenu();
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
	gotoMenu();
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
