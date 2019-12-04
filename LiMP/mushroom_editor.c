#include <stdio.h>
#include <string.h>
int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int A, B, max = 0, point = 0;

    char cheakpoint = '*';
    char grid = '#';
    char tochka = '.';

    fscanf(fin, "%d%d", &A, &B);
    char str_1[B + 3];
    char str_2[B + 3];
    fscanf(fin, "%s", str_1);
    for (int i = 1; i < A; i++) {
        fscanf(fin, "%s", str_2);
        for (int j = 0; str_1[j] != '\0'; j++) {
            if (str_2[j] == tochka || str_2[j] == cheakpoint || str_2[j] == '\0') {
                point = 0;
            }
            if (str_1[j] == cheakpoint && str_2[j] == grid && point == 0) {
                max++;
                point++;
            }
        }
        strcpy(str_1, str_2);
        point = 0;
    }
    printf("%d", max);
    fprintf(fout, "%d", max);
}