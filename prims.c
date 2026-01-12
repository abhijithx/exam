// Read number of vertices v.

// Read the adjacency matrix adj[v][v].

// Replace 0 with a large value (like 99) to mean “no edge”.

// Initialize all visited[i] = 0.

// Read the starting vertex start.

// Mark start as visited.

// Set edge = 0 and mincost = 0.

// Repeat while edge < v - 1:

// Set min = INF.

// For every vertex i:

// If visited[i] == 1, check all vertices j:

// If visited[j] == 0 and adj[i][j] < min,
// update min, visitedVertex = i, unvisitedVertex = j.

// Mark unvisitedVertex as visited.

// Print the edge (visitedVertex → unvisitedVertex) and its cost.

// Add min to mincost.

// Increase edge by 1.

// After the loop, print mincost.

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