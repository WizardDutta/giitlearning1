#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL;


void creation()
{
    head = (node*)malloc(sizeof(node));
    printf("Enter the data you want to initiate the list with: ");
    scanf("%d",&head->data);
    head->next=head;
}
void display()
{
    node *trav=head;
    printf("head");
    do
    {
        printf("->%d",trav->data);
        trav=trav->next;
    } while (trav!=head);
    
    printf("\n");
}
node* searchByElement(int x)
{
    node *trav=head;
    do
    {
        if(trav->data==x)
            return trav;
        trav=trav->next;
    } while (trav!=head);
    printf("Element not available\n");
    return NULL;    
}
node* searchByPos(int pos)
{
    node *trav=head;
    int i=1;
    do
    {
        if(i==pos)
            return trav;
        trav=trav->next;
        i++;
    } while (trav!=head);
    printf("Invalid position\n");
    return NULL;
}
void insertAfter()
{
    int x;
    printf("Enter Element after which insertion happens: ");
    scanf("%d",&x);

    node *newnode = (node*)malloc(sizeof(node));
    printf("Enter data in the new node\n->");
    scanf("%d",&newnode->data);
    node *temp = searchByElement(x);

    newnode->next=temp->next;
    temp->next=newnode;
}
void insertBefore()
{
    int x,y;
    printf("Enter Element before which insertion happens : ");
    scanf("%d",&x);

    node* newnode = (node*)malloc(sizeof(node));
    printf("Enter data in the new node\n->");
    scanf("%d",&y);

    node *temp = searchByElement(x);
    newnode->data = temp->data;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->data = y;
}
void insertByPosition()
{
    int pos,x;
    printf("Enter position where the element is to be inserted:\n-> ");
    scanf("%d",&pos);
    printf("Enter data:\n-> ");
    scanf("%d",&x);

    node *temp = searchByPos(pos);
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = temp->data;
    newnode->next = temp->next;
    temp->next = newnode;
    temp->data = x;
}
void deleteByElement()
{
    int ele;
    printf("Enter element to be deleted\n->");
    scanf("%d",&ele);
    node *temp = searchByElement(ele);
    if(temp==head && temp->next==head) //only  one node
    {
        free(head);
        head=NULL;
    }
    else{
        node *ptr = temp->next;
        temp->data=ptr->data;
        temp->next=ptr->next;
        free(ptr);
    }
}
void deleteByPos()
{
    int pos;
    printf("Enter position to be deleted:->");
    scanf("%d",&pos);
    node *temp = searchByPos(pos);
    if(temp==head && temp->next==head) //only  one node
    {
        free(head);
        head=NULL;
    }
    else{
        node *ptr = temp->next;
        temp->data=ptr->data;
        temp->next=ptr->next;
        free(ptr);
    }
}
void append()
{
    int ele;
    printf("Enter element to be appended:\n->");
    scanf("%d",&ele);

    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = head->data;
    newnode->next = head->next;
    head->data = ele;
    head->next = newnode;
    head = newnode;
}
void menu()
{
   int flag=1;
   while(flag)  
   {
    printf("Choose from the following:\n");
    printf("0. To create a linked list\n");
    printf("1. To display list:\n");
    printf("2. To insert element after a node\n");
    printf("3. To insert element before a node\n");
    printf("4. To insert element at a given position\n");
    printf("5. To delete a given element\n");
    printf("6. To delete by a given position\n");
    printf("7. Append\n->>");
    int x;
    scanf("%d",&x);
    switch (x)
    {
        case 0:
            creation();
            break;
        case 1:
            display();
            break;
        case 2:
            insertAfter();
            break;
        case 3:
            insertBefore();
            break;
        case 4:
            insertByPosition();
            break;
        case 5:
            deleteByElement();
            break;
        case 6:
            deleteByPos();
            break;
        case 7:
            append();
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