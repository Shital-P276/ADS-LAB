#include <stdio.h>

int n, cost[10][10]; // Number of vertices and cost matrix

void prim() {
    int visited[10] = {0};  // To track visited vertices
    int minCost = 0;        // Total cost of the MST
    int edges = 0;          // Count of edges in the MST

    visited[0] = 1;         // Start with the first vertex
    printf("\nEdges in the Minimum Spanning Tree:\n");

    while (edges < n - 1) { // Loop until n-1 edges are included
        int min = 999;      // A very large value to find the smallest edge
        int u = -1, v = -1; // To store the vertices of the selected edge
        
        // Find the smallest edge connecting a visited vertex to an unvisited vertex
        for (int i = 0; i < n; i++) {
            if (visited[i]) { // Check only visited vertices
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Add the selected edge to the MST
        printf("Edge (%d, %d) with cost %d\n", u, v, min);
        minCost += min; // Add edge cost to total cost
        visited[v] = 1; // Mark the vertex as visited
        edges++;        // Increase the edge count
    }

    printf("\nTotal Minimum Cost: %d\n", minCost);
}

int main() {
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    printf("\nEnter the cost adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    printf("\nCost Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", cost[i][j]);
        }
        printf("\n");
    }

    prim(); // Call the function to find the MST
    return 0;
}
