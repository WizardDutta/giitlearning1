#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool** adjacencyMatrix();

typedef struct edge{
    int src,dest,wt;
}edge;

typedef struct graph{
    int vertex;
    bool **adjM;
    int **adjL;
}graph;

graph G;
void initGraph()
{
    G.vertex = 6;
    G.adjM = adjacencyMatrix();
    G.adjL = NULL;
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
int main()
{
    initGraph();
    int i,j;
    for(i=0;i<G.vertex;i++)
    {
        for(j=0;j<G.vertex;j++)
            printf("%d ",G.adjM[i][j]);
        printf("\n");
    }
    return 0;
}