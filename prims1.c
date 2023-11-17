#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10

int prims(int g[MAX_VERTICES][MAX_VERTICES], int visit[MAX_VERTICES], int v) {
    int count = 0;
    int i, j;
    visit[0] = 1;
    int s, d;
    int min;
    while (count < v - 1) {
        min = INT_MAX;
        for (i = 0; i < v; i++) {
            if (visit[i] == 1) {
                for (j = 0; j < v; j++) {
                    if (visit[j] == 0 && g[i][j] != 0) {
                        if (g[i][j] < min) {
                            min = g[i][j];
                            s = i;
                            d = j;
                        }
                    }
                }
            }
        }
        visit[d] = 1;
        count++;
        printf("%d <--> %d (weight %d)\n", s, d, g[s][d]);
    }
    return 0;
}

int main() {
    int v;
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    int i, j;
    int g[MAX_VERTICES][MAX_VERTICES];
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &g[i][j]);
        }
    }
    int visit[MAX_VERTICES];
    for (i = 0; i < v; i++) {
        visit[i] = 0;
    }
    prims(g, visit, v);
    return 0;
}
