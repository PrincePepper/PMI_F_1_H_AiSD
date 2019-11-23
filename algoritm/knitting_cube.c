//
// Created by User on 23.11.2019.
//

#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int N = 0;
    fscanf(fin, "%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int g = 0; g < N; g++) {
                fprintf(fout, "%d ", ((i + j + g) % N) + 1);
            }
            fprintf(fout, "\n");
        }
    }
}

