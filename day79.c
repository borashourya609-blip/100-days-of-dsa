#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXV 1005
#define MAXE 20005

// adjacency list (compressed)
int head[MAXV], to[MAXE], wt[MAXE], nxt[MAXE], ecnt;

// add directed edge u->v with weight w
void addEdge(int u, int v, int w) {
    to[ecnt] = v;
    wt[ecnt] = w;
    nxt[ecnt] = head[u];
    head[u] = ecnt++;
}

// min-heap of (dist, node)
typedef struct { int d, u; } Node;
Node heap[MAXE];
int hsz;

// swap
void swap(Node *a, Node *b) { Node t = *a; *a = *b; *b = t; }

// push
void push(Node x) {
    int i = hsz++;
    heap[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].d <= heap[i].d) break;
        swap(&heap[p], &heap[i]);
        i = p;
    }
}

// pop min
Node pop() {
    Node ret = heap[0];
    heap[0] = heap[--hsz];
    int i = 0;
    while (1) {
        int l = 2*i + 1, r = 2*i + 2, s = i;
        if (l < hsz && heap[l].d < heap[s].d) s = l;
        if (r < hsz && heap[r].d < heap[s].d) s = r;
        if (s == i) break;
        swap(&heap[i], &heap[s]);
        i = s;
    }
    return ret;
}

int dist[MAXV];

void dijkstra(int n, int src) {
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;

    dist[src] = 0;
    hsz = 0;
    push((Node){0, src});

    while (hsz) {
        Node cur = pop();
        int u = cur.u, d = cur.d;

        // skip stale entries
        if (d > dist[u]) continue;

        for (int e = head[u]; e != -1; e = nxt[e]) {
            int v = to[e];
            int w = wt[e];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push((Node){dist[v], v});
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // init adjacency
    for (int i = 0; i < n; i++) head[i] = -1;
    ecnt = 0;

    int u, v, w;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        u--; v--; // 1-based → 0-based

        addEdge(u, v, w);
        // if undirected, also:
        // addEdge(v, u, w);
    }

    int src;
    scanf("%d", &src);
    src--;

    dijkstra(n, src);

    // print distances
    for (int i = 0; i < n; i++) {
        printf("%d ", dist[i]);
    }

    return 0;
}