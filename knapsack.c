

#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
  return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapSack(int W, int wt[], int profit[], int n, int chosenItems[])
{
  int i, w;
  int **K = (int **)malloc((n + 1) * sizeof(int *));
  for (i = 0; i <= n; i++)
  {
    K[i] = (int *)malloc((W + 1) * sizeof(int));
  }

  // Build table K[][] in bottom up manner
  for (i = 0; i <= n; i++)
  {
    for (w = 0; w <= W; w++)
    {
      if (i == 0 || w == 0)
        K[i][w] = 0;
      else if (wt[i - 1] <= w)
        K[i][w] = max(profit[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
      else
        K[i][w] = K[i - 1][w];
    }
  }

  int result = K[n][W];
  w = W;

  // Trace the items included in the knapsack
  for (i = n; i > 0 && result > 0; i--)
  {
    if (result == K[i - 1][w])
      continue; // Item i was not included
    else
    {
      chosenItems[i - 1] = 1; // Item i was included
      result -= profit[i - 1];
      w -= wt[i - 1];
    }
  }

  // Get the result before freeing memory
  int maxProfit = K[n][W];

  // Free the allocated memory
  for (i = 0; i <= n; i++)
  {
    free(K[i]);
  }
  free(K);

  return maxProfit;
}

int main()
{
  int n, W;

  // Take input for the number of items
  printf("Enter the number of items: ");
  scanf("%d", &n);

  int *profit = (int *)malloc(n * sizeof(int));
  int *wt = (int *)malloc(n * sizeof(int));
  int *chosenItems = (int *)calloc(n, sizeof(int));

  // Take input for the profits and weights of the items
  printf("Enter the profits and weights of the items:\n");
  for (int i = 0; i < n; i++)
  {
    printf("Item %d - Profit: ", i + 1);
    scanf("%d", &profit[i]);
    printf("Item %d - Weight: ", i + 1);
    scanf("%d", &wt[i]);
  }

  // Take input for the maximum weight of the knapsack
  printf("Enter the maximum weight of the knapsack: ");
  scanf("%d", &W);

  // Calculate the maximum profit that can be obtained
  int maxProfit = knapSack(W, wt, profit, n, chosenItems);
  printf("Maximum profit in Knapsack = %d\n", maxProfit);

  // Print the items chosen
  printf("Items chosen (1-based index): ");
  for (int i = 0; i < n; i++)
  {
    if (chosenItems[i])
    {
      printf("%d ", i + 1);
    }
  }
  printf("\n");

  // Free the allocated memory
  free(profit);
  free(wt);
  free(chosenItems);

  return 0;
}