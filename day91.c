#include <stdio.h>

#define MAX 1000

void merge(int arr[], int left, int mid, int right) {
    int temp[MAX];

    int i = left;
    int j = mid + 1;
    int k = left;

    // merge sorted halves
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    // remaining left half
    while (i <= mid)
        temp[k++] = arr[i++];

    // remaining right half
    while (j <= right)
        temp[k++] = arr[j++];

    // copy back
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}