#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// meeting structure
typedef struct {
    int start, end;
} Meeting;

// compare by start time
int cmp(const void *a, const void *b) {
    return ((Meeting*)a)->start - ((Meeting*)b)->start;
}

// min heap
int heap[MAX], size = 0;

void swap(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

// heapify up
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// heapify down
void heapifyDown(int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;

    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// push end time
void push(int x) {
    heap[size] = x;
    heapifyUp(size);
    size++;
}

// pop min
void pop() {
    heap[0] = heap[--size];
    heapifyDown(0);
}

int main() {
    int n;
    scanf("%d", &n);

    Meeting arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].start, &arr[i].end);
    }

    // sort by start time
    qsort(arr, n, sizeof(Meeting), cmp);

    // first meeting
    push(arr[0].end);

    for (int i = 1; i < n; i++) {
        // if room free
        if (heap[0] <= arr[i].start) {
            pop();
        }

        push(arr[i].end);
    }

    printf("%d\n", size); // number of rooms

    return 0;
}