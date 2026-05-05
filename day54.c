#include <stdio.h>
#include <stdlib.h>

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Stack
struct Node* s1[100], *s2[100];
int top1 = -1, top2 = -1;

// Push & Pop helpers
void push1(struct Node* x) { s1[++top1] = x; }
void push2(struct Node* x) { s2[++top2] = x; }

struct Node* pop1() { return s1[top1--]; }
struct Node* pop2() { return s2[top2--]; }

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

// Zigzag traversal
void zigzag(struct Node* root) {
    if (!root) return;

    push1(root);

    while (top1 != -1 || top2 != -1) {

        // Left to Right
        while (top1 != -1) {
            struct Node* curr = pop1();
            printf("%d ", curr->data);

            if (curr->left)  push2(curr->left);
            if (curr->right) push2(curr->right);
        }

        // Right to Left
        while (top2 != -1) {
            struct Node* curr = pop2();
            printf("%d ", curr->data);

            if (curr->right) push1(curr->right);
            if (curr->left)  push1(curr->left);
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

    zigzag(root);

    return 0;
}