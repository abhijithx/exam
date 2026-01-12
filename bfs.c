// Read number of vertices v.

// Read the adjacency matrix adj[v][v].

// Read the starting vertex start.

// Initialize all visited[i] = 0.

// Create an empty queue.

// Enqueue start into the queue and mark it as visited.

// While the queue is not empty:

// Dequeue one vertex vertex.

// Print vertex.

// For every vertex i from 0 to v-1:

// If adj[vertex][i] == 1 and visited[i] == 0:

// Enqueue i into the queue.

// Mark visited[i] = 1.

// Repeat until the queue becomes empty.

#include <stdio.h>
int adj[10][10];
int visited[10];
int v, i, j, k;

void bfs(int start)
{
    int queue[v];
    int front = 0;
    int rear = -1;
    queue[++rear] = start;
    visited[start] = 1;
    while (front <= rear)
    {
        int vertex = queue[front++];
        printf("%d", vertex);
        while (k < v - 1)
        {
            printf("->");
            k++;
            break;
        }
        for (i = 0; i < v; i++)
        {
            if (adj[vertex][i] == 1 && visited[i] != 1)
            {
                queue[++rear] = i;
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
    bfs(start);
}