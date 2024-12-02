#include <stdio.h>

#define INF 999

int parent[9]; // Array to track the parent of each node

// Function prototypes
int find(int i);
int unionSets(int i, int j);
void kruskal(int n, int cost[9][9]);

int main() {
    int n, cost[9][9];

    printf("\n**** KRUSKAL’S ALGORITHM FOR MINIMUM SPANNING TREE ****\n");

    // Get the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost adjacency matrix
    printf("Enter the cost adjacency matrix (use 0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF; // Replace 0 with INF for no edge
        }
    }

    // Call Kruskal's algorithm
    kruskal(n, cost);

    return 0;
}

// Function to find the parent of a node (with path compression)
int find(int i) {
    while (parent[i]) i = parent[i]; // Traverse up the parent array until the root is found
    return i;
}

// Function to union two sets
int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i; // Make one node the parent of another
        return 1;      // Return success
    }
    return 0;          // Return failure if already in the same set
}

// Function implementing Kruskal's algorithm
void kruskal(int n, int cost[9][9]) {
    int minCost = 0;   // Minimum cost of the spanning tree
    int edges = 0;     // Number of edges in the spanning tree
    int min, u, v, a, b;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    // Loop until the spanning tree has n-1 edges
    while (edges < n - 1) {
        min = INF;

        // Find the edge with the smallest weight
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) { // Check for the minimum cost edge
                    min = cost[i][j];
                    u = a = i;         // Store the endpoints of the edge
                    v = b = j;
                }
            }
        }

        u = find(u); // Find the root of the starting vertex
        v = find(v); // Find the root of the ending vertex

        // If adding this edge doesn't form a cycle
        if (unionSets(u, v)) {
            printf("Edge %d: (%d, %d) cost = %d\n", ++edges, a, b, min);
            minCost += min; // Add the edge cost to the total cost
        }

        cost[a][b] = cost[b][a] = INF; // Mark this edge as visited
    }

    printf("Minimum Cost of the Spanning Tree = %d\n", minCost); // Print the total cost
}
