#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<stdbool.h>
#define N 4
#define invalid INT_MIN
typedef struct queue
{
    int front;
    int rear;
    int arr[N];
}queue;
void init_static(queue *q)
{
    q->front=0;
    q->rear=-1;
}
void insert_st(queue *q)
{
    int x;
    printf("\nEnter data : ");
    scanf("%d",&x);
    if(q->rear==N-1)
        printf("\nOverflow\n");
    else
        q->arr[++(q->rear)]=x;
}
int delete(queue *q)
{
    if(q->front>q->rear)
    {
        printf("Underflow\n");
        return invalid;
    }
    else 
    {
        int x=q->arr[q->front];
        q->front++;
        return x;
    }
}

void display(queue *q)
{
    printf("front");
    for(int i=q->front;i<=q->rear;i++)
        printf("->%d",q->arr[i]);
    printf("<-rear");
}
void staticMenu()
{
    queue q;
    init_static(&q);
    int x,u;
    bool flag=true;
    while(flag)
    {
        printf("\nEnter operation number : \n");
        printf("1. To insert\n");
        printf("2. To delete\n");
        printf("3. To display\n");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                insert_st(&q);
                break;
            case 2:
                if((u=delete(&q))!=invalid)
                printf("\nDeleted data : %d",u);
                break;
            case 3:
                display(&q);
                break;
            default:
                break;
        }
        printf("\nDo you want to continue ?\n");
        scanf("%d",&flag);
    }
}




//Dynnamic Queue 
 
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct que 
{
    node *front,*rear;
}que;
void initDy(que *q)
{
    q->front=NULL;
    q->rear=NULL;
}
bool empty(que *q)
{
    return q->front==NULL;
}
void insertDy(que *q)
{

    int x;
    printf("\nEnter data : ");
    scanf("%d",&x);
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=NULL;
    if(empty(q))
    {
       q->front=ptr;
       q->rear=ptr;
    }
    else 
    {
       q->rear->next=ptr;
       q->rear=ptr;
    }
}
int deletedy(que *q)
{
    if(q->front)
    {
        node *ptr=q->front;
        int x=ptr->data;
        q->front=q->front->next;
        free(ptr);
        return x;
    }
    else 
    {
        printf("\nUnderflow");
        return invalid;
    }
}
void displaydy(que* q)
{
    printf("\nfront ");
    node* temp = q->front;
    while(temp)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
    printf("<-rear");
}

void dynammicMenu()
{
    que q;
    initDy(&q);
    int x,u;
    bool flag=true;
    while(flag)
    {
        printf("\nEnter operation number : \n");
        printf("1. To insert\n");
        printf("2. To delete\n");
        printf("3. To display\n");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                insertDy(&q);
                break;
            case 2:
                if((u=deletedy(&q))!=invalid)
                printf("\nDeleted data : %d",u);
                break;
            case 3:
                displaydy(&q);
                break;
            default:
                break;
        }
        printf("\nDo you want to continue ?\n");
        scanf("%d",&flag);
    }
}
typedef struct cque
{
    int front;
    int rear;
    int arr[N];
}cque;

void initcque(cque *q)
{
    q->front=0;
    q->rear=0;
}
void insertcque(cque *q)
{
    if((q->rear+1)%N==q->front)
    {
        printf("\nQueue is Full");
    }
    else 
    {
        int x;
        printf("\nEnter data : ");
        scanf("%d",&x);
        q->arr[q->rear]=x;
        q->rear=(q->rear+1)%N;
    }
}
int deletecque(cque *q)
{
    if(q->front==q->rear)
    {
        printf("\nUnderflow");
        return invalid;
    }
    int x=q->arr[q->front];
    q->front=(q->front+1)%N;
    printf(" front : %d rear : %d\n",q->front,q->rear);
    return x;
}
void displaycque(cque *q)
{
    printf("front = %d and rear = %d \n",q->front,q->rear);
    printf("\nfront");
    for(int i=q->front;i!=q->rear;i=(i+1)%N)
       printf("->%d",q->arr[i]);
    printf("<-rear");
}
void circularMenu()
{
    cque q;
    initcque(&q);
    bool flag=true;
    int u;
    while(flag)
    {
        int x;
        printf("\nEnter operation number : \n");
        printf("1. To insert\n");
        printf("2. To delete\n");
        printf("3. To display\n");
        scanf("%d",&x);
        switch (x)
        {
            case 1:
                insertcque(&q);
                break;
            case 2:
                if((u=deletecque(&q))!=invalid)
                printf("\nDeleted data : %d",u);
                printf("front = %d and rear = %d \n",q.front,q.rear);
                break;
            case 3:
                displaycque(&q);
                break;
            default:
                break;
        }
        printf("\nDo you want to continue ?\n");
        scanf("%d",&flag);
    }
}
void menu()
{
    int x;
    printf("Enter a number : \n");
    printf("1. For static Q\n");
    printf("2. For dynamic que\n");
    printf("3. For circular q\n");
    scanf("%d",&x);
    switch (x)
    {
        case 1:
            staticMenu();
            break;
        case 2:
            dynammicMenu();
            break;
        case 3:
            circularMenu();
            break;
        default:
            break;
    }
}

int main()
{
  menu();

  return 0;
}