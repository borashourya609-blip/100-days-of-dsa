//Doubly Linked List Insertion and Traversal
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node* newNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

int main() {
    int n, val;
    scanf("%d", &n);
    
    struct Node *head = NULL, *tail = NULL;
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    
    for (struct Node* cur = head; cur; cur = cur->next)
        printf("%d%s", cur->data, cur->next ? " " : "\n");
    
    return 0;
}