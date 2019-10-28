#include <stdio.h>
#include <limits.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0;
    int max = INT_MIN;
    int value = 0;
    fscanf(fin, "%d", &N);
    int mass[N][3];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d%d%d", &mass[i][0], &mass[i][1], &mass[i][2]);
    }
    for (int i = 0; i < N; i++) {
        if ((mass[i][0] + mass[i][1] + mass[i][2]) >= max) {
            max = (mass[i][0] + mass[i][1] + mass[i][2]);
        }
    }
    for (int i = 0; i < N; i++) {
        if ((mass[i][0] + mass[i][1] + mass[i][2]) == max) {
            value++;
        }
    }
    fprintf(fout, "%d ", value);
    for (int i = 0; i < N; i++) {
        if ((mass[i][0] + mass[i][1] + mass[i][2]) == max) {
            fprintf(fout, "%d ", i + 1);
        }
    }
}
