#include <stdio.h>
#include <stdlib.h>

struct inventory
{
    struct inventory *prev;                
    char item_name[50];                  
    int quantity;                         
    int price;                          
    struct inventory *next;                
};
typedef struct inventory inv;
inv *LP=NULL,*temp,*temp1,*temp2,*RP=NULL;   

void create();        
void insert1();      
void display();     
void deletei();    
void savetofile();  
void readfromfile(); 
int count = 0;

void main()
{
    int ch;

  
    printf("\n 1 - Add item to store ");
  
    printf("\n 2 - Delete item at i");
    printf("\n 3 - Display Inventory from beginning");
    printf("\n 4 - Write items into file");
    printf("\n 5 - Read items from file");
    printf("\n 6 - Exit");

    while (1)
    {
	printf("\n Enter choice : ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	     insert1();
	     savetofile();
	    break;

	case 2:
	    deletei();
	    break;
	case 3:
	    display();
	    break;
	case 4:
	     savetofile();
	     break;
	case 5:
	    readfromfile();
	      break;
	case 6:
	    exit(0);
	     break;

	default:
	    printf("\n Wrong choice menu");
	}
    }
   
}


void create()
{


    temp =(inv *)malloc(1*sizeof(inv));
    temp->prev = NULL;
    temp->next = NULL;
  
    printf("\n Enter name of the item : ");
    scanf("%s",temp->item_name);
    printf("\n Enter the quantity : ");
    scanf("%d",temp->quantity);
    printf("\n Enter the price : ");
    scanf("%d",temp->price);
  
    count++;
}


void insert1()
{
    if (LP == NULL)
    {
	create();
	LP = temp;
	temp1 = LP;
    }
    else
    {
	create();
	temp->next = LP;
	LP->prev = temp;
	LP = temp;
	RP=temp;
    }
}



void deletei()
{
    int i = 1, pos;

    printf("\n Enter position to be deleted : ");
    scanf("%d", &pos);
    temp2 = LP;

    if ((pos < 1) || (pos >= count + 1))
    {
	printf("\n Error : Position out of range to delete");
	return;
    }
    if (LP == NULL)
    {
	printf("\n Error : Empty list no elements to delete");
	return;
    }
    else
    {
	while (i < pos)
	{
	    temp2 = temp2->next;
	    i++;
	}
	if (i == 1)
	{
	    if (temp2->next == NULL)
	    {
		printf("Node deleted from list");
		free(temp2);
		temp2 = LP = NULL;
		return;
	    }
	}
	if (temp2->next == NULL)
	{
	    temp2->prev->next = NULL;
	    free(temp2);
	    printf("Node deleted from list");
	    return;
	}
	temp2->next->prev = temp2->prev;
	if (i != 1)
	    temp2->prev->next = temp2->next;   
	if (i == 1)
	    LP = temp2->next;
	printf("\n Node deleted");
	free(temp2);
    }
    count--;
}

void display()
{
     inv *temp2;
     temp2=LP;
     if(temp2==NULL)
      {
	 printf("List is Empty");
      }
     while(temp2!=NULL)
     {

	  printf("\n%s",temp2->item_name);
	  printf("\n%d",temp2->quantity);
	  printf("\n%d",temp2->price);
	
	  temp2=temp2->next;
	  printf("\n------------------------------------\n");
     }
     printf("NULL");
}


void savetofile()
{
    FILE *fp;
    inv *ptr;

    if(LP == NULL)
    {
	printf("Empty.\n");
	return;
    }

    ptr = LP;
    if((fp=fopen("c:\\database.txt", "w+")) == NULL)
    {
	printf("No such file.\n");
	return;
    }
    else
    {
	fwrite(&ptr, sizeof(inv), 1, fp);
	fclose(fp);
	printf("Saved to disk.\n");
	system("PAUSE");
    }
}



void readfromfile()
{

    FILE *fp;
    inv *ptr = malloc(sizeof(*ptr));
    ptr = LP;

    fp=fopen("c:\\database.txt", "r+");

    while(fread(&ptr, sizeof(inv), 1, fp) ==1)
    {
	printf("\nTHE DETAILS WRITTEN INTO THE FILE ARE :\n");
      
	printf("Item name: %s\n", &ptr->item_name);
	printf("Quantity: %d\n",&ptr->quantity);
	printf("Price: %d\n",&ptr->price);
     
	ptr = ptr->next;
    }
	 fclose(fp);
       system("PAUSE");
}
