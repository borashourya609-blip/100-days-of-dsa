#include <stdio.h>

// check if painting possible within time = mid
int canPaint(int arr[], int n, int k, int mid) {
    int painters = 1;
    int total = 0;

    for (int i = 0; i < n; i++) {
        if (total + arr[i] <= mid) {
            total += arr[i];
        } else {
            painters++;
            total = arr[i];

            if (painters > k)
                return 0;
        }
    }

    return 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    int sum = 0, maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int low = maxVal, high = sum;
    int ans = sum;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;        // feasible → try smaller
            high = mid - 1;
        } else {
            low = mid + 1;    // not feasible → increase
        }
    }

    printf("%d\n", ans);

    return 0;
}