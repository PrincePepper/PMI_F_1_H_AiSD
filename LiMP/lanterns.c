#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int mass[100] = {0};
    int kol = 0;
    int max = 1;
    int value = 0;
    int H = 0, S = 0;
    fscanf(fin, "%d", &kol);
    for (int j = 0; j < kol; j++) {
        fscanf(fin, "%d%d", &S, &H);
        if (abs(S - H) >= 0) {
            if (S - H < 0) {
                mass[0] += 1;
            } else
                mass[S - H] += 1;
        }
        if (S + H < 100) {
            mass[S + H] -= 1;
        }
    }
    for (int i = 0; i < 100; i++) {
        value += mass[i];
        if (value > max)
            max = value;
    }
    fprintf(fout, "%d", max);
}
