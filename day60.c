#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for CBT check
struct Node* queue[100];
int front = 0, rear = -1;

void enqueue(struct Node* x) { queue[++rear] = x; }
struct Node* dequeue() { return queue[front++]; }
int isEmpty() { return front > rear; }

// Create node
struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree (array index method)
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Check heap order
int isMinHeap(struct Node* root) {
    if (!root) return 1;

    if (root->left && root->data > root->left->data)
        return 0;

    if (root->right && root->data > root->right->data)
        return 0;

    return isMinHeap(root->left) && isMinHeap(root->right);
}

// Check complete binary tree
int isComplete(struct Node* root) {
    enqueue(root);
    int seenNull = 0;

    while (!isEmpty()) {
        struct Node* curr = dequeue();

        if (curr == NULL) {
            seenNull = 1;
        } else {
            if (seenNull)
                return 0;

            enqueue(curr->left);
            enqueue(curr->right);
        }
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    if (isComplete(root) && isMinHeap(root))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}