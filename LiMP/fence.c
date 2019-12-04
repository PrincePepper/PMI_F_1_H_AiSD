#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int index = 0, b1 = 0, b2 = 0;
    fscanf(fin, "%d", &index);
    int mass[index];
    int mass2[index];

    for (int i = 0; i < index; i++) {
        int a;
        fscanf(fin, "%d", &a);
        mass[i] = a;
        mass2[i] = a;
    }

    for (int i = 0; i < index - 1; i += 2) {
        if (mass[i] < mass[i + 1] && mass[i + 1] > mass[i + 2]) {
        } else {
            while (mass[i] >= mass[i + 1]) {
                mass[i + 1]++;
                b1++;
            }
            if (i != index - 2) {
                while (mass[i + 1] <= mass[i + 2]) {
                    mass[i + 1]++;
                    b1++;
                }
            }
        }
    }
    for (int i = 0; i < index - 1; i += 2) {
        if (mass2[i] > mass2[i + 1] && mass2[i + 1] < mass2[i + 2]) {
        } else {
            while (mass2[i] <= mass2[i + 1]) {
                mass2[i]++;
                b2++;
            }
            if (i != index - 2) {
                while (mass2[i + 1] >= mass2[i + 2]) {
                    mass2[i + 2]++;
                    b2++;
                }
            }
        }
    }
    for (int i = 0; i < index; i++) {
        fprintf(fout, "%d ", b2 <= b1 ? mass2[i] : mass[i]);
    }
}