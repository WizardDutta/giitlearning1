#include<stdio.h>

int count = 0;
void towerofHanoi(int n,char src,char helper,char dest)
{
    if(n==1)
        printf("%c to %c: Count = %d\n",src,dest,++count);
    else 
    {
        towerofHanoi(n-1,src,dest,helper);
        printf("%c to %c: Count = %d\n",src,dest,++count);
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