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
int knapsack(int i, int m);
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
    optsoln = knapsack(1, m);

    // Output the optimal solution
    printf("The optimal solution is: %d\n", optsoln);

    return 0;
}

// Function to calculate the optimal solution using recursion
int knapsack(int i, int m) {
    // Base case: If all items have been considered
    if (i == n + 1) {
        return 0;
    }

    // If weight of the current item is more than the remaining capacity, skip it
    if (items[i].weight > m) {
        return knapsack(i + 1, m);
    }

    // Return the maximum of:
    // 1. Skipping the current item (move to next item)
    // 2. Including the current item (subtract its weight from remaining capacity and add its profit)
    return max(knapsack(i + 1, m), knapsack(i + 1, m - items[i].weight) + items[i].profit);
}

// Function to return the maximum of two values
int max(int a, int b) {
    return (a > b) ? a : b;  // Return the larger of the two values
}
