//Check whether a given graph is connected or not using DFS method.
#include <stdio.h>

void DFS(int adj[20][20][20],int k, int u, int visited[20][20], int n);

int main()
{
    int n, adj[20][20][20], i, j, visited[20][20], source;
    int curr, z;
    
    printf("Enter the number of vertices of all graphs: ");
    scanf("%d", &n);
    
    printf("Enter the number of graphs: ");
    scanf("%d", &z);
    
    for(int k = 0 ; k < z ; k++){
    printf("\nEnter the adjacency matrix %d:\n",k);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &adj[k][i][j]);
            }
        }
    }
    
    for (int k = 0;k<z;k++){
        for (i = 1; i <= n; i++)
        {
            visited[k][i] = 0;
        }
    }
    

    for (int k = 0;k<z;k++){
        printf("\nEnter the source node for %d matrix : ", k);
        scanf("%d", &source);

        DFS(adj,k,source, visited, n);

        for (i = 1; i <= n; i++)
        {
            if (visited[k][i] == 0)
            {
                printf("\nGraph is not connected\n");
                curr = 1;
                break;
            }
            curr = 0;
        }
        
        if(curr == 0){
            printf("\nGraph is connected\n");
        }

    }
}

void DFS(int adj[20][20][20],int k , int u, int visited[20][20], int n)
{
    int v;
    visited[k][u] = 1;  

        for (v = 1; v <= n; v++)
        {
            if (adj[k][u][v] == 1 && visited[k][v] == 0)   
            {
               DFS(adj,k,v, visited, n); 
            }
        }
}
