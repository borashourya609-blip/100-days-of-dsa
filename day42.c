#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, size = 0;

int stack[MAX];
int top = -1;

// Queue operations
void enqueue(int x) {
    if (size == MAX) return;
    rear++;
    queue[rear] = x;
    size++;
}

int dequeue() {
    if (size == 0) return -1;
    int val = queue[front];
    front++;
    size--;
    return val;
}

// Stack operations
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int N, x;

    scanf("%d", &N);

    // Input queue
    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Queue → Stack
    while (size > 0) {
        push(dequeue());
    }

    // Step 2: Stack → Queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    while (front <= rear) {
        printf("%d ", queue[front++]);
    }

    return 0;
}