#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];

    // Initialize matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    int u, v;

    // Read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Convert to 0-based indexing
        u--; 
        v--;

        adj[u][v] = 1;

        // Uncomment this for UNDIRECTED graph
        // adj[v][u] = 1;
    }

    // Print adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}