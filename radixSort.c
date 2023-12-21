#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define S 10
#define M 7


typedef struct node{
    int key;
    struct node* next;
}node;

node* digitArr[S]={NULL};

node* append(node* head, int val)
{
    if(head)
    {
        node* temp = head;
        while(temp->next)
            temp = temp->next;
        node* n = (node*)malloc(sizeof(node));
        n->key = val;
        n->next = NULL;
        temp->next = n;
    }
    else{
        head = (node*)malloc(sizeof(node));
        head->key = val;
        head->next = NULL;
    }
    return head;
}
node* removeHead(node* head)
{
    if(head)
    {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    return NULL;
}
int extractDigit(int num)
{
    int i;
    if(num==0)
        return 1;
    for(i=0;num;i++)
        num /= 10;
    return i;
}
int maxDigitNum(int* arr)
{
    int i,maxDigit=0,digit;
    for(i=0;i<M;i++)
    {
        digit = extractDigit(arr[i]);
        if(digit>maxDigit)
            maxDigit = digit;
    }
    return maxDigit;
}
void radixSort(int* arr)
{
    int util[M], digit=maxDigitNum(arr),i;
    for(i=0;i<digit;i++)
    {
        int j, div=pow(10,i),k;
        for(j=0;j<S;j++)
            digitArr[i] = NULL; //initializing digitArr
        for(j=0;j<M;j++)
            util[j] = (arr[j]/div)%10; //initializing util 
        for(j=0;j<M;j++)
            digitArr[util[j]] = append(digitArr[util[j]], arr[j]);

        for(j=0,k=0;j<S;j++)
        {
            while(digitArr[j])
            {
                arr[k++] = digitArr[j]->key;
                digitArr[j] = removeHead(digitArr[j]);
            }
        }
    }
}
int main()
{
    int arr[M]={105,15,719,615,339,507,506};
    radixSort(arr);
    int i;
    printf("\nPrinting array: \n");
    for(i=0;i<M;i++)
        printf("%d ",arr[i]);
    return 0;
}