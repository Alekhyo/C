#include<stdio.h>
int main()
{
    int y;
    printf("Enter the year :");
    scanf("%d",&y);
    
    if(((y%4==0)&&(y%100!=0))||((y%4==0)&&(y%400==0)))  /* if year is divisible by 4 AND NOT divisible by 100 OR year is divisible by 4 and 400 */ 
    {
        printf("leap year");
    }
    else
    {
    	printf("Not a leap year");
	}
}
