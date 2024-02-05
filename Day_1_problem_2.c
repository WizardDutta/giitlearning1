#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isprime(int n)
{
    if(n<=1)
        return 0;
    int i;
    if(n%2==0 && 4<=n)
        return 0;
    for(i=3;i*i<=n;i+=2)
        if(n%i==0)
            return 0;
    return 1;
}
int power(int base,int ex) //this takes a T.C: O(log(ex))
{
    if(ex==0)
        return 1;
    int ans = power(base,ex>>1);
    if(ex&1) //if odd power
        return base*ans*ans;
    return ans*ans;
}
bool isarmstrong(int n)
{
    int num = n,dig=0;
    while(num)
    {
        dig++; //1. we have to calculate number of digits
        num/=10;
    }
    num=n;
    int rem=0;
    while(num)
    {
        rem += power(num%10,dig);
        num /= 10;
    }
    if(n==rem)
        return 1;
    return 0;
}
void menu()
{
    int choice;
    while(true)
    {
        printf("Enter any of the choices from 1 to 4\n");
        printf("1. To check prime or not\n");
        printf("2. To check armstrong number or not\n");
        printf("3. To find the largest number among 3 integers\n");
        printf("4. Exit\n");
        scanf("%d",&choice);
        int n;
        int a,b,c;
        switch (choice)
        {
            case 1:
                printf("Enter an integer: ");
                scanf("%d",&n);
                printf("%s\n",isprime(n)?"yes":"no");
                break;
            case 2:
                printf("Enter an integer: ");
                scanf("%d",&n);
                printf("%s\n",isarmstrong(n)?"yes":"no");
                break;
            case 3:
                printf("Enter 3 integers: ");
                scanf("%d%d%d",&a,&b,&c);
                if(a>=b)
                {
                    if(a>=c)
                        printf("%d\n",a);
                    else
                        printf("%d\n",c);
                }
                else{
                    if(b>=c)
                        printf("%d\n",b);
                    else    
                        printf("%d\n",c);
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice!!!!!!\n");
        }
    }
}
int main()
{
  menu();
  return 0;
}