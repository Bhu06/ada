#include <stdio.h>

#define INF 99999
#define MAX 10

void floydWarshall(int dist[][MAX], int n)
{
  int i, j, k;

  for (k = 0; k < n; k++)
  {
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < n; j++)
      {
        if (dist[i][j] > dist[i][k] + dist[k][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

void printMatrix(int dist[][MAX], int n)
{
  int i, j;
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (dist[i][j] == INF)
        printf("%7s", "INF");
      else
        printf("%7d", dist[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int n;
  printf("Enter the number of vertices (maximum %d): ", MAX);
  scanf("%d", &n);
  
  if(n <= 0 || n > MAX) {
    printf("Invalid number of vertices.\n");
    return 1; // Exiting with error
  }

  int dist[MAX][MAX];
  printf("Enter the adjacency matrix (enter %d for infinity):\n", INF);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &dist[i][j]);
      // Ensure a direct edge has a positive weight, otherwise set it to INF
      if (i != j && dist[i][j] <= 0)
        dist[i][j] = INF; 
    }
  }

  floydWarshall(dist, n);

  printf("The shortest distances between every pair of vertices:\n");
  printMatrix(dist, n);

  return 0;
}
