#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue
struct Node* queue[100];
int front = 0, rear = -1;

// Enqueue
void enqueue(struct Node* x) {
    queue[++rear] = x;
}

// Dequeue
struct Node* dequeue() {
    return queue[front++];
}

// Check empty
int isEmpty() {
    return front > rear;
}

// Create node
struct Node* createNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

// Build tree
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Right view
void rightView(struct Node* root) {
    if (!root) return;

    enqueue(root);

    while (!isEmpty()) {
        int levelSize = rear - front + 1;

        for (int i = 0; i < levelSize; i++) {
            struct Node* curr = dequeue();

            // last node of level
            if (i == levelSize - 1) {
                printf("%d ", curr->data);
            }

            if (curr->left)
                enqueue(curr->left);
            if (curr->right)
                enqueue(curr->right);
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

    rightView(root);

    return 0;
}