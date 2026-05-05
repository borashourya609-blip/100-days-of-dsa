#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));

    int max = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        if (arr[i] < 0) {
            printf("Negative numbers not allowed\n");
            return 0;
        }

        if (arr[i] > max)
            max = arr[i];
    }

    // dynamic count array
    int *count = (int*)calloc(max + 1, sizeof(int));
    int *output = (int*)malloc(n * sizeof(int));

    // frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // stable placement
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    // print
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    free(arr);
    free(count);
    free(output);

    return 0;
}