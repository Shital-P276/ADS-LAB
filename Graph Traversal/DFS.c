#include <stdio.h>

void DFS(int adj[20][20], int u, int visited[20], int n);

int main()
{
    int n, adj[20][20], i, j, visited[20], source;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the source node (1 to %d): ", n);
    scanf("%d", &source);

    DFS(adj, source, visited, n);

    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
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
    int v;
    visited[u] = 1;  

    for (v = 1; v <= n; v++)
    {
        if (adj[u][v] == 1 && visited[v] == 0)   
        {
            DFS(adj, v, visited, n); 
        }
    }
}
