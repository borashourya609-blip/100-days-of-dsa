#include <stdio.h>

#define MAX 1000

// merge and count inversions
long long merge(int arr[], int left, int mid, int right) {
    int temp[MAX];

    int i = left;
    int j = mid + 1;
    int k = left;

    long long inv = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (mid - i + 1); // key line
        }
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

// merge sort + count
long long mergeSort(int arr[], int left, int right) {
    long long inv = 0;

    if (left < right) {
        int mid = (left + right) / 2;

        inv += mergeSort(arr, left, mid);
        inv += mergeSort(arr, mid + 1, right);

        inv += merge(arr, left, mid, right);
    }

    return inv;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long inversions = mergeSort(arr, 0, n - 1);

    printf("%lld\n", inversions);

    return 0;
}