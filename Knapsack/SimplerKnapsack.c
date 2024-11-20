#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float x[20] = {0.0};
    float tp = 0.0;
    float remaining_capacity = capacity;

    for (int i = 0; i < n; i++) {
        if (weight[i] <= remaining_capacity) {
            x[i] = 1.0;
            tp += profit[i];
            remaining_capacity -= weight[i];
        } else {
            x[i] = remaining_capacity / weight[i];
            tp += x[i] * profit[i];
            break;
        }
    }

    printf("\nThe result vector is:- ");
    for (int i = 0; i < n; i++)
        printf("%.2f\t", x[i]);
    printf("\nMaximum profit is:- %.2f", tp);
}

int main() {
    float weight[20], profit[20], capacity;
    int num;
    float ratio[20];

    printf("\nEnter the no. of objects:- ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each object:- ");
    for (int i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter the capacity of knapsack:- ");
    scanf("%f", &capacity);

    // Calculate profit-to-weight ratios and sort in descending order
    for (int i = 0; i < num; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                float temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                // Swap weight
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                // Swap profit
                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }
    

    knapsack(num, weight, profit, capacity);
    
    return 0;
}

/*Fractional Knapsack Algorithm

Input:

n: Number of objects
weight[]: Array of object weights
profit[]: Array of object profits
capacity: Knapsack maximum capacity


Calculate Profit-to-Weight Ratio:

For each object i = 0 to n-1:

ratio[i] = profit[i] / weight[i]




Sort Objects in Descending Order of Profit-to-Weight Ratio:

Use descending bubble sort or quick sort
Rearrange weight[], profit[], and ratio[] simultaneously
Ensures most valuable items considered first


Fractional Knapsack Selection:

Initialize total_profit = 0
Initialize result_vector[n] = {0}
Initialize remaining_capacity = capacity
For each object i = 0 to n-1:

If weight[i] <= remaining_capacity:

result_vector[i] = 1.0
total_profit += profit[i]
remaining_capacity -= weight[i]


Else:

result_vector[i] = remaining_capacity / weight[i]
total_profit += result_vector[i] * profit[i]
Break loop






Output:

Print result_vector (fraction of each object selected)
Print total_profit



Time Complexity: O(n²)
Space Complexity: O(n)*/
