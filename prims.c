#include <stdio.h>
int adj[10][10];
int visited[10];
int v, i, j, k;
#define INF 100

void prims(int start)
{
    visited[start] = 1;
    int mincost = 0;
    int edge = 0;
    while (edge < v - 1)

    {
        int min = INF;
        int visitedVertex = -1;
        int unvistiedVertex = -1;
        for (i = 0; i < v; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < v; j++)
                {
                    if (adj[i][j] < min && visited[j] == 0)  
                    {
                        min = adj[i][j];
                        visitedVertex = i;
                        unvistiedVertex = j;
                    }
                }
            }
        }
        visited[unvistiedVertex] = 1;
        printf(" %d - > %d ( cost : %d) \n",visitedVertex,unvistiedVertex,min);
        mincost+=min;
        edge ++;
    }

    printf("\n total cost : %d " , mincost );
}

void main()
{
    printf("ENTER NO OF VERTICES: ");
    scanf("%d", &v);

    printf("ENTER ADJACENCY MATRIX:\n");
    for (i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (j = 0; j < v; j++)
        {
            scanf("%d", &adj[i][j]);
            if (adj[i][j] == 0)
            {
                adj[i][j] = 99;
            }
        }
    }
    printf("enter starting vertex:");
    int start;
    scanf("%d", &start);
    prims(start);
}