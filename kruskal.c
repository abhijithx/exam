// Read number of vertices v.

// Read the adjacency matrix matrix[v][v].

// Replace 0 with a large value (like 999) to mean “no edge”.

// Initialize parent[i] = i for all vertices.

// Set edge = 0 and total = 0.

// Repeat until edge < v - 1:

// Find the smallest edge (a, b) in the entire matrix.

// Find the parents:

// u = find(a)

// v2 = find(b)

// If u != v2 (they are in different groups):

// Print the edge (a, b) and its cost.

// Add the cost to total.

// Join the groups using unionSet(u, v2).

// Increase edge by 1.

// Remove this edge from consideration by setting
// matrix[a][b] = matrix[b][a] = 999.

// Print total cost of the Minimum Spanning Tree.

#include <stdio.h>

int parent[10];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

int main()
{
    int v, i, j;
    int matrix[10][10];

    printf("ENTER NO OF VERTICES: ");
    scanf("%d", &v);

    printf("ENTER ADJACENCY MATRIX:\n");
    for (i = 0; i < v; i++)

    {
        parent[i] = i;
        for (j = 0; j < v; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                matrix[i][j] = 999;
        }
    }

    int edge = 0, total = 0;

    printf("\nEdges in Minimum Spanning Tree:\n");

    while (edge < v - 1)
    {
        int min = 999, a = -1, b = -1;

        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (matrix[i][j] < min)
                {
                    min = matrix[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        int u = find(a);
        int v2 = find(b);

        if (u != v2)
        {
            printf("%d -> %d cost: %d\n", a, b, min);
            total += min;
            unionSet(u, v2);
            edge++;
        }

        matrix[a][b] = matrix[b][a] = 999;
    }

    printf("Total cost = %d\n", total);
    return 0;
}