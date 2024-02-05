#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define is_full 0
#define invalid -1
typedef struct Heap
{
    int capacity;
    int *ptr;
    int lastindex;
}heap;
void init(heap *h)
{
    h->ptr=NULL;
    h->lastindex=-1;
}
void create_Heap(heap *h, int size)
{   

    if(h->ptr!=NULL)
    free(h->ptr);
    h->capacity=size;
    h->ptr=(int*)malloc(sizeof(int)*(h->capacity));
}
int get_last_idx(heap *h)
{
    return h->lastindex;
}
bool isfull(heap *h)
{
    return h->lastindex==h->capacity-1;
}
void del(heap *h)
{
    h->lastindex--;
}
void Heap_sort(int a[],int lst_idx)
{    
    if(lst_idx==0)
    return;
    a[lst_idx]=a[0]+a[lst_idx]-(a[0]=a[lst_idx]);
    int i=0,max=i;
    while((2*i+2<=lst_idx-1)&&(a[i]<a[2*i+1]||a[i]<a[2*i+2]))
    {
        int l=2*i+1;
        int k=l+1;
        if(a[l]>a[k])
        {
            a[i]=a[l]+a[i]-(a[l]=a[i]);
            i=l;
        }
        else 
        {
            a[i]=a[k]+a[i]-(a[k]=a[i]);
            i=k;
        }
    }
    int u=2*i+1;
    if(u<=lst_idx-1&&a[u]>a[i])
    {
        a[u]=a[i]+a[u]-(a[i]=a[u]);
    }
    Heap_sort(a,lst_idx-1);
}
void insert(heap *h, int idx,int data)
{
     if(isfull(h))
     return;
     else if(idx>=h->capacity||idx<0)
     return         ;
     int i=h->lastindex;
     while(i>=idx)
     {   
         h->ptr[i+1]=h->ptr[i];
         i--;
     }
     h->ptr[idx]=data;
     h->lastindex++;
    for(int i=1;i<=h->lastindex;i++)
    {   
        int k=i;
        while((h->ptr[(k-1)/2]<h->ptr[k])&&(k>=0))
        {
            int l=(k-1)/2;
            h->ptr[l]=h->ptr[k]+h->ptr[l]-(h->ptr[k]=h->ptr[l]);
            k=(k-1)/2;
        }
    }
}
void showdata(heap *h)
{
    for(int i=0;i<=h->lastindex;i++)
    printf("%d ",h->ptr[i]);
    printf("\n");
}
void deleteHeap(heap *h)
{
    free(h->ptr);
}
void inorder(heap *h,int idx)
{
    if(idx<h->capacity)
    {
        inorder(h,2*idx+1);
        printf("%d ",h->ptr[idx]);
        inorder(h,2*idx+2);
    }
}
void preorder(heap *h,int idx)
{
    if(idx<h->capacity)
    {
        printf("%d ",h->ptr[idx]);
        preorder(h,2*idx+1);
        preorder(h,2*idx+2);
    }
}
void postorder(heap *h,int idx)
{
    if(idx<h->capacity)
    {
        postorder(h,2*idx+1);
        postorder(h,2*idx+2);
        printf("%d ",h->ptr[idx]);
    }
}
void display(heap *h)
{
    for(int i=0;i<h->lastindex;i++)
    printf("%d ",h->ptr[i]);
    printf("\n");
}
void menu()
{
    heap* h = (heap*)malloc(sizeof(heap));
    int n;
    init(h);
    printf("Enter the size of the heap : ");
    scanf("%d",&n);
    create_Heap(h,n);
    bool flag=true;
    int idx=0;
    int data;
    while(flag)
    {
        printf("\n1. Insertion\n");
        printf("2. Inorder Traversal\n");
        printf("3. Post-order Traversal\n");
        printf("4. Pre-order Traversal\n");
        printf("5. Heap Sort\n");
        printf("6. Display original list\n");
        printf("7. Display sorted list\n");
        int x;
        printf("Enter case number : ");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                printf("\nEnter value : ");
                scanf("%d",&data);
                insert(h,idx++,data);
                break;
            case 2:
                inorder(h,0);
                break;
            case 3:
                postorder(h,0);
                break;
            case 4:
                preorder(h,0);
                break;
            case 5:
                Heap_sort(h->ptr,h->lastindex);
                break;
            case 6:
                display(h);
                break;
            case 7:
                Heap_sort(h->ptr,h->lastindex);
                display(h);
                break;
            default:
                break;
        }
        printf("Do you want to continue 1/0 ?\n");
        scanf("%d",&flag);
    }
}
int main()
{   
    menu();
    return 0;
}