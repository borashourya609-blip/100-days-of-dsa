#include <stdio.h>

// Lower Bound: first index where arr[i] >= x
int lower_bound(int arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

// Upper Bound: first index where arr[i] > x
int upper_bound(int arr[], int n, int x) {
    int left = 0, right = n;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }

    return left;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int x;
    scanf("%d", &x);

    int lb = lower_bound(arr, n, x);
    int ub = upper_bound(arr, n, x);

    printf("%d %d\n", lb, ub);

    return 0;
}