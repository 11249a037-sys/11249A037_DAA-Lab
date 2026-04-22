#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    return ((int*)a)[2] - ((int*)b)[2];
}

int find(int p[], int x) {
    if (p[x] != x)
        p[x] = find(p, p[x]);
    return p[x];
}

void unite(int p[], int r[], int x, int y) {
    if (r[x] < r[y]) p[x] = y;
    else if (r[x] > r[y]) p[y] = x;
    else ( p[y] = x, r[x]++ );
}

void kruskal(int e[][3], int n) {
    int p[n], r[n];
    int i, u, v, cost = 0;

    qsort(e, n, sizeof(e[0]), comp);

    for (i = 0; i < n; i++)
        p[i] = i, r[i] = 0;

    printf("Edges in MST:\n");

    for (i = 0; i < n; i++) {
        u = find(p, e[i][0]);
        v = find(p, e[i][1]);

        if (u != v) {
            unite(p, r, u, v);
            printf("%d - %d = %d\n", e[i][0], e[i][1], e[i][2]);
            cost += e[i][2];
        }
    }

    printf("Total Cost = %d\n", cost);
}

int main() {
    int e[5][3] = {
        {0,1,10},{0,2,6},{0,3,5},
        {1,3,15},{2,3,4}
    };

    kruskal(e, 5);
    return 0;
}
