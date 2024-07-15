#include <stdio.h>

void kruskals();
int cost[10][10], min, i, j, count, k, u, v, n, sum, parent[10];
void union_ij(int, int);
int find(int);

void main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    
    printf("Enter the cost adjacency matrix (enter 9999 for no direct edge):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }
    
    kruskals();
}

void kruskals() {
    count = 0;
    k = 0;
    sum = 0;
    int spanning_tree[10][2]; // Added to store the edges of the spanning tree

    for (i = 0; i < n; i++)
        parent[i] = i;

    while (count != n - 1) {
        min = 999;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < min && cost[i][j] != 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        i = find(u);
        j = find(v);
        if (i != j) {
            spanning_tree[count][0] = u; // Corrected index
            spanning_tree[count][1] = v; // Corrected index
            count++;
            sum += cost[u][v];
            union_ij(i, j);
        }
        cost[u][v] = cost[v][u] = 999; // Avoid picking the same edge again
    }

    printf("Spanning Tree:\n");
    for (i = 0; i < count; i++)
        printf("%d -> %d\n", spanning_tree[i][0], spanning_tree[i][1]);
    printf("Cost = %d\n", sum);
}

void union_ij(int i, int j) {
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

int find(int v) {
    while (parent[v] != v) {
        v = parent[v];
    }
    return v;
}
