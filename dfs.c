#include <stdio.h>
int adj[10][10];
int visited[10];
int v, i, j,k;

void dfs(int start)
{
    int stack[v];
    int top = -1;
    stack[++top] = start;
    visited[start] = 1;

    while (top != -1)
    {
        int vertex = stack[top--];
        printf("%d", vertex);
        while(k < v-1)
        {
            printf("->");
            k++;
            break;
        }
        for (i = 0; i < v; i++)
        {
            if (adj[vertex][i] == 1 && visited[i] != 1)
            {
                stack[++top] = i;
                visited[i] = 1;
            }
        }
    }
}

void main()
{
    printf("ENTER NO OF VERTICES: ");
    scanf("%d", &v);

    printf("ENTER ADJACENCY MATRIX:\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("enter starting vertex:");
    int start;
    scanf("%d", &start);
    for (i = 0; i < v; i++)
    {
        visited[i] = 0;
    }
    dfs(start);
}