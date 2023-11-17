#include <stdio.h>
#include <limits.h>

void printPath(int parent[], int node) {
    if (parent[node] == -1) {
        printf("  %d", node);
       return;
    }
    printPath(parent, parent[node]);
    printf(" -> %d", node);
}

void dijkstra(int g[][100], int cost[], int parent[], int visit[], int n) {
    for (int k = 0; k < n; k++) {
        int min = INT_MAX, u;
        for (int i = 0; i < n; i++) {
            if (cost[i] < min && visit[i] == 0) {
                min = cost[i];
                u = i;
            }
        }
        visit[u] = 1;
        for (int j = 0; j < n; j++) {
            if (g[u][j] != 0 && visit[j] == 0) { // Changed condition to g[u][j] != 0
                if (cost[j] > g[u][j] + cost[u]) {
                    cost[j] = g[u][j] + cost[u];
                    parent[j] = u; // Update parent array
                }
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    int g[100][100];
    printf("Enter the values into the adjacency matrix (0 for no edge):\n"); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    
    int cost[100], visit[100], parent[100];
    for (int i = 0; i < n; i++) {
        cost[i] = INT_MAX;
        visit[i] = 0;
        parent[i] = -1;
    }
    cost[0] = 0;

    dijkstra(g, cost, parent, visit, n);

    printf("Shortest distances and paths from node 0:\n");
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("vertex %d and  Distance  is = %d, and  Path is  =", i, cost[i]);
        printPath(parent, i);
        printf("\n");
        sum += cost[i];
    }
    printf("Sum of the costs is %d\n", sum);

    return 0;
}
