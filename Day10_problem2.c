
// EVALUATION OF POSTFIX FOR SINGLE AND MULTI-DIGIT NUMBERS
// BY SRINJAN DUTTA

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#define INVALID INT_MIN
#define M 30

typedef struct node{
    int data;
    struct node* next;
}node;
node* top = NULL;
void push(int x)
{
    node * ptr = (node*)malloc(sizeof(node));
    if(!ptr)
    {
        printf("\nOverflow Error!");
        return;
    }
    ptr->data = x;
    ptr->next = top;
    top = ptr;
}
int pop()
{
    if(top)
    {
        int x = top->data;
        node * ptr = top;
        top = top->next;
        free(ptr);
        return x;
    }
    else{
        printf("Underflow ERROR!!");
        return INVALID;       
    }
}
void postfix_evaluation()
{
    char postfix[M];
    printf("Enter the postfix expression: ");
    gets(postfix);
    char ch;
    int x,y,i=0,r;
    while (postfix[i])
    {   
        ch = postfix[i];
        r=0;
        switch (ch)
        {
        case '+': y=pop(); x=pop(); push(x+y);
            break;
        case '-': y=pop(); x=pop(); push(x-y);
            break;
        case '*': y=pop(); x=pop(); push(x*y);
            break;
        case '/': y=pop(); x=pop(); push(x/y);
            break;
        case '^': y=pop(); x=pop(); push(pow(x,y));
            break;
        case ' ':
            break;
        default:
            while (postfix[i]>='0' && postfix[i]<='9')
            {
                ch = postfix[i];
                r = r*10 + (ch-'0');
                i++;
            }
            i--; //bcz postfix[i] is not a digit now
            push(r);
            break;
        }
        i++;
    }
    printf("The evaluated answer is: %d",top->data);
}
int main()
{
    postfix_evaluation();
    return 0;
}