#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int visited[MAX];

// Queue
int queue[MAX];
int front = 0, rear = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// BFS
void bfs(int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int i = 0; i < size[u]; i++) {
            int v = adj[u][i];

            if (!visited[v]) {
                visited[v] = 1;   // mark here!
                enqueue(v);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    // Input adjacency list
    for (int i = 0; i < n; i++) {
        scanf("%d", &size[i]);

        for (int j = 0; j < size[i]; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    int s;
    scanf("%d", &s);

    // Initialize visited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    bfs(s);

    return 0;
}