#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[5];
    float value;
    float ratio;
    float weight;
} Item;

void sortItems(Item items[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (items[j].ratio < items[j + 1].ratio)
            {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

float knapsack(Item items[], int n, int capacity)
{
    for (int i = 0; i < n; i++)
    {
        items[i].ratio = items[i].value / items[i].weight;
    }

    sortItems(items, n);

    float totalValue = 0.0;
    float fractions[n];

    for (int i = 0; i < n; i++)
    {
        if (capacity >= items[i].weight)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
            fractions[i] = 1.0;
        }
        else
        {
            fractions[i] = capacity / items[i].weight;
            totalValue += items[i].value * capacity;
            capacity = 0;
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%s    ", items[i].name);
    }

    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%.1f  ", fractions[i]);
    }

    return totalValue;
}

int main(){
    int n ;
    float capacity;
    printf("enter no of objects: ");
    scanf("%d",&n);
    Item items[n];

    printf("\nEnter Objects: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter %d Object name: ",i+1);
        scanf("%s",&items[i].name);

        printf("Enter %d Object profit: ",i+1);
        scanf("%f",&items[i].value);
        
        printf("Enter %d Object weight: ",i+1);
        scanf("%f",&items[i].weight); 

        printf("\n");
    }
    
    printf("\nenter capacity of sack: ");
    scanf("%f",&capacity);

    float Max = knapsack(items,n,capacity);

    printf("\nmax value of knapsack is : %f",Max);
    return 0;
}
