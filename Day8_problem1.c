/*
Day8 problems
*/



#include<stdio.h>
#include<stdlib.h>


typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}node;
node *head; //global variable containing address of the first node

node* search(int x)
{
    node *temp=head;
    while(temp)
    {
        if(temp->data==x)
        return temp;
        temp=temp->next;
    }
    return temp; //returns null
}

void createDll()
{
    head=NULL;

    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);

    head=ptr;
    ptr->next=NULL;
    ptr->prev=NULL;
}
void insertAfter()
{
    int x;
    printf("Enter Element after : ");
    scanf("%d",&x);
    node *temp=search(x);

    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);

    if(!temp->next)
    {
        ptr->prev=temp;
        temp->next=ptr;
        ptr->next=NULL;
    }
    else 
    {
        ptr->next=temp->next;
        temp->next->prev=ptr;
        ptr->prev=temp;
        temp->next=ptr;
    }
}
void insertBefore()
{
    int x;
    printf("Enter Element before : ");
    scanf("%d",&x);
    node *temp=search(x);
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);
     
    if(temp==head)
    {
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
    else 
    {
        ptr->next=temp;
        temp->prev->next=ptr;
        ptr->prev=temp->prev;
        temp->prev=ptr;
    }
}
void insertByPos()
{
    node *temp=head;
    int ps;
    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);
     
    printf("\nEnter position : ");
    scanf("%d",&ps);

    for(int i=1;i<ps;i++)
    temp=temp->next; //finding node at the given position

    if(temp==head) //if the first node, then head should point to the new node
    {
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
    else 
    {
        ptr->next=temp;
        temp->prev->next=ptr;
        ptr->prev=temp->prev;
        temp->prev=ptr;
    }
}
void display()
{
    node *temp=head;
    while(temp)
    {
       printf("%d ",temp->data);
       temp=temp->next;
    }
}
void displayRecursive(node *temp)
{
    if(!temp)
    return;
    printf("%d ",temp->data);
    displayRecursive(temp->next);
}
void deleteByElement()
{
    int x;
    printf("Enter element to be deleted : ");
    scanf("%d",&x);
    node *temp=search(x);
    if(!temp)
    {
        printf("No such element to delete");
        return;
    }
    if(temp==head)
    {
        head=head->next;
        head->prev=NULL;
        free(temp);   
    }
    else if(!temp->next)
    {
        temp->prev->next=NULL;
        free(temp);
    }
    else 
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}
void append() //To insert at the end of linked list
{
    int x;
    node *temp=head;
    while(temp->next)
       temp=temp->next;

    node *ptr=(node*)malloc(sizeof(node));
    printf("\nInput new element : ");
    scanf("%d",&ptr->data);

    if(head==NULL)
    {
        head=ptr;
        ptr->next=NULL;
        ptr->prev=NULL;
    }
    else 
    {
        ptr->prev=temp;
        temp->next=ptr;
        ptr->next=NULL;
    }
}
void deleteByPos()
{
    int ps;
    printf("\nEnter position : ");
    scanf("%d",&ps);
    node* temp=head;

    for(int i=1;i<ps;i++)
        temp=temp->next;

    if(temp==head)
    {
        head=head->next;
        head->prev=NULL;
        free(temp);   
    }
    else if(!temp->next)
    {
        temp->prev->next=NULL;
        free(temp);
    }
    else 
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
}
void reverseprint()
{
    node*temp=head;
    while(temp->next)
        temp=temp->next;
    printf("Linked list printed in reverse order:\n");
    while (temp)    
    {
        printf("%d ",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}

void reverseDLL() 
{
    node *temp,*ptr;
    while (head->next)
        head=head->next; //head is pointing to the last node now
    temp=head,ptr=head->prev;
    node* swap;
    while (ptr) //code to swap the nodes pointed by prev and next
    {
        ptr = temp->prev;
        swap = temp->next;
        temp->next=temp->prev;
        temp->prev=swap;
        temp=ptr;
    }
}
void menu()
{
   int flag=1;
   while(flag)  
   {
    printf("Choose from the following:\n");
    printf("0. Create DLL\n");
    printf("1. To display list:\n");
    printf("2. To display using recursive function\n");
    printf("3. To reverse print\n");
    printf("4. To insert element after a node\n");
    printf("5. To insert element before a node\n");
    printf("6. To insert element at a given position\n");
    printf("7. To delete a given element\n");
    printf("8. To delete by a given position\n");
    printf("9. To reverse a linked list\n");
    printf("10. Append\n->>");
    int x;
    scanf("%d",&x);
    switch (x)
    {
    case 0:
        createDll();
        break;
    case 1:
        display();
        break;
    case 2:
        displayRecursive(head);
        printf("\n");
        break;
    case 3:
        reverseprint();
        break;
    case 4:
        insertAfter();
        break;
    case 5:
        insertBefore();
        break;
    case 6:
        insertByPos();
        break;
    case 7:
        deleteByElement();
        break;
    case 8:
        deleteByPos();
        break;
    case 9:
        reverseDLL();
        break;
    case 10:
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