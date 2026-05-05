#include <stdio.h>

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify (max heap)
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Heap Sort
void heapSort(int arr[], int n) {
    // Step 1: Build max heap
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Step 2: Extract elements
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);     // Move max to end
        heapify(arr, i, 0);         // Restore heap
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main() {
    int arr[] = {40, 10, 30, 20, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printArray(arr, n);

    return 0;
}