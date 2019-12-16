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
    int mass_etag[N];
    mass_etag[0] = 0;
    int count = 0;
    int podiez = 0;
    for (int i = 0; i < K; i++) {
        for (int g = 1; g <= N; g++) {
            int a = mass[i] * M * g;

            mass_etag[g - 1] = a;
            podiez = mass_etag[g - 1] - mass[i] * M;
            if (mass_etag[g - 1] >= X) break;
        }
        while (podiez < X) {
            podiez += mass[i];
            count++;
        }
    }
    fprintf(fout, "%d", count);
}




