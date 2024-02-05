#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#define M 5
#define MAX 999999

void dijkstra(int,bool[],int[]);
void dijkstra_allPair();
int** adjacencyMatrix();
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
void dijkstra_allPair()
{
    bool visited[G.vertex];
    int distance[G.vertex];
    for(int curr=0;curr<G.vertex;curr++){
        for(int i=0;i<G.vertex;i++)
            distance[i] = MAX;
        for(int i=0;i<G.vertex;i++)
            visited[i] = false;
        int src = curr;
        distance[src]=0;
        dijkstra(src,visited,distance);
        printf("\nDistance of each node from %d: \n",src);
        for(int i=0;i<G.vertex;i++)
            printf("%d ",distance[i]);
    }
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
    dijkstra_allPair();
    return 0;
}
// void Djkstra_allPair()
// {
//     int N = G.vertex;
//     int distArr[N][N],i,j,curr,count;
//     for(curr=0;curr<N;curr++)
//     {
//         for(i=0;i<N;i++)
//             distArr[curr][i] = MAX; //initializing distarr
//         distArr[curr][curr]=0;

//         for(i=curr,count=0;count<N;i=(i+1)%N,count++)
//         {
//             for(j=0;j<N;j++)
//                 if(G.adjM[i][j] && (G.adjM[i][j]+distArr[curr][i]<distArr[curr][j]))
//                     distArr[curr][j] = G.adjM[i][j] + distArr[curr][i];
//         }
//         // printf("\nDistance of each node from %d: \n",curr);
//     }
//     printf("\nPairwise shortest path matrix:\n");
//     for(i=0;i<N;i++)
//     {
//         for(j=0;j<N;j++)
//             printf("%d ",distArr[i][j]);
//         printf("\n");
//     }
// }