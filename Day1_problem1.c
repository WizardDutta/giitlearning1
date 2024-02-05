#include<stdio.h>

void fibonacci_for_loop(int n)
{
    int first=0,second=1,i,fib;
    if(n==0)
        printf("%d ",first);
    else{
        printf("%d %d ",first,second);
        for(i=2;i<=n;i++)
        {
            fib = first + second;
            printf("%d ",fib);
            first = second;
            second = fib;
        }
    }
    printf("\n");
}
void fibonacci_while_loop(int n)
{
    int first=0,second=1,fib;
    if(n==0)
        printf("%d ",first);
    else{
        printf("%d %d ",first,second);
        int i=2;
        while(i<=n)
        {
            fib = first + second;
            printf("%d ",fib);
            first = second;
            second = fib;
            i++;
        }
    }
    printf("\n");
    
}
void fibonacci_dowhile_loop(int n)
{
    int first=0,second=1,fib;
    if(n==0)
        printf("%d ",first);
    else
    {
        printf("%d %d ",first,second);
        int i=2;
        if(i<=n)
        {
            do
            {
                fib = first + second;
                printf("%d ",fib);
                first = second;
                second = fib;
                i++;
            }while(i<=n);
        }
    }
    printf("\n");
}
int main()
{
    int n;
    printf("Enter number: ");
    scanf("%d",&n);
    fibonacci_for_loop(n);
    fibonacci_while_loop(n);
    fibonacci_dowhile_loop(n);
    return 0;
}