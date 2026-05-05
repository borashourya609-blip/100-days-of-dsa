#include <stdio.h>
#include <limits.h>

#define MAX 100

// adjacency list
int adj[MAX][MAX];
int weight[MAX][MAX];
int size[MAX];

// min heap (simple array-based)
int heap[MAX], dist[MAX], pos[MAX];
int heapSize;

// swap helper
void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// heapify up
void heapifyUp(int i) {
    while (i && dist[heap[i]] < dist[heap[(i - 1) / 2]]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < heapSize && dist[heap[l]] < dist[heap[smallest]])
        smallest = l;

    if (r < heapSize && dist[heap[r]] < dist[heap[smallest]])
        smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// insert into heap
void push(int v) {
    heap[heapSize] = v;
    heapifyUp(heapSize);
    heapSize++;
}

// extract min
int pop() {
    int root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

// Dijkstra
void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    heapSize = 0;

    push(src);

    while (heapSize > 0) {
        int u = pop();

        for (int i = 0; i < size[u]; i++) {
            int v = adj[u][i];
            int w = weight[u][i];

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v);
            }
        }
    }

    // print result
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
        size[i] = 0;

    int u, v, w;

    // read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        adj[u][size[u]] = v;
        weight[u][size[u]++] = w;

        // for undirected graph, also add reverse edge
        // adj[v][size[v]] = u;
        // weight[v][size[v]++] = w;
    }

    int src;
    scanf("%d", &src);

    dijkstra(n, src);

    return 0;
}