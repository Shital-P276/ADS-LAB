#include <stdio.h>

void DFS(int adj[20][20], int u, int visited[20], int n);

int main()
{
    int n, adj[20][20], visited[20] = {0};

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    // Start DFS from the first vertex (0-based index)
    DFS(adj, 0, visited, n);

    // Check if all vertices are visited
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("\nGraph is not connected\n");
            return 0;
        }
    }

    printf("\nGraph is connected\n");
    return 0;
}

void DFS(int adj[20][20], int u, int visited[20], int n)
{
    visited[u] = 1; // Mark the current node as visited

    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1 && !visited[v]) // Check for an unvisited neighbor
        {
            DFS(adj, v, visited, n);
        }
    }
}
