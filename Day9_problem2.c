#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
node *top=NULL;

void push(int x)
{
    node *newnode = (node*)malloc(sizeof(node));
    if(!newnode)
    {
        printf("Overflow Error!\n");
        return;
    }
    newnode->data = x;
    newnode->next=top;
    top=newnode;
}
int pop()
{
    node *ptr;
    if(top)
    {
        ptr=top;
        top=top->next;
        int x = ptr->data;
        free(ptr);
        return x;
    }
    printf("Underflow Error!!!!!!!\n");
    return INT_MIN;
}
void display()
{
    node *temp=top;
    while(temp)
    {
       printf("%d ",temp->data);
       temp=temp->next;
    }
}
void menu()
{
    int flag=1,ele;
   while(flag)  
   {
    printf("Choose from the following:\n");
    printf("1. To display stack:\n");
    printf("2. To push\n");
    printf("3. To pop\n->>");
    int x;
    scanf("%d",&x);
    switch (x)
    {
        case 1:
            display();
            break;
        case 2:
            printf("Enter the element to be pushed\n->>");
            scanf("%d",&ele);
            push(ele);
            break;
        case 3:
            pop();
            break;
        default:
            printf("Sorry! wrong choice\n");
            break;
    }
    printf("\nDo you want to continue 1/0 ?\n");
    scanf("%d",&flag);
   }
}
int main()
{
    menu();
    return 0;
}