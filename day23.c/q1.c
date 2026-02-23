//Merge Two Sorted Linked Lists
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* buildList(int n) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        struct Node* node = newNode(val);
        if (!head) head = tail = node;
        else { tail->next = node; tail = node; }
    }
    return head;
}

struct Node* mergeSorted(struct Node* l1, struct Node* l2) {
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = l1 ? l1 : l2;

    return dummy.next;
}

void printList(struct Node* head) {
    struct Node* curr = head;
    while (curr) {
        if (curr != head) printf(" ");
        printf("%d", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* l1 = buildList(n);

    scanf("%d", &m);
    struct Node* l2 = buildList(m);

    struct Node* merged = mergeSorted(l1, l2);
    printList(merged);

    return 0;
}