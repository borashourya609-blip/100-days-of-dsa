#include <stdio.h>
#include <string.h>

#define EMPTY -1
#define MAX 100

int table[MAX];
int m;

// Insert using quadratic probing
void insert(int key) {
    for (int i = 0; i < m; i++) {
        int idx = (key % m + i * i) % m;

        if (table[idx] == EMPTY) {
            table[idx] = key;
            return;
        }
    }
}

// Search using quadratic probing
int search(int key) {
    for (int i = 0; i < m; i++) {
        int idx = (key % m + i * i) % m;

        if (table[idx] == EMPTY)
            return 0;  // not found

        if (table[idx] == key)
            return 1;  // found
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);

    scanf("%d", &m);

    // initialize table
    for (int i = 0; i < m; i++)
        table[i] = EMPTY;

    char op[10];
    int key;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            if (search(key))
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
    }

    return 0;
}