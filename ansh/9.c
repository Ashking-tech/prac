#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (graph[v][i] != 0 && !visited[i]) {
            DFS(i);
        }
    }
}

int isConnected() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    DFS(0);

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            return 0;
    }
    return 1;
}

int main() {
    int edges, u, v, cost;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter number of flight paths: ");
    scanf("%d", &edges);

    printf("Enter flight paths (city1 city2 cost):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &cost);
        graph[u][v] = cost;
        graph[v][u] = cost;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%3d ", graph[i][j]);
        printf("\n");
    }

    if (isConnected())
        printf("\nGraph is Connected.\n");
    else
        printf("\nGraph is Not Connected.\n");

    return 0;
}
