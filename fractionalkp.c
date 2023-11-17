#include <stdio.h>

// Swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort based on profit per unit weight
void bubbleSort(int profit[], int weight[], int n) {
    int i , j;
    for (i=0;i < n;i++) {
        for (j = 0; j < n - 1 - i; j++) {
            double ratio1 = (double)profit[j] / weight[j];
            double ratio2 = (double)profit[j + 1] / weight[j + 1];
            if (ratio1 < ratio2) {
                swap(&weight[j], &weight[j + 1]);
                swap(&profit[j], &profit[j + 1]);
            }
        }
        //i++;
    }
}

// Function to solve the fractional knapsack problem
double fractionalKnapsack(int profit[], int weight[], int capacity, int n) {
    double totalValue = 0.0;
    int i;

    // Sort items based on profit per unit weight using bubble sort
    bubbleSort(profit, weight, n);

    // Fill the knapsack with items
    
    for(i=0;i < n && capacity > 0;i++) {
        if (weight[i] <= capacity) {
            // If the entire item can be added
            totalValue += profit[i];
            capacity -= weight[i];
        } else {
            // If only a fraction of the item can be added
            totalValue += (double)profit[i] / weight[i] * capacity;
            capacity = 0;
        }
        
    }

    return totalValue;
}
int main() {
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];

    printf("Enter the profit and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    double maxValue = fractionalKnapsack(profit, weight, capacity, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}


/*int main() {
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(profit) / sizeof(profit[0]);
   

    double maxValue = fractionalKnapsack(profit, weight, capacity, n);
    printf("Maximum value: %.2f\n", maxValue);

    return 0;
}*/
