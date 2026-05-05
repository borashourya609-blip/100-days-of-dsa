#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX];
    int n;

    // read input until EOF or manually set n
    n = 0;
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    int sum = 0, maxLen = 0;

    // simple hash map (array) with offset for negatives
    int hash[20000];
    for (int i = 0; i < 20000; i++)
        hash[i] = -2;  // -2 means not seen

    int offset = 10000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] != -2) {
            int len = i - hash[sum + offset];
            if (len > maxLen)
                maxLen = len;
        } else {
            hash[sum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}