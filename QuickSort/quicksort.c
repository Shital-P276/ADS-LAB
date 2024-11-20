#include <stdio.h>

void qsort(int b[], int left, int right);

int main()
{
    int a[100], i, l, r, n;
    
    printf("\nENTER THE SIZE OF THE ARRAY: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++)
    {
        printf("\nENTER NUMBER-%d: ", i + 1);
        scanf("%d", &a[i]);
    }
    
    printf("\nTHE ARRAY ELEMENTS BEFORE SORTING: \n");
    for (i = 0; i < n; i++)
    {
        printf("\t %d", a[i]);
    }
    
    l = 0;
    r = n - 1;
    qsort(a, l, r);
    
    printf("\nTHE ARRAY ELEMENTS AFTER SORTING: \n");
    for (i = 0; i < n; i++)
        printf("\t %d", a[i]);
    
    return 0;
}

void qsort(int b[], int left, int right)
{
    if (left >= right) return;  // Base case for recursion

    int pivot = b[left];
    int i = left + 1;
    int j = right;

    while (i <= j)
    {
        while (i <= right && b[i] <= pivot)
            i++;
        
        while (j > left && b[j] > pivot)
            j--;
        
        if (i < j)
        {
            // Swap elements
            int temp = b[i];
            b[i] = b[j];
            b[j] = temp;
        }
    }

    // Place pivot in correct position
    int temp = b[left];
    b[left] = b[j];
    b[j] = temp;

    // Recursive calls
    qsort(b, left, j - 1);
    qsort(b, j + 1, right);
}
