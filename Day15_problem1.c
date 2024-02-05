#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define M 5

bool** adjacencyMatrix();
void DFS();
void DFS_util(int,bool*);
void BFS();
void BFS_util(bool*);



typedef struct graph{
    int vertex;
    bool **adjM;
}graph;

graph G; //Global declaration

void initGraph()
{
    G.vertex = M;
    G.adjM = adjacencyMatrix();
}
bool** adjacencyMatrix()
{
    bool **matrix=NULL;
    int i;
    matrix = (bool**)calloc(G.vertex, sizeof(bool*));
    for(i=0;i<G.vertex;i++)
        matrix[i] = (bool*)calloc(G.vertex, sizeof(bool));
    
    matrix[0][0] = false;
    
    return matrix;
}


void DFS()
{
   int n = G.vertex;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i] = false;
    DFS_util(0, visited); //beginig the traversal
}
void DFS_util(int curr, bool visited[])
{
    printf("%d ",curr);
    visited[curr] = true;
    int j;
    for(j=0;j<G.vertex;j++)
    {
        if(G.adjM[curr][j]==true && !visited[j])
            DFS_util(j, visited);
    }
}
// Dynamic Queue implementation
typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct que 
{
    node *front,*rear;
}que;
void initQ(que *q)
{
    q->front=NULL;
    q->rear=NULL;
}
bool emptyQ(que *q)
{
    return q->front==NULL;
}
void insertQ(que *q, int x)
{
    node *ptr=(node*)malloc(sizeof(node));
    ptr->data=x;
    ptr->next=NULL;
    if(emptyQ(q))
    {
       q->front=ptr;
       q->rear=ptr;
    }
    else 
    {
       q->rear->next=ptr;
       q->rear=ptr;
    }
}
int deleteQ(que *q)
{
    if(q->front)
    {
        node *ptr=q->front;
        int x=ptr->data;
        q->front=q->front->next;
        free(ptr);
        return x;
    }
    else 
    {
        printf("\nUnderflow");
        return INT_MIN; //as an invalid 
    }
} // end of Queue implementation
void BFS()
{
    int n = G.vertex;
    bool visited[n];
    for(int i=0;i<n;i++)
        visited[i] = false; //initializing
    BFS_util(visited);
}
void BFS_util(bool* visited)
{
    que Q;
    initQ(&Q);
    insertQ(&Q,0);
    while (!emptyQ(&Q))
    {
        int curr = deleteQ(&Q);
        if(!visited[curr])
        {
            printf("%d ",curr);
            visited[curr] = true;
            int j;
            for(j=0;j<G.vertex;j++)
                if(G.adjM[curr][j])
                    insertQ(&Q,j);
        }
    }
}
int main()
{
    initGraph();
    int i,j;
    printf("Enter the adjacency Matrix: \n");
    for(i=0;i<G.vertex;i++)
    {
        for(j=0;j<G.vertex;j++)
            scanf("%d",&G.adjM[i][j]);
    }
    printf("\nPrinting in DFS style\n");
    DFS();
    printf("\nPrinting in BFS style\n");
    BFS();
    return 0;
}