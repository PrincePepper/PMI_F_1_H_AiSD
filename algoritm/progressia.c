#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x2, const void *x1) {
    return (*(int *) x2 - *(int *) x1);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    fscanf(fin, "%d", &N);

    int mass[N];
    int mass2[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
        mass2[i] = 0;
    }
    int d = 0;
    int value = 0;
    int value2 = 0;
    int b = 0;
    int c = 0;
    int j2 = 0;
    int i2 = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            d = abs(mass[j] - mass[i]);
            int a = mass[j];
            for (int g = j + 1; g < N; g++) {
                if (abs(a - mass[g]) == d) {
                    a = mass[g];
                    value++;
                }
            }
            if (value > value2) {
                value2 = value;
                b = a;
                c = d;
                j2 = j;
                mass2[0] = i + 1;
                mass2[1] = j + 1;
            }
            value = 0;

        }
    }

    fprintf(fout, "%d\n", value2 + 2);
    int i = 2;
    for (int g = j2 + 1; g < N; g++) {
        if (abs(b - mass[g]) == c) {
            b = mass[g];
            mass2[i] = g + 1;
            i++;
        }
    }
    qsort(mass2, N, sizeof(int), compare);
    for (i = 0; i < N; i++) {
        if (mass2[i] != 0) fprintf(fout, "%d ", mass2[i]);
    }
}
