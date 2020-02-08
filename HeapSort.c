#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)      /* Function to swap  */
{
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify(int *arr,int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n && arr[l]>arr[largest])                /* checks if parent element is less than its left child element */
		largest=l;
	
	if(r<n && arr[r]>arr[largest])				 /* checks if parent element is less than its  right child element */
		largest=r;
	
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);			/* swaps if parent element is less than its child element */
		heapify(arr,n,largest);          		/* heapifies further using recursion */
	}
}

void heapsort(int *arr,int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)						/* heapifies only parent elements */
		heapify(arr,n,i);
	
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);                 /* swaps root element with last element */
		heapify(arr,i,0);                     /* heapifies (size-i) of array*/
	}
}

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    
    int *arr = (int*)malloc(size * sizeof(int));  /* Dynamic Array Declaration */
    int i;
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    heapsort(arr,size);                     /* Calling heapsort function */
    
    printf("Sorted Array is: ");
	for(i=0;i<size;i++)							/* Print Sorted Array */
    {
        printf("%d ",arr[i]);
    }
}
