#include <stdio.h>

#include <string.h>


int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    fscanf(fin, "%d", &N);
    N++;
    int mass[N];
    int mass2[101] = {0};
    int mass3[101] = {0};

    for (int i = 1; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }

    int d = 0;
    int value = 0;
    int a = 0;
    int value2 = 0;

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            d = mass[i] - mass[j];
            a = mass[i];

            for (int g = i + 1; g < N; g++) {

                if (a - mass[g] == d) {
                    mass2[i] = mass[i];
                    mass2[g] = mass[g];
                    a = mass[g];
                    value++;
                }
            }
            if (value > value2) {
                memcpy(mass3, mass2, 4 * N);
                value2 = value;
            }
            value = 0;
            memset(mass2, 0, 404);
        }
    }
    fprintf(fout, "%d\n", ++value2);
    for (int i = 0; i < N; i++) {
        if (mass3[i] != 0) {
            fprintf(fout, "%d ", i);
        }
    }
}
