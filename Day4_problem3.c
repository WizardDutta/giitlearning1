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
node* search(char *name)
{
    node *t=last;
    while(strcmp(t->next->name,name))
    t=t->next;
    return t;
}
void searchRecord()
{
    char name[40];
    int marks;
    printf("Enter Name: ");
    scanf("%s",name);
    node *prev=search(name);
    printf("\nData Found \nName : %s      Marks: %d\n",prev->next->name,prev->next->marks);
}
void delete(char *name)
{
    node *prev=search(name);
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
void printFile()
{
    FILE *ptr=fopen("records.csv","w");
    node *t=last->next;
    while(t!=last)
    {
        fprintf(ptr,"%s,%d\n",t->name,t->marks);
        t=t->next;
    }
    fprintf(ptr,"%s,%d\n",t->name,t->marks);
}
void printData()
{
    node *t=last->next;
    while(t!=last)
    {
        printf("Name :%s       marks :  %d\n",t->name,t->marks);
        t=t->next;
    }
    printf("Name : %s          marks : %d\n",t->name,t->marks);
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
    scanf("%s",name);
    delete(name);
}
void updateData()
{
    char name[40];
    int marks;
    int new_marks;
    printf("Enter Name of the student : ");
    scanf("%s",name);
    node *prev=search(name);
    printf("\nEnter new marks of student : ");
    scanf("%d",&new_marks);
    prev->next->marks=new_marks;
}
void menu()
{
    int x;
    while(1)
    {
        printf("1. Append new record of a student\n");
        printf("2. Delete a record of a specific student\n");
        printf("3. Update a field of student\n");
        printf("4. Display All records\n");
        printf("5. Search records\n");
        printf("6. Exit\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                append();
                printFile();
                break;
            case 2:
                deleteRecord();
                printFile();
                break;
            case 3:
                updateData();
                printFile();
                break;
            case 4:
                printData();  // All new records we can watch in the file;
                break;
            case 5:
                searchRecord();
                break;
            case 6:
                exit(0);
        }
    }
}
int main()
{
  menu();
  printFile();
  return 0;
}