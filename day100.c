#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int pos;
    int speed;
} Car;

// sort by position descending
int cmp(const void *a, const void *b) {
    return ((Car*)b)->pos - ((Car*)a)->pos;
}

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    Car cars[MAX];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].pos);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &cars[i].speed);
    }

    // sort cars by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;

        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // else merges into previous fleet
    }

    printf("%d\n", fleets);

    return 0;
}