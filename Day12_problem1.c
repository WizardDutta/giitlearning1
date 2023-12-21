#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
node *root; //taking root as global variable
void creation()
{
    int x;
    printf("Enter data to initialize the root:\n->> ");
    scanf("%d",&x);
    root = (node*)malloc(sizeof(node));
    root->data = x;
    root->left = root->right = NULL;
}
void insert()
{
    int x;
    printf("Enter data to be inserted:\n->> ");
    scanf("%d",&x);
    node *newnode = (node*)malloc(sizeof(node));
    newnode->data = x;
    newnode->left = newnode->right = NULL;

    node* temp = root;
    while (true)
    {
        if(x > temp->data)
        {
            if(temp->right)
                temp = temp->right;
            else {
                temp->right = newnode;
                return;
            }
        }
        else if(x < temp->data)
        {
            if(temp->left)
                temp = temp->left;
            else {
                temp->left = newnode;
                return;
            }
        }
    }
}
void printInorder(node*root)
{
    if(root)
    {
        printInorder(root->left);
        printf("%d ",root->data);
        printInorder(root->right);
    }
}
void printPreorder(node *root)
{
    if(root)
    {
        printf("%d ",root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}
void printPostorder(node *root)
{
    if(root)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf("%d ",root->data);
    }
}
bool search(node *root,const int key)
{
    if(root)
    {
        if(root->data==key)
            return true;
        else if(root->data>key)
            return search(root->left,key);
        else return search(root->right,key);
    }
    else
        return false;
}
node* find_inorder_successor(node* temp)
{
    while (temp->left)
        temp = temp->left;
    return temp;    
}
node* deleteNode(node* root, int key)
{
    if(root->data>key)
        root->left = deleteNode(root->left, key);
    else if(root->data<key)
        root->right = deleteNode(root->right, key);
    else
    {
        // 1. the target node has no child
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }
        // 2. The target node only has right child
        else if(root->left==NULL) //and root->right is not null
        {
            node* p = root->right;
            free(root);
            return p; //The parent now links to target node's right child
        }
        // 3. The target node only has left child
        else if(root->right==NULL)
        {
            node* p = root->left;
            free(root);
            return p;
        }
        // 4. The target node has both childs
        else
        {
            // Have to find the inorder successor of the target node
            node* ptr = find_inorder_successor(root->right);
            root->data = ptr->data; // The data in the target node is deleted
            root->right = deleteNode(root->right, ptr->data);
        }
    }
    return root; //when root->data!=key
}
void menu()
{
    bool flag=true;
    creation();
    int ch,key;
    while (flag)
    {
        printf("1. Insert data\n");
        printf("2. Delete data\n");
        printf("3. Inorder print\n");
        printf("4. Preorder print\n");
        printf("5. Postorder print\n");
        printf("6. Searching an element\n");
        printf("Enter your choice: \n->>");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            printf("Enter the data to be deleted\n->>");
            scanf("%d",&key);
            if(deleteNode(root,key))
                printf("Node successfully deleted\n");
            else
                printf("An Error occured!!, element not found\n");
            break;
        case 3:
            printInorder(root);
            printf("\n");
            break;
        case 4:
            printPreorder(root);
            printf("\n");
            break;
        case 5:
            printPostorder(root);
            printf("\n");
            break;
        case 6:
            printf("Enter the element to be searched\n->>");
            scanf("%d",&key);
            if(search(root,key))
                printf("Element found\n");
            else
                printf("Element not found\n");
            break;
        default:
            printf("wrong choice\n");
            break;
        }
        printf("Do you want to continue (1/0)?->>");
        scanf("%d",&flag);
    }
}
int main()
{
    menu();
    return 0;
}