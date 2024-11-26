#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    double value;
    double weight;
    double ratio;
} Item;

void sortItems(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

double fractionalKnapsack(Item items[], int n, double capacity) {
    sortItems(items, n);

    double totalValue = 0.0;
    double fractions[n];  // Store fractions of items taken

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            fractions[i] = 1.0;  // Full item taken
        } else {
            fractions[i] = capacity / items[i].weight;
            totalValue += items[i].ratio * capacity;
            capacity = 0;
            break;  // Knapsack is full
        }
    }

    // Output the items taken in the desired format
    printf("Items taken:\n");
    for (int i = 0; i < n; i++) {
        printf("%s ", items[i].name);  // Print item names
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%.1f ", fractions[i]);  // Print fractions
    }
    printf("\n");

    return totalValue;
}

int main() {
    int n = 3;  // Number of items
    double capacity = 50;  // Knapsack capacity

    // Create items (name, value, weight)
    Item items[] = {
        {"o1", 60, 10, 0},
        {"o2", 100, 20, 0},
        {"o3", 120, 30, 0}
    };

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        items[i].ratio = items[i].value / items[i].weight;
    }

    double maxValue = fractionalKnapsack(items, n, capacity);

    printf("\nMaximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
