/*In this program, we have created a linked list as the data structure to store the records, it is used as a medium to
alter the contents of the file, every time an operation is performed on the linked list(insertion, deletion), the file is 
overwritten as per the data present in the linked list*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct node
{   
   struct node *next;
   char name[50];
   int marks;
}node;

node *last=NULL;

void insert(int data,char name[])
{
    node *t=last;
    if(!last)
    {
        node *n=(node*)malloc(sizeof(node));
        n->marks=data;
        strcpy(n->name,name);
        last=n;
        n->next=n;
        return;
    }
    node *n=(node*)malloc(sizeof(node));
    n->marks=data;
    strcpy(n->name,name);
    n->next=last->next;
    last->next=n;
    last=n; 
}
node* search(char *name,int marks)
{
    node *t=last;
    while(strcmp(t->next->name,name)&&t->next->marks!=marks)
    t=t->next;
    return t;
}
void delete(char *name,int marks)
{
    node *prev=search(name,marks);
    node *curr=prev->next;
    if(curr==last)
    {
        if(last==last->next)   // Single Node
        {
             free(last);
             last=NULL;
             return;
        }
        else 
        {
            prev->next=last->next;
            free(last);
            last=prev;
            return;
        }
    }
    prev->next=curr->next;
    free(curr);
}
void displayFile()
{
    FILE *ptr=fopen("file.txt","w");
    node *t=last->next;
    while(t!=last)
    {
        fprintf(ptr,"%s      %d\n",t->name,t->marks);
        t=t->next;
    }
    fprintf(ptr,"%s      %d\n",t->name,t->marks);
}
void printData()
{
    node *t=last->next;
    while(t!=last)
    {
        printf("Name %s marks %d\n",t->name,t->marks);
        t=t->next;
    }
    printf("Name %s marks %d",t->name,t->marks);
}
void append()
{
    char name[40];
    int marks;
    printf("Name : ");
    scanf("%s",name);
    printf("\nMarks : ");
    scanf("%d",&marks);
    insert(marks,name);
}
void deleteRecord()
{
    char name[40];
    int marks;
    printf("Student's Name : ");
    fgets(name,20,stdin);
    printf("\n Marks : ");
    scanf("%d",&marks);
    delete(name,marks);
}
void updateData()
{
    char name[40];
    int marks;
    int new_marks;
    printf("Enter Name of the student : ");
    fgets(name,40,stdin);
    printf("\nEnter the old marks : ");
    scanf("%d",&marks);
    node *prev=search(name,marks);
    printf("\nEnter new marks of student : ");
    scanf("%d",&new_marks);
    prev->next->marks=new_marks;
}
void menu()
{
    int x;
    do
    {
        printf("1. Append new record of a student\n");
        printf("2. Delete a record of a specific student\n");
        printf("3. Update a field of student\n");
        printf("4. Display All records\n");
        printf("5. Quit\n");

        scanf("%d",&x);
        switch(x)
        {
            case 1:
                append();
                break;
            case 2:
                deleteRecord();
                break;
            case 3:
                updateData();
                break;
            case 4:
                displayFile();  // All new records we can watch in the file;
                break;
            case 5:
                break;
            default:
                printf("Try again\n");
        }
        if(x==5)
            break; //breaks out of the loop
    } while (1);
    
}
int main()
{
  menu();
  return 0;
}