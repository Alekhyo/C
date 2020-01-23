#include<stdio.h>
#define N 5
int interpolation(int arr[],int size,int num)
{
	int low=0;
	int high=size-1;
	int pos;
	
	while(low<=high&&num>=arr[low]&&num<=arr[high])
	{
		if(low==high)
		{
			if(arr[low]==num);
			    return low;
			return -1;
		}
		
        pos=low+(((double)(high-low)/(arr[high]-arr[low]))*(num-arr[low]));                 /* Interpolation Formula  */
		
		if(arr[pos]==num)
		{
		   return pos;
     	}
		 
		if(num>arr[pos])                                                                  /* Checking the right sub array if number greater than Array[pos] */
		    low=pos+1;
		else
		    high=pos-1;																	  /* Checking the left sub array if number lesser than Array[pos] */
    }
	return -1;
}
int main()
{
	int arr[N],num,i=0,result;
	printf("Enter the elements of the array\n\n");
	for(i=0;i<N;i++)
		scanf("%d",&arr[i]);
	
	printf("Enter the element to be searched:");
	scanf("%d",&num);
	
	result=interpolation(arr,N,num);												     /*Function Call*/
	if(result!=-1)
	  printf("%d is found at position %d",num,result+1);
	else
	 printf("%d is not found",num);
}
