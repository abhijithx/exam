// Read number of vertices v.

// Read the adjacency matrix adj[v][v].

// Initialize indegree[i] = 0 for all vertices.

// Compute indegree of each vertex:

// For every adj[i][j] == 1, increase indegree[j].

// Create an empty stack and set:

// top = -1

// count = 0 (number of vertices processed)

// While count < v:

// Set found = 0

// For each vertex i from 0 to v-1:

// If indegree[i] == 0:

// Push i into stack

// Mark it processed: indegree[i] = -1

// Increase count

// Set found = 1

// For every j:

// If adj[i][j] == 1, decrease indegree[j]

// If no vertex with indegree 0 is found (found == 0), break.

// If count < v:

// Print “GRAPH HAS CYCLE”

// Else:

// Print all vertices in stack as the Topological Order
#include <stdio.h>

int main()
{
    int v, i, j;

    printf("ENTER NO OF VERTICES: ");
    scanf("%d", &v);

    int adj[v][v];
    int indegree[v];

    printf("ENTER ADJACENCY MATRIX:\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 0; i < v; i++)
        indegree[i] = 0;

    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            if (adj[i][j] == 1)
                indegree[j]++;
        }
    }

    int stack[v];
    int top = -1;
    int count = 0;   

    while (count < v)
    {
        int found = 0;

        for (i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                stack[++top] = i;
                indegree[i] = -1;  
                count++;
                found = 1;

                for (j = 0; j < v; j++)
                {
                    if (adj[i][j] == 1)
                        indegree[j]--;
                }
            }
        }

        if (found == 0)
            break;   
    }

    if (count < v)
    {
        printf("\nGRAPH HAS CYCLE");
    }
    else
    {
        printf("\nTOPOLOGICAL ORDER:\n");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }

    return 0;
}
