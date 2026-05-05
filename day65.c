#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list (simple array-of-lists via fixed arrays)
int adj[MAX][MAX];
int size[MAX];
int visited[MAX];

// DFS with parent tracking
int dfs(int u, int parent) {
    visited[u] = 1;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            if (dfs(v, u))
                return 1;
        }
        else if (v != parent) {
            return 1; // cycle detected
        }
    }
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
    }

    int u, v;

    // read edges (undirected)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // assuming 0-based input; if 1-based → do u--, v--

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    // check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}