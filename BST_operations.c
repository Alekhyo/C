#include<stdio.h>
#include<stdlib.h>
struct BST
{
    /*
    Binary Search Tree structure 
    data contains value
    left is self-referential structure to left subtree
    right is self-referential structure to right subtree 
    */

	int data;
	struct BST *left;
	struct BST *right;
};

struct BST *createnode(int value)
{
    /*
    Creates a new node of BST
    */
    struct BST *newnode;
    newnode=(struct BST *)malloc(sizeof(struct BST));
    
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;

    return newnode;
}

struct BST *insertnode(struct BST *root,int value)
{
    /*
    Recursive function to insert a node in BST
    */
    if(root == NULL)
    {
        root=createnode(value);        
    }
    else if(value<=root->data)
    {
        root->left=insertnode(root->left,value);
    }
    else
    {
        root->right=insertnode(root->right,value);
    }

return root;
}

struct BST *search(struct BST *root,int key)
{
    /*
    Recursive function to find an element in a BST
    */
    if(root!=NULL)
    {
        if(root->data==key)
        {   
            return root;
        }
        else if(key<=root->data)
        {
            search(root->left,key);
        }
        else
        {
            search(root->right,key);
        }
    }
    else
    {
        return NULL;
    }
}

struct BST *findMin(struct BST *root)
{
    /*
    Finds the Minimum element in a BST
    */
    struct BST *temp;
    temp=root;
    while(temp->left!=NULL)
    {
        temp=temp->left;
    }

return temp;
}

struct BST *delete(struct BST *root,int data)
{
    /*
    Deletes an element from the BST
    */
    struct BST *temp;
    
    if(root==NULL)
        return NULL;

    else if (data<root->data)
    {
        root->left=delete(root->left,data);
    }
    else if (data>root->data)
    {
        root->right=delete(root->right,data);
    }
    else
    {
        if(root->left==NULL && root->right==NULL)       /* If the node has no child*/
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL && root->right!=NULL)  /* If the node have a right child */ 
        {
            temp=root;
            root=root->right;
            free(temp);
        }
        else if (root->right==NULL && root->left!=NULL) /*If the node have a left child*/
        {
            temp=root;
            root=root->left;
            free(temp);
        }
        else
        {                                                /*If the node have 2 childs*/
            temp=findMin(root->right);
            root->data=temp->data;
            root->right=delete(root->right,root->data);
        }
    }
return root;
}

void inorder(struct BST *root)
{
    /*Inorder traversal of a BST*/
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d   ",root->data);
        inorder(root->right); 
    }
}


int main()
{
	struct BST *root=NULL;

	root=insertnode(root,12);   /*Insert element into BST*/
    root=insertnode(root,5);    /*Insert element into BST*/
    root=insertnode(root,15);   /*Insert element into BST*/
    root=insertnode(root,3);    /*Insert element into BST*/
	root=insertnode(root,7);    /*Insert element into BST*/
	root=insertnode(root,1);    /*Insert element into BST*/   
    root=insertnode(root,9);    /*Insert element into BST*/
	root=insertnode(root,8);    /*Insert element into BST*/
	root=insertnode(root,11);   /*Insert element into BST*/
    root=insertnode(root,13);   /*Insert element into BST*/
    root=insertnode(root,14);   /*Insert element into BST*/
    root=insertnode(root,17);   /*Insert element into BST*/
    root=insertnode(root,20);   /*Insert element into BST*/
    root=insertnode(root,18);   /*Insert element into BST*/
	
	printf("The Tree is:\n");  /* Print Inorder Traversal of BST */
	inorder(root);
    

    root=delete(root,1);       /* Delete node with value 1 */
    printf("\nThe Tree is:\n");
	inorder(root);
    
}

