#include <stdio.h>
 
#define V 4
#define INF 99999
 
void printSolution(int dist[][V]);
 
void floydWarshall(int dist[][V])
{
    int i, j, k;
 
    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
 
    printSolution(dist);
}
 
void printSolution(int dist[][V])
{
    printf(
        "The following matrix shows the shortest distances"
        " between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
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
    int graph[V][V];

    // Taking user input for edge weights
    printf("Enter the graph's edge weights:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == 0) {
                if (i != j) { // Set non-diagonal 0 weights to INF for correct computation
                    graph[i][j] = INF;
                }
            }
        }
    }
 
    floydWarshall(graph);
    return 0;
}
