#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    int bf;
    struct node *left;
    struct node *right;
}node;
int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}



node* createNode(int x) {
    node *n=(node*)malloc(sizeof(node));
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}

int findHeight(node* root)
{
    if(root)
        return max(findHeight(root->left), findHeight(root->right))+1;
    return 0;
}
int findBalanceFactor(node* root)
{
    return findHeight(root->left) - findHeight(root->right);
}

node* rightRotation(node* root)
{
    node *child = root->left;
    node* temp = child->right; //it can be null
    child->right = root;
    root->left = temp;

    return child;
}
node* leftRotation(node* root)
{
    node* child = root->right;
    node* temp = child->left;
    child->left = root;
    root->right = temp;

    return child;
}
node* findInorderSuccessor(node* root)
{
    while (root->left)
        root = root->left;
    return root;
}
node* insert(node* root, int x)
{
    if(root) {
        if(root->data>x) {
           root->left=insert(root->left,x);
        } else  {
           root->right=insert(root->right,x);
        }

        int bf=findBalanceFactor(root);

        if(bf>1)
        {
            node *child = root->left;
            if(findBalanceFactor(child)>0) //right rotation
            {
                root = rightRotation(root);
            }
            else // left right rotation
            {
                root->left = leftRotation(child);
                root = rightRotation(root);
            }
        }
        else if(bf<-1)
        {
            node* child = root->right;
            if(findBalanceFactor(child)<0) //left rotation
            {
                root = leftRotation(root);
            }
            else // right left rotation
            {
                root->right = rightRotation(child);
                root = leftRotation(root);
            }
        }
        
        return root;
    }
    else 
        return createNode(x);
}
node* deleteNode(node* root, int val)
{
    if(root->data > val)
        root->left = deleteNode(root->left, val);
    else if(root->data < val)
        root->right = deleteNode(root->right, val);
    else
    {
        if(root->left==NULL && root->right==NULL) // childless node
        { 
            free(root);
            return NULL;
        }
        else if(root->left==NULL) // only right child
        {
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL) // only left child
        {
            node* temp = root->left;
            free(root);
            return temp;
        }
        else{ // has both children
            node* IS = findInorderSuccessor(root->right);
            root->data = IS->data;
            root->right = deleteNode(root->right, IS->data);
            // in this case, we need to check the bf of the root itself
        }
    }


    int bf = findBalanceFactor(root);

    if(bf>1)
    {
        node *child = root->left;
        if(findBalanceFactor(child)>0) //right rotation
        {
            root = rightRotation(root);
        }
        else // left right rotation
        {
            root->left = leftRotation(child);
            root = rightRotation(root);
        }
    }
    else if(bf<-1)
    {
        node* child = root->right;
        if(findBalanceFactor(child)<0) //left rotation
        {
            root = leftRotation(root);
        }
        else // right left rotation
        {
            root->right = rightRotation(child);
            root = leftRotation(root);
        }
    }
    return root;
}


void inorder(node *root) {
    if(root) {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void preorder(node *root) {
    if(root) {
        printf("%d ",root->data);
        int bf=findBalanceFactor(root);
        printf("Bf = %d\n",bf);
        preorder(root->left);
        preorder(root->right);
    }
}



int main() {
    node *root=createNode(100);
    int carryon=1;
    while(1) {
        int x;
        printf("Enter Value : ");
        scanf("%d",&x);
        root=insert(root,x);
        printf("\n Want to quit ? ");
        scanf("%d",&carryon);
        if(carryon)
            break;
    }
    printf("Tree preorder = \n");
    preorder(root); 
    printf("\nInorder \n");
    inorder(root);
    int val;
    printf("\nEnter the value you want to delete: ");
    scanf("%d",&val);
    root = deleteNode(root, val);
    char s[10]="root";
    printf("Tree preorder = \n");
    preorder(root); 
    printf("\nInorder \n");
    inorder(root);
    return 0;
}