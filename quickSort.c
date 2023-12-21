#include<stdio.h>
#define M 9

int partition2(int* arr,int beg, int end);
int partition(int *arr, int beg, int end)
{
    int i=beg, j=end+1, pivot = arr[beg];
    while (i<j)
    {
        do
        {
            i++;
        } while (arr[i]<pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);
        if(i<j)
            arr[i] = arr[i]+arr[j]-(arr[j]=arr[i]);
    }
    arr[beg] = arr[j];
    arr[j] = pivot;
    return j; // index of the pivot element
}
void quickSort(int* arr, int beg,int end)
{
    if(beg<end)
    {
        int p = partition(arr, beg, end);
        quickSort(arr, beg, p-1);
        quickSort(arr, p+1, end);
    }
}
int partition2(int* arr,int beg, int end)
{
    int mid = (beg+end)/2;
    int i=beg, j=end, pivot = arr[mid];
    while (i<j)
    {
        while (arr[i]<pivot)
            i++;
        while (arr[j]>pivot)
            j--;
        if(i<j)
            arr[i] = arr[i]+arr[j]-(arr[j]=arr[i]);
    }
    return i;
}
int main()
{
    int arr[M] = {75,13,13,5,99,56,3,17,78};
    printf("Now printing the array\n");
    quickSort(arr,0,M-1);
    int i;
    for(i=0;i<M;i++)
        printf("%d ",arr[i]);
    return 0;
}