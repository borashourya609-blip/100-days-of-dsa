#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;

// Enqueue
void enqueue(int value) {
    if ((rear + 1) % size == front) {
        return; // full (won't happen here)
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
}

// Dequeue (returns value)
int dequeue() {
    if (front == -1) {
        return -1;
    }

    int value = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % size;
    }

    return value;
}

// Display
void display() {
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % size;
    }
}

int main() {
    int n, m, x;

    scanf("%d", &n);
    size = n;

    // enqueue elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    scanf("%d", &m);

    // rotation logic
    for (int i = 0; i < m; i++) {
        int val = dequeue();
        enqueue(val);
    }

    display();

    return 0;
}