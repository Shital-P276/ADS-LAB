#include <stdio.h>

#define INF 999

int parent[9]; // Array to track the parent of each node
int find(int i);
int unionSets(int i, int j);

int main() {
    int n, cost[9][9], minCost = 0, edges = 0;
    int u, v, a, b, min;

    printf("\n**** KRUSKAL’S ALGORITHM FOR MINIMUM SPANNING TREE ****\n");
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost adjacency matrix (use 0 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) cost[i][j] = INF; // Replace 0 with INF
        }
    }

    printf("\nEdges in the Minimum Spanning Tree:\n");
    while (edges < n - 1) {
        min = INF;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    u = a = i;
                    v = b = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (unionSets(u, v)) {
            printf("Edge %d: (%d, %d) cost = %d\n", ++edges, a, b, min);
            minCost += min;
        }
        cost[a][b] = cost[b][a] = INF; // Mark edge as visited
    }

    printf("Minimum Cost of the Spanning Tree = %d\n", minCost);
    return 0;
}

int find(int i) {
    while (parent[i]) i = parent[i];
    return i;
}

int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i; // Union operation
        return 1;
    }
    return 0;
}
