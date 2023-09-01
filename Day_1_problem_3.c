#include<stdio.h>


int find_elements(int *arr,int x,int n)
{
    int i;
    for(int i=0;i<n;i++) //performing linear search to return true index of the key
    {
        if(arr[i]==x)
        return i;
    }
    return -1;
}
int main()
{
   int n;
   printf("length of the array: ");
   scanf("%d",&n);
   int a[n];
   printf("Input elements\n");
   int i;
   for(i=0;i<n;i++) //entering elements
   scanf("%d",&a[i]);

   int key; //input the key
   printf("Enter the element to search\n");
   scanf("%d",&key);

   int idx=find_elements(a,key,n);
   if(idx==-1) //final conclusion
   printf("Not found\n");
   else 
   printf("Element found at idx %d",idx);
}