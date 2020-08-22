#include<stdio.h>
#include<stdlib.h>
struct stack
{
    /*
    top: indicates the top of the stack
    capacity: indicates the capacity of the stack
    array: integer pointer to the stack 
    */
    
    int top;
    int capacity;
    int *array;
};

struct stack *createstack(int cap)
{
   /*
    Initiates a struct stack with capacity=cap
    Returns the address of the structure 
   */

   struct stack *s;
   s=malloc(sizeof(struct stack));
   s->capacity=cap;
   s->top=-1;
   s->array=malloc(sizeof(int)*(s->capacity));
   return(s);
}

int isfull(struct stack *s)
{
    /*
    Checks whether stack is full
    */
    
    if(s->top==s->capacity-1)
        return(1);
    else
        return(0);
}

int isempty(struct stack *s)
{
    
    /*
    Checks whether stack is empty
    */
    if(s->top==-1)
        return(1);
        else
        return(0);
}
void push(struct stack *s,int item)
{
    
    /*
    Inserts a new element into the stack
    */

    if(!isfull(s))
    {
        s->top++;
        s->array[s->top]=item;
    }
}
int pop(struct stack *s)
{
    /*
    Removes element from the stack
    */

    int item;
    if(!isempty(s))
    {
        item=s->array[s->top];
        s->top=s->top-1;
        return(item);
    }
}

void delete_stack(struct stack *stack)
{   
    /*
    Deallocates the space
    */

    free(stack->array);
    stack->top=-1;
}

int main()
{
    int item;
    struct stack *s;
    s=createstack(5);
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,50);


    item=pop(s);
    printf("The popped value is %d",item);

    delete_stack(s);
}
