#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int dq[MAX];
int front = -1, rear = -1, size = 0;

// Check empty
int empty() {
    return size == 0;
}

// Push front
void push_front(int x) {
    if (size == MAX) return;

    if (empty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }
    dq[front] = x;
    size++;
}

// Push back
void push_back(int x) {
    if (size == MAX) return;

    if (empty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    dq[rear] = x;
    size++;
}

// Pop front
void pop_front() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    size--;
}

// Pop back
void pop_back() {
    if (empty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", dq[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
    size--;
}

// Front element
void get_front() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[front]);
}

// Back element
void get_back() {
    if (empty()) printf("-1\n");
    else printf("%d\n", dq[rear]);
}

// Display deque
void display() {
    if (empty()) return;

    int i = front;
    while (1) {
        printf("%d ", dq[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    char op[20];
    int x;

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "push_front") == 0) {
            scanf("%d", &x);
            push_front(x);
        }
        else if (strcmp(op, "push_back") == 0) {
            scanf("%d", &x);
            push_back(x);
        }
        else if (strcmp(op, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(op, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(op, "front") == 0) {
            get_front();
        }
        else if (strcmp(op, "back") == 0) {
            get_back();
        }
        else if (strcmp(op, "size") == 0) {
            printf("%d\n", size);
        }
        else if (strcmp(op, "empty") == 0) {
            printf("%d\n", empty());
        }
        else if (strcmp(op, "display") == 0) {
            display();
        }
    }

    return 0;
}