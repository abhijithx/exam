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
