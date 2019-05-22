#include<stdio.h>

#include<stdlib.h>
#include<time.h>

#include<string.h>

#include<conio.h>

#include<ctype.h>





void additem();
void edititem();
void listitem();
void recorditem();
void search();
void deleteitem();
void update(struct ITEM,struct ITEM);
void deleteitem(struct ITEM);

struct ITEM {
  char name[100];
  int price;
  int id;
  int quantity;
}item;

struct record{
	char itemname[100];
	time_t time;
	int price;	
}record;

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
  srand(time(NULL)); 
  asciiArt();
  //changeColor("0f");
  notice("MAIN MENU");
  print("What would you like to do?\n");
  print("Enter the number to perform operation.\n");
  print("Enter 1 to add items. \n");
  print("Enter 2 to edit items. \n");
  print("Enter 3 to display items.\n");
  print("Enter 4 to search.\n");
  print("Enter 5 to delete.\n");
  print("Enter 6 to add a sell record .\n");
  print("Enter 7 to view sell records .\n");
  print("Enter 8 to exit.");
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
		search();
	case '5':
		deleteitem();
	case '6':
		recorditem();
	case '7':
		listitem();
	case '8':
		exit(0);


	default:
		clr();
		main();
  }

  
}
// main menu
void gotoMenu(){
	printf("\n");
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
//to delete


void deleteitem(){
	clr();
	asciiArt();
	notice("DELETE ITEMS");
	char newn[100];
	print("Enter the name of item to delete : ");
	fflush(stdin);
	gets(newn);
	fflush(stdin);
	FILE *fp1=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(struct ITEM),1,fp1)){
		if(strcmp(item.name,newn)==0){
			notice("Item Details ");//push hana n
			printf("\t\t\tName : %s ",item.name);
		    printf("\t\t\tQuantity : %d\n",item.quantity); 
			printf("\t\t\tRate : %d \n\n",item.price);
			printf("\t\t\t\t------------- %s deleted succesfully -------------\n\n",item.name);
		
			deleteitem(item);
		}
	}
	printf("\n\t\t\tThe item does not exists");
	gotoMenu();

}
//record a item


void recorditem(){
   clr();
  asciiArt();
  notice("Record a Item");
  fp = fopen("D:\\record.txt", "a");
  int uniqueId,matched=0;
  FILE *fp1 = fopen("D:\\project.txt", "r");
    print("Enter the Unique Id : ");
    fflush(stdin);
    scanf("%d",&uniqueId);    
    while(fread(&item,sizeof(struct ITEM),1,fp1)){
		if(item.id==uniqueId){
			matched=1;			
			break;
		}
	}
	if(matched==0){
		print("uniqueId not found Try Again !");
		gotoMenu();
	}
	else{
		strcpy(record.itemname,item.name);
		record.price=item.price;
        time(&record.time); 
		fwrite( &record, sizeof(struct record), 1, fp);
		fclose(fp);
		fclose(fp1);
		notice("Record added succesfully.");
    	gotoMenu();
		
	}
	
    
}

void listitem(){
	clr();
	asciiArt();
	notice("Items Sold");
	FILE *fp1=fopen("D:\\record.txt", "r");
	printf("\n Name.\t\tPrice.\t\tDate\n");
	while(fread(&record,sizeof(struct record),1,fp1)){		
     printf("%s\t\t%d",record.itemname,record.price);
	 printf("\t\t%s\n", ctime(&record.time));
}
	fclose(fp1);
	gotoMenu();

}



