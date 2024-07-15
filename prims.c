#include <stdio.h>
#include <float.h>
#define INFINITY 9999

void Prims();
float cost[10][10], sum = 0;
int vis[10], vt[10], et[10][10];
int e = 0, i, j, k, u, v, n, m;

int main() {
    printf("Enter number of vertices\n");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (use %d to represent infinity)\n", INFINITY);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%f", &cost[i][j]);
            if (cost[i][j] == INFINITY) {
                cost[i][j] = INFINITY;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    Prims();
    printf("Minimum spanning tree\n");
    for (i = 1; i < e; i++) {
        printf("%d -> %d\n", et[i][1], et[i][2]);
    }
    printf("Total cost = %.2f\n", sum); // Adjusted to display total cost in decimal
    return 0;
}

void Prims() {
    int x = 1;
    float min;
    vt[x] = 1;
    vis[x] = 1;

    for (i = 1; i < n; i++) { // n-1 edges in a MST for n vertices
        min = FLT_MAX;
        j = x;
        while (j > 0) {
            k = vt[j];
            for (m = 1; m <= n; m++) { // Start from 1 to match user input range
                if (cost[k][m] < min && vis[m] == 0) {
                    min = cost[k][m];
                    u = k;
                    v = m;
                }
            }
            j--;
        }
        vt[++x] = v;
        et[i][1] = u;
        et[i][2] = v;
        
        e++;
        vis[v] = 1;
        sum += cost[u][v];
    }
}
