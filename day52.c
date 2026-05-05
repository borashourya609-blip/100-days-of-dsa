#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = createNode(arr[i]);
    root->left = buildTree(arr, n, 2*i + 1);
    root->right = buildTree(arr, n, 2*i + 2);

    return root;
}

// Find LCA in Binary Tree
struct Node* findLCA(struct Node* root, int a, int b) {
    if (root == NULL)
        return NULL;

    if (root->data == a || root->data == b)
        return root;

    struct Node* left = findLCA(root->left, a, b);
    struct Node* right = findLCA(root->right, a, b);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

int main() {
    int n, a, b;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    scanf("%d %d", &a, &b);

    struct Node* root = buildTree(arr, n, 0);

    struct Node* lca = findLCA(root, a, b);

    if (lca)
        printf("%d\n", lca->data);

    return 0;
}