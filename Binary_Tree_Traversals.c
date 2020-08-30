#include<stdio.h>
#include<stdlib.h>
#define max 10
struct binarytree
{
    /*
    struct binarytree holds data,
    left is a pointer to LEFT CHILD,
    right is a pointer to RIGHT CHILD
    */

    int data;
    struct binarytree *left;
    struct binarytree *right;
};

struct queue
{
    /* 
    struct queue holds front ,rear ,
    qarray is a double pointer of type struct binarytree to hold node
    */

    int front;
    int rear;
    struct binarytree **qarray;
};

struct queue *createqueue()
{
    /*
    Creates a queue
    */
    struct queue *Q;
    Q=(struct queue *)malloc(sizeof(struct queue));
    Q->front=-1;
    Q->rear=-1;
    Q->qarray=(struct binarytree **)malloc(10*sizeof(struct binarytree));
    return Q;
}


int isempty(struct queue *Q)
{
    /*
    Checks whether the queue is empty
    */
	if(Q->front==-1)
        return 1;
	else
        return 0;
}


int isfull(struct queue *Q)
{
    /*
    Checks whether the queue is full
    */
	if((Q->front==0 && Q->rear==max-1)|| Q->front==Q->rear+1)
        return 1;
    else
        return 0;
}


void enqueue(struct queue *Q,struct binarytree *root)
{
    /*
    Inserts a tree node into the queue
    */
    if(isfull(Q))
        printf("Overflow");
    else
    {
        if(isempty(Q))
            Q->front=0;

        Q->rear=Q->rear+1;
        Q->qarray[Q->rear]=root;
    }
}


void dequeue(struct queue *queue)
{
    /*
    Deletes a tree node from the queue
    */
    if(isfull(queue)==1)
        return;
	if(queue->front==queue->rear)
        queue->front=queue->rear=-1;
    else
        queue->front=queue->front+1;
}
	

struct binarytree* createnode(int value)
{
    /*
    Create a binarytree
    */
	struct binarytree* newnode;
    newnode=(struct binarytree *)malloc(sizeof(struct binarytree));   
	
    newnode->data=value;
	newnode->left=NULL;
	newnode->right=NULL;
	return(newnode);
}
   

void preorder(struct binarytree *root)
{
    /*
    Recursive function for preorder traversal of a binarytree
    */
    if(root!=NULL)
    {
        printf("%d  ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void inorder(struct binarytree *root)
{
    /*
    Recursive function for inorder traversal of a binarytree
    */
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);
    }
}


void postorder(struct binarytree *root)
{
    /*
    Recursive function for postorder traversal of a binarytree
    */
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d  ",root->data);
    }
}


void levelorder(struct queue *queue,struct binarytree *root)
{
    /*
    Function for level order traversal of a binarytree
    */

	if(root==NULL)
        return;
	
    enqueue(queue,root);  /*Enqueues root of the tree*/
	
    while(!isempty(queue))
	
    {
		struct binarytree *temp=queue->qarray[queue->front];
		
        dequeue(queue);                                 /*Deque from the queue*/
		printf("%d  ",temp->data);
		
        if(temp->left!=NULL)                            /*Enqueues nodes level by level*/
		     enqueue(queue,temp->left);
		if(temp->right!=NULL)
		     enqueue(queue,temp->right);
	}
}

int main()
{
    

	struct binarytree *root=createnode(1);         /* Creating a Binary Tree*/
	root->left=createnode(2);
	root->left->left=createnode(4);
	root->left->right=createnode(5);
	root->right=createnode(3);
	root->right->right=createnode(6);
	
	
	printf("PREORDER: "); preorder(root);printf("\n");            
	printf("INORDER: "); inorder(root);printf("\n");
	printf("POSTORDER: "); postorder(root);printf("\n");


    struct queue *Q;    /* Queue needed for Level Order Traversal*/
    Q=createqueue();
    printf("LEVEL ORDER: ");
    levelorder(Q,root);
    printf("\n");

}
