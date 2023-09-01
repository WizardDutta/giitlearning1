#include<stdio.h>

int length(char *s)
{
    int i;
    for(i=0;s[i];i++);
    return i;
}
void reverse(char *s)
{
    int l = length(s);
    int i;
    for(i=0;i<l/2;i++)
        s[i] = s[i]+s[l-1-i] -(s[l-1-i]=s[i]); //swapping ith and (l-1-i)th element
}
int main()
{
    
    char str[100]; 
    printf("Enter string: ");
    scanf("%s",str);
    printf("length = %d",length(str));
    reverse(str);
    printf("\nreverse string is : %s",str);
  return 0;
}