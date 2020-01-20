#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int bintodec(int n)
{
    int i=0,sum=0,rem,temp;
    temp=n;
    while(temp!=0)
    {
        rem=temp%10;
        temp=temp/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
return sum;
}

int dectobin(int n)
{
    int i=0;
    int b[10];
    int temp=0;
    temp=n;
    while(temp!=0)
    {
        b[i]=temp%2;
        temp=temp/2;
        i++;
    }
printf("The binary equivalent is: ");
int j;
for(j=i-1;j>=0;j--)
    {
        printf("%d",b[j]);
    }
}

int dectohex(int n)
{
 char b[50];
 int i=0;
 int temp=n;
 while(temp!=0)
 {
     b[i]=temp%16;
     temp=temp/16;
     i++;
 }

 printf("The hexadecimal equivalent is: ");
 int j;
  for(j=i-1;j>=0;j--)
      {
          if(b[j]>=10&&b[j]<=15)
            b[j]=b[j]+55;
          else if(b[j]>=0&&b[j]<=9)
            b[j]=b[j]+48;
      }

  for(j=i-1;j>=0;j--)
      {
          printf("%c",b[j]);
      }

}

int dectooct(int n)
{
    int o[10],i=0,j;
    int temp=n;
    while(temp!=0)
    {
        o[i]=temp%8;
        temp=temp/8;
        i++;

    }

    printf("The octal equivalent is: ");
for(j=i-1;j>=0;j--)
{
    printf("%d",o[j]);
}
}
int octtodec(int n)
{
    int temp,i=0,rem,sum=0;
    temp=n;
    while(temp!=0)
    {
        rem=temp%10;
        sum+=rem*pow(8,i);
        temp=temp/10;
        i++;
    }
    return sum;
}

int hextodec(char num[])
{
    int k=0,i,sum=0;
    for(i=strlen(num)-1;i>=0;i--)
        {
           if(num[i]>='0'&&num[i]<='9')
              sum=sum+(num[i]-48)*pow(16,k);
          else
              sum=sum+(num[i]-55)*pow(16,k);

           k++;
        }
printf("The decimal equivalent is: %d",sum);
}

int main()
{
    int num,choice,ANS=1;

while(ANS==1)
 {
    printf("1. BINARY TO DECIMAL \n");
    printf("2. DECIMAL TO BINARY \n");
    printf("3. OCTAL TO DECIMAL \n");
    printf("4. DECIMAL TO OCTAL \n");
    printf("5. HEXADECIMAL TO DECIMAL \n");
    printf("6. DECIMAL TO HEXADECIMAL \n");

    printf("Enter Choice: \n");
    scanf("%d",&choice);



        switch(choice)
        {
                    case 1:printf("Enter the binary equivalent \n");
                           scanf("%d",&num);
                           printf("The decimal equivalent is: %d",bintodec(num));
                           break;

                    case 2:printf("Enter the decimal equivalent \n");
                           scanf("%d",&num);
                           dectobin(num);
                           break;

                    case 3:printf("Enter the octal equivalent \n");
                           scanf("%d",&num);
                           octtodec(num);
                           break;

                    case 4:printf("Enter the decimal equivalent \n");
                           scanf("%d",&num);
                           dectooct(num);
                           break;

                    case 5:printf("Enter the hexadecimal equivalent \n");
                           scanf("%d",&num);
                           printf("The decimal equivalent is: %d",hextodec(num));
                           break;

                    case 6:printf("Enter the decimal equivalent \n");
                           scanf("%d",&num);
                           dectohex(num);
                           break;

                    default:printf("NO OPERATION");

                    printf("\n \n \n");
        }
        printf("\n \n \n");
        printf("Want to continue: 1 for YES and 2 for NO \n");
        scanf("%d",&ANS);
 }

}

