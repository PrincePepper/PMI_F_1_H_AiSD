#include <stdio.h>
#include <math.h>


int compare(const void *x2, const void *x1) {
    return (*(int *) x2 - *(int *) x1);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    fscanf(fin, "%d", &N);

    int mass[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }

    int d = 0;
    int value = 0;
    int a = 0;
    int value2 = 0, j2 = 0, i2 = 0, d2 = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            d = abs(mass[j] - mass[i]);
            a = mass[j];
            for (int g = j + 1; g < N; g++) {
                if (mass[g] - a == d) {
                    a = mass[g];
                    value++;
                }
            }
            if (value >= value2) {
                value2 = value;
                i2 = i;
                j2 = j;
                d2 = d;
            }
            value = 0;
        }
    }
    fprintf(fout, "%d\n", value2 + 2);//количество всего чисел
    fprintf(fout, "%d ", i2 + 1);// 1 элемент
    fprintf(fout, "%d ", j2 + 1);// 2 элемент
    int aaa = mass[j2];
    for (int g = j2 + 1; g < N; g++) {
        if (mass[g] - aaa == d2) {
            aaa = mass[g];
            fprintf(fout, "%d ", g + 1);
        }
    }
}
