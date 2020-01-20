#include<stdio.h>
void linear_search(int A[],int size_of_array,int number)            /* Function Declaration */
{
	int flag=0;
	int i;
	int pos=0;
	for(i=0;i<size_of_array;i++)     								/* Traversing the array   */
	{
		 if(A[i]==number)
		 {
		 	flag=1;
		 	pos=i+1;												/* If element is found ,break the loop and return the index position */
		 	break; 	
		 }
	}
	
	if(flag==1)
    	printf("Number found at position number %d",pos);           /*Displays the position of the searched number in the array */
	else 
		printf("Number NOT found");								   /* flag =0 means the desired number is not found in the array */
	
}
int main()
{
    int size,num,i;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int A[size];
    for(i=0;i<size;i++)
    {
        printf("Enter the value in array: ");
        scanf("%d",&A[i]);
    }
    
    printf("Enter the value to be searched in array: ");
    scanf("%d",&num);
    

	linear_search(A,size,num);										/* Function calling */

}
