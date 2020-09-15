#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node
{
   int data;
   struct node * next;
};

struct node * front=NULL;
struct node * rear=NULL;
void display();
void insert(int val);
void delete();
void peep();

int main()
{
   
   while(1)
   {
     int val,ch;
     printf("\n\nMenu:\n1.Insert\n2.Delete\n3.Peep\n4.Display\n5.Exit");
	 printf("\nEnter your choice: ");
	 scanf("%d",&ch);
	 switch(ch)
    {
	   case 1:
	          printf("Enter data: ");
			  scanf("%d",&val);
			  insert(val);
			  break;
	   case 2:
	          delete();
			  break;
	   case 3: peep();break;
	   case 4: display();break;
	   case 5: exit(0);
	    	  
	}
   }
   return 0;
}

void display()
{
  struct node * ptr;
  ptr= front;
  if(ptr==NULL)
  {
     printf("Empty Queue");
  }
  else
  { 
    printf("\nElements in the queue are: ");
    while(ptr!=NULL)
    {
      printf("\t%d",ptr->data);
  	  ptr=ptr->next;
    }
  }
}


void insert(int val)
{
  struct node * newnode;
  newnode=(struct node *)malloc(sizeof(struct node*));
  newnode->data=val;
  newnode->next=NULL;
  if(rear!=NULL)
  {
     rear->next=newnode;
	 rear=newnode;
  }
  else
  {
     rear=front=newnode;     
  }
}

void delete()
{

   struct node * ptr;
   ptr=front;
   if(front==NULL)
      printf("Oueue Empty!!");
   else
   {
   printf("Value deleted from the Queue=%d",front->data);
    if(front==rear)
    {
       front=rear=NULL;  
    }
    else
    {
      front=front->next;
    }
      free(ptr);
   }
}

void peep()
{
  if(front==NULL)
     printf("Queue Empty!!!");
  else
    printf("Element at top=%d",front->data);
}

