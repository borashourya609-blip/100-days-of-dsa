#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];

// DFS
void dfs(int u) {
    visited[u] = 1;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
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

    // read edges (1-based → convert to 0-based)
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        u--; v--;

        adj[u][size[u]++] = v;
        adj[v][size[v]++] = u;
    }

    int components = 0;

    // check all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    printf("%d\n", components);

    return 0;
}