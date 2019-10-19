#include <stdio.h>
#include <math.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    fscanf(fin, "%d", &N);

    int mass[N];
    int mass2[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }
    int a = N / 2;
    int b = 0;
    int c = 0;
    int d = 0;
    int v = 0;
    for (int i = 0; i < N; i++) {
        for (int g = 1; g <= a; g++) {
            mass2[c] = mass[i];
            for (int j = g; j <= (N / 2) * g; j += g) {
                if (abs(mass[j] - mass[i] - b) == g + 1) {
                    d = g;
                    c++;
                    mass2[c] = j + 1;
                    b = abs(mass[j] - mass[i]);
                } else {
                    d = 0;
                    break;
                }

            }
            if (d > v)
                v = d;
            b = 0;
            c = 0;
        }
    }
    fprintf(fout, "%d\n", (int) round((double) N / (double) v));
    for (int i = 0; i <= (N / 2) * v; i += v)
        fprintf(fout, "%d ", i + 1);
}
