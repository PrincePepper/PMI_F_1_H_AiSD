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
    int temporary = 0;
    for (int i = 0; i < K; i++) {
        fscanf(fin, "%d", &mass[i]);
        if (mass[i] * N * M > X)temporary = 1;
    }
    if (temporary == 1) {
        qsort(mass, K, sizeof(int), compare);
        int mass_etag[N];
        mass_etag[0] = 0;
        int count = 0;
        int podiez = 0;
        int v = 0, v2 = 0;
        int count2 = 0;
        for (int i = 0; i < K; i++) {
            for (int g = 1; g <= N; g++) {
                v = g;
                int a = mass[i] * M * g;
                mass_etag[g - 1] = a;
                podiez = mass_etag[g - 1] - mass[i] * M;
                if (mass_etag[g - 1] >= X) break;
            }
            if (v2 == v) {
                podiez = count2 * mass[i];
            } else count2 = 0;

            while (podiez < X) {

                podiez += mass[i];
                count++;
            }
            count2 = count;
            v2 = v;
        }
        fprintf(fout, "%d", count);
    } else fprintf(fout, "-1");
}