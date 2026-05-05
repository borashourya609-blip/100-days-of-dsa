#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue node with HD
struct QNode {
    struct Node* node;
    int hd;
};

// Create node
struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree from level-order
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);
    return root;
}

// Vertical Order Traversal
void verticalOrder(struct Node* root) {
    if (!root) return;

    struct QNode queue[100];
    int front = 0, rear = 0;

    int hdNodes[200][100]; // store nodes per HD
    int count[200] = {0};

    int offset = 100; // to handle negative HD

    // enqueue root
    queue[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd + offset;

        hdNodes[hd][count[hd]++] = curr->data;

        if (curr->left)
            queue[rear++] = (struct QNode){curr->left, temp.hd - 1};
        if (curr->right)
            queue[rear++] = (struct QNode){curr->right, temp.hd + 1};
    }

    // print from leftmost to rightmost
    for (int i = 0; i < 200; i++) {
        if (count[i] > 0) {
            for (int j = 0; j < count[i]; j++) {
                printf("%d ", hdNodes[i][j]);
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}