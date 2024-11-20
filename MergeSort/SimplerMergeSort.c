#include <stdio.h>

#define MAX_SIZE 50

int A[MAX_SIZE];

void merge(int low, int mid, int high)
{
    int B[MAX_SIZE];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from first half
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    // Copy remaining elements from second half
    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    // Copy back to original array
    for (int p = low; p <= high; p++)
    {
        A[p] = B[p];
    }
}

void mergesort(int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main()
{
    int n, i;
    printf("Enter number of Elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers: \n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nOriginal Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    mergesort(0, n - 1);

    printf("\nSorted Array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
