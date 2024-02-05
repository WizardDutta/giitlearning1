// INFIX TO POSTFIX CONVERSION


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#define SIZE 30

typedef struct stack_node{
    char data;
    struct stack_node* next;
}stknode;

stknode* top=NULL;

void push(char x)
{
    stknode* n = (stknode*)malloc(sizeof(stknode));
    n->data=x;
    n->next=NULL;
    if(!top)
    {
        top=n;
        return;
    }
    n->next = top;
    top=n;
}
char pop()
{
    if(!top)
    {
        printf("Underflow Error\n");
        return '\0';
    }
    stknode* temp = top;
    top=top->next;
    char x = temp->data;
    free(temp);
    return x;
}
char top_ele()
{
    if(!top)
    {
        printf("Empty stack\n");
        return '\0';
    }
    return top->data;
}
bool isempty()
{
    return top==NULL;
}
int priority(char op)
{
    switch (op)
    {
    case '+':
    case   '-' :
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default: //for left parenthesis
        return 0;
    }
}

void infix_to_postfix()
{
    char infix[SIZE],ch,postfix[SIZE];
    printf("Enter the infix expression with brackets: ");
    scanf("%s",infix);
    int i,j;
    for(i=0,j=0;infix[i];i++)
    {
        ch = infix[i];
        switch (ch)
        {
        case '(':
            push(ch);
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        // case '^':
            while(priority(ch)<=priority(top_ele()))
                postfix[j++] = pop();
            push(ch);
            break;
        case '^':
            // while(priority(ch)<priority(top_ele()))
            //     postfix[j++] = pop();
            push(ch); //for its right associativity property
            break;
        case ')':
            do
            {
                postfix[j++] = pop();
            } while (top_ele()!='(');
            pop(); //popping the '('
            break;
        default: //the operands
            postfix[j++] = ch;
            break;
        }
    }
    postfix[j]='\0';
    puts(postfix);
}
int main()
{
    infix_to_postfix();
    return 0;
}