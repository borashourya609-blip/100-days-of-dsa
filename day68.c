#include <stdio.h>

#define MAX 100

int adj[MAX][MAX];
int size[MAX];
int indegree[MAX];

// Queue
int queue[MAX];
int front = 0, rear = -1;

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front > rear;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // initialize
    for (int i = 0; i < n; i++) {
        size[i] = 0;
        indegree[i] = 0;
    }

    int u, v;

    // read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // directed edge u -> v
        adj[u][size[u]++] = v;
        indegree[v]++;
    }

    // enqueue all nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            enqueue(i);
    }

    int count = 0;

    // process queue
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for (int i = 0; i < size[u]; i++) {
            int v = adj[u][i];

            indegree[v]--;

            if (indegree[v] == 0)
                enqueue(v);
        }
    }

    // check for cycle
    if (count != n) {
        printf("\nCycle detected\n");
    }

    return 0;
}