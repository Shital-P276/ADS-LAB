#include <stdio.h>

int A[50];
void merge(int, int, int);

void mergesort(int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = ((low + high) / 2);
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

void merge(int low, int mid, int high)
{
    int i, h, j, B[50], k;
    h = low;
    i = low;
    j = mid + 1;

    while ((h <= mid) && (j <= high))
    {
        if (A[h] <= A[j])
        {
            B[i] = A[h];
            h++;
        }
        else
        {
            B[i] = A[j];
            j++;
        }
        i++;
    }

    if (h > mid)
    {
        for (k = j; k <= high; k++)
        {
            B[i] = A[k];
            i++;
        }
    }
    else
    {
        for (k = h; k <= mid; k++)
        {
            B[i] = A[k];
            i++;
        }
        for (k = low; k <= high; k++)
        {
            A[k] = B[k];
        }
    }
}
int main()
{
    int n, i;

    printf("Enter number of Elements: ");
    scanf("%d", &n);
    printf("Enter %d numbers: \n", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nOriginal Array:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }

    mergesort(1, n);

    printf("\nSorted Array:\n");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
