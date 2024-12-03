#include <stdio.h>

// Function to perform Breadth-First Search (BFS) on the graph
// Parameters:
// - graph: Adjacency matrix representation of the graph
// - start: Starting node for BFS
// - visited: Array to track visited nodes
// - n: Total number of vertices in the graph
void BFS(int graph[20][20], int start, int visited[20], int n) {
    int queue[20], front = 0, rear = 0;
    
    // Initialize the queue with the start node and mark it as visited
    queue[rear++] = start;
    visited[start] = 1;

    // Process nodes in the queue until it is empty
    while (front < rear) {
        int current = queue[front++]; // Dequeue the front node

        // Traverse all adjacent nodes
        for (int v = 1; v <= n; v++) {
            // If an edge exists and the node has not been visited
            if (graph[current][v] == 1 && !visited[v]) {
                queue[rear++] = v; // Enqueue the adjacent node
                visited[v] = 1;    // Mark the node as visited
            }
        }
    }
}

int main() {
    int n, graph[20][20], visited[20] = {0}, source;

    // Input the number of vertices in the graph
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the adjacency matrix of the graph
    printf("\nEnter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Input the starting node for BFS
    printf("\nEnter the source node: ");
    scanf("%d", &source);

    // Perform BFS from the source node
    BFS(graph, source, visited, n);

    // Display the reachability of each node
    printf("\nSource node: %d\n", source);
    for (int i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("Node %d is reachable\n", i);
        } else {
            printf("Node %d is not reachable\n", i);
        }
    }

    return 0;
}
