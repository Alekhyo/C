#include<stdio.h>
void swap(int *a,int *b)
{												/* Function to swap  */
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int A[],int start,int end)        /* Function to find the the index of pivot element */
{
    int p_index=start;
    int pivot=A[end];							/* Last element of the array as pivot element */
    for(int i=start;i<=end;i++)
    {
        if(A[i]<pivot)
        {
            swap(&A[i],&A[p_index]);			/* swaps if A[i] less than pivot element */
            p_index++;
        }
    }
    swap(&A[p_index],&A[end]);
return p_index;
}
void quicksort(int A[],int start,int end)		/* Recursive Function */
{
    int pi;
    if(start<end)
    {
             pi=partition(A,start,end);
             quicksort(A,start,pi-1);			/* Recursively call quicksort */
             quicksort(A,pi+1,end);				/* Recursively call quicksort */
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
    
    quicksort(arr,0,size-1);                     /* Calling quicksort function */
    
    printf("Sorted Array is: ");
	for(i=0;i<size;i++)							/* Printing Sorted Array */
    {
        printf("%d ",arr[i]);
    }
}
