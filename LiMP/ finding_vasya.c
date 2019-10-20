#include <stdio.h>
#include <stdlib.h>

int compare(const void *x1, const void *x2) {
    return (*(int *) x2 - *(int *) x1);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int N = 0, M = 0, X = 0, K = 0;
    fscanf(fin, "%d%d%d%d", &N, &M, &X, &K);

    int mass[K];
    for (int i = 0; i < K; i++) {
        fscanf(fin, "%d", &mass[i]);
    }
    qsort(mass, K, sizeof(int), compare);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <)
    }
}




