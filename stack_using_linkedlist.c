#include<stdio.h>
#include<stdlib.h>

struct node
{
    /* 
    Struct Node contains two elements
    data contains the value
    next contains the address of next node
    */
    int data;
    struct node *next;
};

struct node *push(struct node *TOP)
{
   /* 
    Inserts a element at the front of Linked List
    */ 
   int value;
   struct node *newnode;
   newnode=(struct node *)malloc(sizeof(struct node));
   
   printf("Enter value to be inserted: ");
   scanf("%d",&value);

   newnode->data=value; 
   newnode->next=TOP;
   TOP=newnode;
   
   return(TOP);
}

struct node *pop(struct node *TOP)
{
   /* 
    Removes an element from the front of Linked List
    */ 
   struct node *temp;
   if(TOP==NULL)
   {
       printf("EMPTY STACK");
   }
   else
   {
       temp=TOP;
       printf("The popped item is: %d",temp->data);
       TOP=TOP->next;
       temp->next=NULL;
       free(temp);
   }
   return(TOP);
}

void display_list(struct node *TOP)
{
    /* 
    Display the Linked List
    */
    if(TOP==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while(TOP!=NULL)
        {
            printf("%d  ",TOP->data);
            TOP=TOP->next;
        }
    }
}


void delete_list(struct node *TOP)
{
    /* 
    De-allocates the Linked List
    */
    while (TOP!=NULL)
        {
            struct node *temp;
            
            temp=TOP;
            TOP=TOP->next;
            temp->next=NULL;
            free(temp);            
        }
    
}

int main()
{
    struct node *TOP=NULL;
    TOP=push(TOP);
    TOP=push(TOP);
    TOP=push(TOP);
    TOP=push(TOP);

    TOP=pop(TOP);
    printf(" \n");

    display_list(TOP);



    delete_list(TOP);
    

}