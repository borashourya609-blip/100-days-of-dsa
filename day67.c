#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

// Push to stack
void push(int x) {
    stack[++top] = x;
}

// DFS
void dfs(int u) {
    visited[u] = 1;

    for (int i = 0; i < size[u]; i++) {
        int v = adj[u][i];

        if (!visited[v]) {
            dfs(v);
        }
    }

    // push AFTER visiting neighbors
    push(u);
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

    // directed edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // assuming 0-based input
        adj[u][size[u]++] = v;
    }

    // DFS from all nodes
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    // print topological order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}