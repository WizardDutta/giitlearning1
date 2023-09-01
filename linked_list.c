#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}node;
node* head;
void append(int info)
{
    node* trav=head;
    node* n = (node*)malloc(sizeof(node));
    n->data=info;
    n->link=NULL;
    if(!head)
    {
        head = n;
        return;
    }
    while (trav->link)
        trav=trav->link;
    trav->link = n;
}
void reverseList()
{
    node *prev=NULL,*next;
    while (head)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
}
node* searchbefore(int key)
{
    node* trav = head;
    if(trav==NULL)
    {
        printf("Empty!");
        return NULL;
    }
    if(head->data==key)
        return head;
    while(trav->link)
    {
        if(trav->link->data==key)
            return trav;
        trav = trav->link;
    }
    return NULL;
}
void insert(int nodebefore,int info)
{
    node* temp = searchbefore(nodebefore);
    node* ptr = (node*)malloc(sizeof(node));
    ptr->data=info;
    ptr->link=temp->link;
    temp->link=ptr;
}
node* searchByPosition(int pos)
{
    int indx=1;
    node* trav=head;
    while (trav && indx<pos)
    {
        trav=trav->link;
        indx++;
    }
    if(trav) return trav;
    else if(indx==pos)
    {
        // return 
        printf("Position not found\n");
        return NULL;
    }
}
void insertByPosition(int pos,int x)
{
    node* temp = searchByPosition(pos);
    if(!temp)
        return ;
    node *n = (node*)malloc(sizeof(node));
    n->data = temp->data;
    n->link = temp->link;
    temp->link=n;
    temp->data=x;
}
void printlist()
{
    node* trav = head;
    while (trav)
    {
        printf("%d ",trav->data);
        trav = trav->link;
    }
    printf("\n");
}
int main()
{
    head=NULL;
    append(5);
    append(15);
    append(55);
    append(40);
    printlist();
    // insert(5,80);
    // printlist();
    // reverseList();
    // printlist();
    insertByPosition(5,80);
    printlist();
    // insertByPosition(1,80);
    // printlist();
    return 0;
}