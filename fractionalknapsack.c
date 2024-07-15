#include <stdio.h>

// Function to sort items by value-to-weight ratio in descending order
void sortItems(int values[], int weights[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double r1 = (double)values[j] / weights[j];
            double r2 = (double)values[j + 1] / weights[j + 1];
            if (r1 < r2) {
                // Swap values
                int temp = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp;
                
                // Swap weights
                temp = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = temp;
            }
        }
    }
}

// Function to calculate the maximum value we can get from the given weights and values
double fractionalKnapsack(int W, int values[], int weights[], int n) {
    sortItems(values, weights, n);

    int curWeight = 0;  // Current weight in knapsack
    double finalValue = 0.0;  // Result (value in knapsack)

    for (int i = 0; i < n; i++) {
        if (curWeight + weights[i] <= W) {
            curWeight += weights[i];
            finalValue += values[i];
        } else {
            int remain = W - curWeight;
            finalValue += values[i] * ((double)remain / weights[i]);
            break;
        }
    }

    return finalValue;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    for (int i = 0; i < n; i++) {
        printf("Enter profit and weight for item %d: ", i + 1);
        scanf("%d %d", &values[i], &weights[i]);
    }

    printf("Enter the weight capacity of the knapsack: ");
    scanf("%d", &W);

    printf("Maximum value in Knapsack = %.2f\n", fractionalKnapsack(W, values, weights, n));
    return 0;
}
