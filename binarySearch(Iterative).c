#include<stdio.h>
int binarySearch(int A[],int start,int end,int num)
{
	while(start<=end)
	{
		int mid=(start+end)/2;															/*Finding the middle element */
		
		if(A[mid]==num)																	/*Checking the middle element */
			return mid;		
		
		if(num>A[mid])
			start=mid+1;                                                               /*Checks the right half of the array if number greater than middle element*/
			
		else
			start=mid-1;                                                              /*Checks the left half of the array if number is less than the middle element*/
	}
	
   return -1;
}

int main()
{
    int size,number,i,result;
    
	printf("Size of the array \n");
    scanf("%d",&size);
	int A[size];
   
	for(i=0;i<size;i++)
        {
          printf("Enter the elements of the array \n");
          scanf("%d",&A[i]);
        }

    printf("Enter the number to be found: ");
    scanf("%d",&number);

	result=binarySearch(A,0,size-1,number);         /* Function Call */
	
	if (result==-1)
		printf("Element NOT FOUND\n");
	else
		printf("Element FOUND at position: %d \n",result+1);
}

