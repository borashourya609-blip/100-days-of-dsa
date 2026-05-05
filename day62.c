#include <stdio.h>
#include <stdlib.h>

// Node for adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Create new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Array of adjacency lists
    struct Node* adj[n];

    // Initialize
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    int u, v;

    // Read edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Convert to 0-based
        u--; 
        v--;

        // Add edge u -> v
        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        // Uncomment for UNDIRECTED graph
        /*
        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
        */
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("%d: ", i + 1);  // print as 1-based
        struct Node* temp = adj[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex + 1);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}