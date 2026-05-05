#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];
int recStack[MAX];

// DFS for cycle detection
int dfs(int u) {
    visited[u] = 1;
    recStack[u] = 1;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            if (dfs(v))
                return 1;
        }
        else if (recStack[v]) {
            return 1; // cycle detected
        }
    }

    recStack[u] = 0; // backtrack
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        visited[i] = 0;
        recStack[i] = 0;
    }

    int u, v;

    // directed edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // assuming 0-based input; if 1-based → u--, v--
        adj[u][size[u]++] = v;
    }

    // check all components
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}