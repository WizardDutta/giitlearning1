#include<stdio.h>


void swap(char* a,char *b)
{
    *a = *a+*b - (*b=*a);
}
int count = 0; //a global variable to record the total number of permutations
void permutation(char *string,int length,int indx)
{
    if(indx==length)
    {
        count++;
        printf("%s\n",string);
        return ;
    }
    for(int i=indx;i<length;i++)
    {
        swap(&string[indx],&string[i]);
        permutation(string,length,indx+1);
        swap(&string[indx],&string[i]); //reswapping the elements to their true positions
    }
}
int main()
{
    int n;
    printf("Enter length: ");
    scanf("%d",&n);
    char p[n];
    printf("Enter string: ");
    scanf("%s",p);
    printf("\n\n\n\n");
    permutation(p,n,0);
    printf("\n\nTotal permutations: %d",count);
    return 0;
}