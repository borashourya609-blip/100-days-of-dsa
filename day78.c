#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize graph with INF
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = INT_MAX;

    int u, v, w;

    // read edges (1-based → 0-based)
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--; v--;

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX], visited[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0; // start from node 0

    int totalWeight = 0;

    for (int count = 0; count < n; count++) {

        // pick minimum key vertex
        int min = INT_MAX, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = 1;
        totalWeight += key[u];

        // update neighbors
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != INT_MAX && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d\n", totalWeight);

    return 0;
}