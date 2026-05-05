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

// Insert into BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Find LCA in BST
struct Node* findLCA(struct Node* root, int a, int b) {
    if (root == NULL) return NULL;

    if (a < root->data && b < root->data)
        return findLCA(root->left, a, b);

    if (a > root->data && b > root->data)
        return findLCA(root->right, a, b);

    return root; // split point
}

int main() {
    int n, x, a, b;
    scanf("%d", &n);

    struct Node* root = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &a, &b);

    struct Node* lca = findLCA(root, a, b);

    if (lca)
        printf("%d\n", lca->data);

    return 0;
}