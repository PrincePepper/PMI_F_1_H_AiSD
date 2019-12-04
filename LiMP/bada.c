#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int A, B, max = 0;
    fscanf(fin, "%d%d", &A, &B);
    while (A > 0) {
        int new_B = B;
        if (B > A) {
            new_B = A;
        }
        A = A - new_B;
        max = max + new_B + 1;
    }
    fprintf(fout, "%d", max);
}