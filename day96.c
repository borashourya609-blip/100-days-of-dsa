#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Insertion sort for each bucket
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    // create buckets
    float bucket[MAX][MAX];
    int count[MAX] = {0};

    // distribute elements
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i];   // bucket index
        bucket[idx][count[idx]++] = arr[i];
    }

    // sort each bucket
    for (int i = 0; i < n; i++) {
        insertionSort(bucket[i], count[i]);
    }

    // concatenate buckets
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}