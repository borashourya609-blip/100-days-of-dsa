#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    int max = 0;

    // input + find max
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max)
            max = arr[i];
    }

    int count[MAX] = {0};
    int output[MAX];

    // frequency count
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // prefix sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // build output (right → left for stability)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }

    // print sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}