#include <stdio.h>

int a[20][20], visited[20], n;

// DFS Function
void DFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;

    for(i = 1; i <= n; i++)
    {
        if(a[v][i] == 1 && visited[i] == 0)
            DFS(i);
    }
}

// BFS Function
void BFS(int v)
{
    int queue[20];
    int front = 0, rear = 0;
    int i;

    visited[v] = 1;
    queue[rear++] = v;

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 1; i <= n; i++)
        {
            if(a[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

// Main Function
int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    // DFS Traversal
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal: ");
    DFS(start);

    // BFS Traversal
    for(i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nBFS Traversal: ");
    BFS(start);

    return 0;
}
