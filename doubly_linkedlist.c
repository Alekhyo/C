#include<stdio.h>
#include<stdlib.h>
int length=0;
struct node
{
    /* 
    A structure contains data to hold data, 
    prev pointer of type struct node to hold the addresse of previous node,
    next pointer of type struct node to hold the addresse of next node, 
    */
    int data;
    struct node *prev;
    struct node *next;
};

struct node *createnode()
{
    /*
    Creates a node of type struct node with 
    prev initialised with NULL,
    next initialised with NULL
    */

    struct node *newnode;
    int value;

    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter a value: ");
    scanf("%d",&value);

    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;

    return newnode;
}

struct node *insertfirst(struct node *TOP)
{
    /*
    Inserts a node at the front of the list
    */

    struct node *newnode;
    newnode=createnode();
    length=length+1;        /* Length of the List is incremented */
    

    if(TOP==NULL)
    {
        TOP=newnode;
    }
    else
    {
        TOP->prev=newnode;
        newnode->next=TOP;
        TOP=newnode;
    }

return TOP;
}

struct node *insertmiddle(struct node *TOP)
{
    /*
    
    Inserts an element at a given position
    
    */
    int position;
    printf("\nEnter the position:");
    scanf("%d",&position);

    if (position==0)            /* Invalid Position */
        { 
            printf("Invalid Position.Enter a value between 1 and %d. Try Again: \n",length);
            TOP=insertmiddle(TOP);
        }
    
    else if (position>length)   /* Invalid Position */
        { 
            printf("Invalid Position.Enter a value between 1 and %d. Try Again: \n",length);
            TOP=insertmiddle(TOP);
        }
    
    else
        {
            struct node *current=NULL;

            int i,count=1;
            
            if(TOP==NULL)           /* Inserts element at the front of the list */
                {
                    TOP=insertfirst(TOP);
                }
            else if(position==1)  /* Inserts element at front of the list */
                {
                    TOP=insertfirst(TOP);
                }

            else
                {
                    struct node *newnode;
                    newnode=createnode();
                    
                    current=TOP;

                    while (count<position-1)
                    {
                        current=current->next;
                        count++;
                    }
        
                    newnode->next=current->next;
                    newnode->prev=current->next->prev;

                    current->next->prev=newnode;
                    current->next=newnode;

                    length=length+1;        /* Length of the List is incremented */
                }
    
        }

return (TOP);
}


void displaynode(struct node *TOP)
{
    /*
    Displays the list
    */
    if(TOP==NULL)
    {
        printf("EMPTY LIST");
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

struct node *deletenode(struct node *TOP)
{
    int position;
    int count=0;

    printf("\nEnter the position to be deleted:");
    scanf("%d",&position);

    if (position==0)            /* Invalid Position */
        { 
            printf("Invalid Position.Enter a value between 1 and %d. Try Again: \n",length);
            TOP=deletenode(TOP);
        }
    
    else if (position>length)   /* Invalid Position */
        { 
            printf("Invalid Position.Enter a value between 1 and %d. Try Again: \n",length);
            deletenode(TOP);
        }
    
    else
        {
            if(TOP==NULL)
            {
                printf("Empty List");
            }
            else
            {
                struct node *temp;
                temp=TOP;
                while(count<position-1)
                {
                    temp=temp->next;
                    count=count+1; 
                }

                if(position==1)                 /* First Element is Deleted */
                {
                    TOP=temp->next;
                    temp->next->prev=temp->prev;
                }
                else if(position==length)       /* Last Element is Deleted */
                {
                    temp->prev->next=temp->next;
                }
                else
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
        

                temp->prev=NULL;
                temp->next=NULL;
                free(temp);
        
                length=length-1;            /* Length of the List is decremented */
            }
    }    
return TOP;
}


int main()
{
    
    struct node *START=NULL;
    
    START=insertfirst(START);
    START=insertfirst(START);
    START=insertfirst(START);
    displaynode(START);

    START=insertmiddle(START);
    displaynode(START);

    START=deletenode(START);
    displaynode(START);

}
