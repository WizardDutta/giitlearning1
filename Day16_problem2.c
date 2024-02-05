#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define M 5
#define MAX 9999

// void Djkstra();
int** adjacencyMatrix();
void dijkstra(int,bool*,int*);
void dijkstra_util();
typedef struct graph{
    int vertex;
    int **adjM;
}graph;

graph G; //global

void initGraph()
{
    G.vertex = M;
    G.adjM = adjacencyMatrix();
}
int** adjacencyMatrix()
{
    int **matrix=NULL;
    int i;
    matrix = (int**)calloc(G.vertex, sizeof(int*));
    for(i=0;i<G.vertex;i++)
        matrix[i] = (int*)calloc(G.vertex, sizeof(int));
    
    matrix[0][0] = 0;
    
    return matrix;
}
void dijkstra_util()
{
    bool visited[G.vertex];
    int distance[G.vertex];
    for(int i=0;i<G.vertex;i++)
        distance[i] = MAX;
    int src = 0;
    distance[src]=0;
    dijkstra(src,visited,distance);
    printf("\nDistance of each node from 0: \n");
    for(int i=0;i<G.vertex;i++)
        printf("%d ",distance[i]);
}
void dijkstra(int src,bool vis[],int distance[])
{
    if(!vis[src]) 
    {
        vis[src]=true;
        for(int i=0;i<G.vertex;i++) {
            if(G.adjM[src][i]) {
                int l=G.adjM[src][i]+distance[src];
                if(l<distance[i]) distance[i]=l;
                dijkstra(i,vis,distance);
            }
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
    dijkstra_util();
    
    return 0;
}
// void Djkstra()
// {
//     int N = G.vertex;
//     int distArr[N],i,j;
//     distArr[0]=0;
//     for(i=1;i<N;i++)
//         distArr[i] = MAX; //initializing distarr
//     bool visited[N];
//     for(i=0;i<N;i++) visited[i]=false;
//     for(i=0;i<N;i++)
//     {
//         for(j=0;j<N;j++)
//             if(G.adjM[i][j] && (G.adjM[i][j]+distArr[i]<distArr[j]))
//                 distArr[j] = G.adjM[i][j] + distArr[i];
//     }
//     printf("\nDistance of each node from 0: \n");
//     for(i=0;i<G.vertex;i++)
//         printf("%d ",distArr[i]);
// }