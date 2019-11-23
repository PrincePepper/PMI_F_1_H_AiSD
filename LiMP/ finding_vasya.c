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
    int value = 0;
    int etag = 1;
    int count = 0;
    int count2 = 0;
    int count3 = 0;
    for (int i = 0; i < K; i++) {
        if (mass[i] * N * M < X) {
            break;
        }
        int kol = 0;
        int kol2 = 0;
        while (kol < X) {
            kol = mass[i] * M * value;
            value++;
        }
        value -= 2;
        kol2 = mass[i] * M * value;
        while (kol2 < X) {
            kol2 += mass[i];
            count3++;
        }
        value++;
        if (etag == value) {
            count2 += count3 - count;
            count = count3;
        } else {
            count2 += count3;
        }
        count3 = 0;
        etag = value;
        value = 0;
    }
    if (count2 == 0) {
        fprintf(fout, "-1");
    } else {
        fprintf(fout, "%d", count2);
    }
}