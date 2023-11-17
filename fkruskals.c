#include <stdio.h>
#include <limits.h>

#define N 10

int i, j, a, b, u, v, k = 1, n;
int min, mincost = 0, g[N][N], parent[N];

int findParent(int i) {
    while (parent[i] != 0)
        i = parent[i];
    return i;
}

int unionSets(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

void kruskalsAlgorithm() {
    while (k < n) {
        for (i = 1, min = INT_MAX; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (g[i][j] < min) {
                    min = g[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        
        u = findParent(u);
        v = findParent(v);

        if (unionSets(u, v)) {
            printf("%d: Edge (%d,%d) = %d\n", k++, a, b, min);
            mincost += min;
        }

        g[a][b] = g[b][a] = INT_MAX;
    }

    printf("Minimum cost of the  MST = %d\n", mincost);
}

int main() {
    printf("Enter the number of vertices (max %d): ", N);
    scanf("%d", &n);
    
    int maxEdges = n * (n - 1) / 2;
    int numEdges;

    printf("Enter the number of edges (maximum %d): ", maxEdges);
    scanf("%d", &numEdges);

    if (numEdges > maxEdges) {
        printf("Invalid number of edges for %d vertices. Maximum allowed edges: %d\n", n, maxEdges);
        return 1;
    }

    printf("Enter the adjacency matrix:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &g[i][j]);
            if (g[i][j] == 0)
                g[i][j] = INT_MAX;
        }
    }

    kruskalsAlgorithm();

    return 0;
}
