#include <stdio.h>
#include <string.h>

#define MAX_PROGRESS 101

int main() {
    int N;
    FILE *infile = fopen("input.txt", "r");
    fscanf(infile, "%d", &N);
    N++;
    int a[MAX_PROGRESS];
    int b[MAX_PROGRESS] = {0};
    int c[MAX_PROGRESS];
    for (int i = 1; i < N; i++) {
        fscanf(infile, "%d", &a[i]);
    }
    fclose(infile);
    int raznost = 0;
    int M = 0;
    int M1 = 0;
    int p;
    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            raznost = a[i] - a[j];
            p = a[i];
            for (int g = i + 1; g < N; g++) {
                if (p - a[g] == raznost) {
                    M1++;
                    b[i] = a[i];
                    b[g] = a[g];
                    p = a[g];
                }
            }
            if (M1 > M) {
                memcpy(c, b, 4 * N);
                M = M1;
            }
            M1 = 0;
            memset(b, 0, 404);
        }
    }

    FILE *outfile = fopen("output.txt", "w");
    fprintf(outfile, "%d\n", ++M);
    for (int i = 0; i < N; i++) {
        if (c[i] != 0) {
            fprintf(outfile, "%d ", i);
        }
    }
    fclose(outfile);
}