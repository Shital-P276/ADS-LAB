#include <stdio.h>

// Quick sort function declaration
void qsort(int b[], int left, int right);

int n;

void main() {
    int a[100], i, l, r;

    printf("\nENTER THE SIZE OF THE ARRAY: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nENTER NUMBER-%d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\nTHE ARRAY ELEMENTS BEFORE SORTING: \n");
    for (i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }

    l = 0;
    r = n - 1;

    qsort(a, l, r);

    printf("\nTHE ARRAY ELEMENTS AFTER SORTING: \n");
    for (i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
}

void qsort(int b[], int left, int right) {
    if (right > left) {
        int i = left, j = right, pivot = b[left];

        while (i < j) {
            while (b[i] <= pivot && i < right) i++;
            while (b[j] > pivot) j--;

            if (i < j) { 
                // Swap elements
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }

        // Swap pivot into correct position
        int temp = b[left];
        b[left] = b[j];
        b[j] = temp;

        // Recursive calls
        qsort(b, left, j - 1);
        qsort(b, j + 1, right);
    }
}
