#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL, *rear = NULL;

// Enqueue: insert at rear (O(1))
void enqueue(int x) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = x;
    node->next = NULL;

    if (rear == NULL) {
        // empty queue
        front = rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
}

// Dequeue: remove from front (O(1))
void dequeue() {
    if (front == NULL) {
        printf("-1\n");
        return;
    }

    struct Node* temp = front;
    printf("%d\n", temp->data);

    front = front->next;

    if (front == NULL) {
        // queue became empty
        rear = NULL;
    }

    free(temp);
}

int main() {
    int N;
    scanf("%d", &N);

    char op[20];
    int x;

    for (int i = 0; i < N; i++) {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &x);
            enqueue(x);
        } else if (strcmp(op, "dequeue") == 0) {
            dequeue();
        }
    }

    return 0;
}