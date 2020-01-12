#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int N, M, X, K;
    fscanf(fin, "%d%d%d%d", &N, &M, &X, &K);

    int A, podiezd, floor;
    int *house = (int *) calloc(N + 1, sizeof(int));
    for (int i = 0; i < K; i++) {
        fscanf(fin, "%d", &A);
        podiezd = (X - 1) / (M * A) + 1;
        floor = ((X - (podiezd - 1) * M * A) - 1) / A + 1;

        if ((podiezd - 1) <= N && (floor > house[podiezd])) {
            house[podiezd] = floor;
        }
    }
    int sum = 0;
    for (int i = 0; i < N + 1; i++) {
        sum += house[i];
    }
    if (sum == 0) fprintf(fout, "%s", "-1");
    else fprintf(fout, "%d", sum);

}