//to edit items
void edititem(){
	clr();
	asciiArt();
	notice("EDIT ITEMS");
	char newn[100];
	print("Enter the name of item to edit : ");
	fflush(stdin);
	gets(newn);
	fflush(stdin);
	FILE *fp1=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(struct ITEM),1,fp1)){
		if(strcmp(item.name,newn)==0){
			struct ITEM i=item;
			notice("Item Details ");
			printf("\t\t\tName : %s ",item.name);
		    printf("\t\t\tQuantity : %d\n",item.quantity); 
			printf("\t\t\tRate : %d \n\n",item.price);
			print("Enter new name : ");
			gets(item.name);
			print("\n\t\t\tEnter new quantity : ");
			scanf("%d",&item.quantity);
			printf("\n\t\t\tEnter new price : ");
			scanf("%d",&item.price);
			fwrite(&item,sizeof(struct ITEM),1,fp1);
			fclose(fp1);
			update(item,i);
		}
	}
	printf("\n\t\t\tThe item does not exists");
	gotoMenu();

}

void deleteitem(struct ITEM i){
	fclose(fp);
	FILE *fp5=fopen("D:\\project.txt","r");
	FILE *fp6=fopen("D:\\project1.txt","w");
	while(fread(&item,sizeof(struct ITEM),1,fp5)){
		if(strcmp(item.name,i.name)!=0&&i.price!=item.price&&item.quantity!=i.quantity){
			fwrite(&item,sizeof(struct ITEM),1,fp6);
		}
	}
	fclose(fp5);
	fclose(fp6);
    fflush(stdin);	
	fp5=fopen("D:\\project.txt","w");
	fp6=fopen("D:\\project1.txt","r");
	while(fread(&item,sizeof(struct ITEM),1,fp6)){
			fwrite(&item,sizeof(struct ITEM),1,fp5);
	}
	fclose(fp5);
	fclose(fp6);
	gotoMenu();	

}

void update(struct ITEM itemm,struct ITEM i){
	fclose(fp);
	FILE *fp5=fopen("D:\\project.txt","r");
	FILE *fp6=fopen("D:\\project1.txt","w");
	while(fread(&item,sizeof(struct ITEM),1,fp5)){
		if(strcmp(item.name,i.name)!=0&&i.price!=item.price&&item.quantity!=i.quantity){
			fwrite(&item,sizeof(struct ITEM),1,fp6);
		}
	}
	fwrite(&itemm,sizeof(struct ITEM),1,fp6);
	fclose(fp5);
	fclose(fp6);
    fflush(stdin);	
	fp5=fopen("D:\\project.txt","w");
	fp6=fopen("D:\\project1.txt","r");
	while(fread(&item,sizeof(struct ITEM),1,fp6)){
			fwrite(&item,sizeof(struct ITEM),1,fp5);
	}
	fclose(fp5);
	fclose(fp6);
	

	gotoMenu();	
	
}

void search(){
		clr();
	asciiArt();
	notice("SEARCH ITEM");
	char newn[100];
	print("Enter the name of item to search : ");
	fflush(stdin);
	gets(newn);
	FILE *fp1=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(struct ITEM),1,fp1)){
		if(strcmp(item.name,newn)==0){
			notice("Item Details ");
			printf("\t\t\tName : %s ",item.name);
		    printf("\t\t\tQuantity : %d\n",item.quantity); 
			printf("\t\t\tRate : %d \n\n",item.price);
		    fclose(fp1);
		   	gotoMenu();	
		}
	}
	printf("\n\t\t\tThe item does not exists");
	gotoMenu();
	
}


// to display items
void display(){
  clr();
  asciiArt();
  notice("DISPLAYING ITEMS");
  printf("Items are :\n");
	printf("ItemNo.\t Name.\t Quantity.\tPrice.\tUniqueId.\n");
	int i=1;
	fp=fopen("D:\\project.txt", "r");
	while(fread(&item,sizeof(item),1,fp)!=NULL){
		printf("\n%d",i);
		printf("\t%s",item.name);
		printf("\t\t   %d",item.quantity);
		printf("\t%d\t",item.price);
		printf("%d\n",item.id);
		i++;
	}
	if(i==1){
	 clr();
	 notice("\n\n\n\nNo Item Found !");	
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
    gets(item.name);
    print("Enter the price : ");
    scanf("%d", & item.price);
    print("Enter the quantity : ");
    scanf("%d", & item.quantity);
    item.id=rand();
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
