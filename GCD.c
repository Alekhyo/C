#include<stdio.h>
int main()
{
    int num1,num2;
    printf("Enter the first number: ");
    scanf("%d",&num1);
    
    printf("Enter the second number: ");
    scanf("%d",&num2);
    
    while(num2>0)
    	{
        	int r=(num1%num2);
        	num1=num2;
        	num2=r;
    	}
    	
	printf("The GCD is %d",num1);
}
