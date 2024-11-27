#include <stdio.h>
#define INF 999 // Define a large value to represent "infinity" (no direct path)

void dijkstra(int source, int cost[20][20], int visited[20], int distance[20], int n);

int main() {
    int i, j, n, source;
    int visited[20], cost[20][20], distance[20];

    // Prompt the user for the number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost adjacency matrix
    printf("Enter the cost adjacency matrix (use %d for no direct path):\n", INF);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    // Ask for the source vertex
    printf("\nEnter the source node (0 to %d): ", n - 1);
    scanf("%d", &source);

    // Call Dijkstra's algorithm to find the shortest paths
    dijkstra(source, cost, visited, distance, n);

    // Display the shortest paths from the source to all other nodes
    printf("\nShortest paths from node %d:\n", source);
    for (i = 0; i < n; i++) {
        if (i != source) {
            printf("To node %d: %d\n", i, distance[i]);
        }
    }

    return 0;
}

void dijkstra(int source, int cost[20][20], int visited[20], int distance[20], int n) {
    int i, j, min, u;

    // Initialize all nodes as unvisited and set initial distances from the source
    for (i = 0; i < n; i++) {
        visited[i] = 0;              // Mark all nodes as unvisited
        distance[i] = cost[source][i]; // Distance to each node is the direct cost from the source
    }

    visited[source] = 1;   // Mark the source node as visited
    distance[source] = 0;  // Distance to itself is always 0

    // Iterate to find the shortest paths to all nodes
    for (j = 1; j < n; j++) {
        min = INF;   // Initialize the minimum distance to "infinity"
        u = -1;      // Variable to store the next node to process

        // Find the unvisited node with the smallest known distance
        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;  // Update the next node to process
            }
        }

        if (u == -1) { // If no reachable unvisited nodes remain, exit
            break;
        }

        visited[u] = 1; // Mark the chosen node as visited

        // Update distances for all unvisited neighbors of the chosen node
        for (i = 0; i < n; i++) {
            if (cost[u][i] != INF && !visited[i]) { // Check for valid unvisited neighbors
                // Update distance if a shorter path is found
                if (distance[i] > distance[u] + cost[u][i]) {
                    distance[i] = distance[u] + cost[u][i];
                }
            }
        }
    }
}
