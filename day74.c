#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000
#define LEN 50

// compare strings for qsort
int cmp(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char votes[MAX][LEN];

    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    // sort votes
    qsort(votes, n, sizeof(votes[0]), cmp);

    char winner[LEN];
    int maxVotes = 0;

    int count = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && strcmp(votes[i], votes[i - 1]) == 0) {
            count++;
        } else {
            // new candidate block ends
            if (count > maxVotes) {
                maxVotes = count;
                strcpy(winner, votes[i - 1]);
            }
            // tie automatically handled by sorting (lex smaller comes first)
            count = 1;
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}