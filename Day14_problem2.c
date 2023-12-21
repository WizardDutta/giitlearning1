#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define M 5

bool isFull(node*);


typedef struct node{
    int key[M];
    struct node *children[M];
    struct node *parent;
}node;

node* create_node(node* root)
{
    root = (node*)malloc(sizeof(node));
    if(root)
    {
        int i;
        for(i=0;i<M;i++)
        {
            root->children[i] = NULL;
            root->key[i] = -1e9;
        }
        root->parent = NULL;
    }
    else{
        printf('OOps! we are out of memory.');
    }
    return root;
}

node* insert(node* root, int data)
{
    node* temp = find_leaf(root,data);
    if(temp)
    {
        
        int i, j;
        for(i=0;i<M;i++)
        {
            if(temp->key[i]>data)
            {
                for(j=M-1;j>i;j--)
                    temp->key[j] = temp->key[j-1];
                temp->key[i] = data;
                break;
            }
        }
        if(isFull(temp))    
        {
            
        }
    }
    else{
        printf("OOPS! This integer already exists.");
    }
    return root;
}
bool isFull(node *temp)
{
    return temp->key[M-1]==-1e9? false : true;
}

node* find_leaf(node* root, int val)
{
    int i;
    if(root->children[0]==NULL) //leaf node found
    {
        for(i=0;i<M;i++)
            if(val==root->key[i])
                return NULL;

        return root;
    }
    for(i=0;i<M;i++)
    {
        if(root->key[i]>val)
            return find_leaf(root->children[i], val);
        if(root->key[i]==-1e9)
            return find_leaf(root->children[i], val);
    }
}

int main()
{
    return 0;
}