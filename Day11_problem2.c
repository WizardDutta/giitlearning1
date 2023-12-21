#include<stdio.h>


void towerofHanoi(int n,char src,char helper,char dest)
{
    if(n==1)
        printf("%c to %c\n",src,dest);
    else 
    {
        towerofHanoi(n-1,src,dest,helper);
        printf("%c to %c\n",src,dest);
        towerofHanoi(n-1,helper,src,dest);
    }
}
int main()
{
    printf("Enter number of boxes: ");
    int n;
    scanf("%d",&n);
    towerofHanoi(n,'S','T','D');
    return 0;
}