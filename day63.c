#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list
int adj[MAX][MAX];
int size[MAX];     // number of neighbors per node
int visited[MAX];

// DFS function
void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);   // number of neighbors

        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    dfs(s);

    return 0;
}