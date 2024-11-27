#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// A structure to represent a job
typedef struct Job {
    int id;       // Job ID
    int profit;   // Profit if job is completed
    int deadline; // Deadline of the job
} Job;

// Function to compare jobs based on profit for sorting
int compare(const void* a, const void* b) {
    Job* jobA = (Job*)a;
    Job* jobB = (Job*)b;
    return jobB->profit - jobA->profit;
}

// Utility function to find the minimum of two numbers
int min(int num1, int num2) {
    return (num1 < num2) ? num1 : num2;
}

// Function to perform Job Sequencing
void jobSequencing(Job jobs[], int n) {
    // Step 1: Sort jobs by profit in descending order
    qsort(jobs, n, sizeof(Job), compare);

    // Step 2: Create an array to track free time slots
    bool slots[n];
    for (int i = 0; i < n; i++) {
        slots[i] = false; // All slots are initially free
    }

    // Step 3: Create an array to store the job sequence
    int jobSequence[n];
    for (int i = 0; i < n; i++) {
        jobSequence[i] = -1; // -1 indicates no job is assigned
    }

    // Step 4: Initialize total profit
    int totalProfit = 0;

    // Step 5: Assign jobs to slots
    for (int i = 0; i < n; i++) {
        // Iterate from the last possible time slot for the job
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slots[j]) { // If the slot is free
                slots[j] = true;          // Mark slot as occupied
                jobSequence[j] = jobs[i].id; // Assign the job ID
                totalProfit += jobs[i].profit; // Add profit
                break;
            }
        }
    }

    // Step 6: Print the job sequence and total profit
    printf("Job sequence: ");
    for (int i = 0; i < n; i++) {
        if (jobSequence[i] != -1) {
            printf("Job %d ", jobSequence[i]);
        }
    }
    printf("\nTotal profit: %d\n", totalProfit);
}

int main() {
    // Input: Number of jobs and their details
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    printf("Enter job details (ID, profit, deadline):\n");
    for (int i = 0; i < n; i++) {
        printf("Job %d: ", i + 1);
        scanf("%d %d %d", &jobs[i].id, &jobs[i].profit, &jobs[i].deadline);
    }

    // Call job sequencing function
    jobSequencing(jobs, n);

    return 0;
}
