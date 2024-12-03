#include <stdio.h>
#define MAX 50  // Maximum number of items

// Struct to represent an item with profit and weight
struct Item {
    int weight;
    int profit;
};

struct Item items[MAX];  // Array to store the items
int n;  // Number of items

// Function prototypes
int knapsack(int m);
int max(int a, int b);

int main() {
    int m, i, optsoln;

    // Input the number of items
    printf("Enter number of objects: ");
    scanf("%d", &n);

    // Input the weights and profits of items
    printf("Enter the weights and profits:\n");
    for (i = 1; i <= n; i++) {
        printf("Item %d - Weight: ", i);
        scanf("%d", &items[i].weight);
        printf("Item %d - Profit: ", i);
        scanf("%d", &items[i].profit);
    }

    // Input the knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);

    // Find the optimal solution using the knapsack function
    optsoln = knapsack(m);

    // Output the optimal solution
    printf("The optimal solution is: %d\n", optsoln);

    return 0;
}

// Function to calculate the optimal solution using dynamic programming
int knapsack(int m) {
    int dp[MAX][MAX] = {0};  // DP table to store results of subproblems

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (items[i].weight <= w) {
                // Max of excluding or including the current item
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - items[i].weight] + items[i].profit);
            } else {
                // If the current item can't be included
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    // The result is stored in the bottom-right cell of the DP table
    return dp[n][m];
}

// Function to return the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;  // Return the larger of the two values
}
