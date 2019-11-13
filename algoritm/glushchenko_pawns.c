#include <stdio.h>
#include <math.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, x = 0, y = 0;
    fscanf(fin, "%d%d%d%d", &x1, &y1, &x2, &y2);

    int x_raz1, x_raz2, y_raz1, y_raz2;
    int mass[8][8] = {0};
    for (x = 1; x <= 8; x++) {
        for (y = 1; y <= 8; y++) {
            x_raz1 = abs(x - x1);
            x_raz2 = abs(x - x2);
            y_raz1 = abs(y - y1);
            y_raz2 = abs(y - y2);

            mass[x_raz1][y_raz1] += 1;
            mass[x_raz2][y_raz2] += 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", mass[i][j]);
        }
        printf("\n");
    }
}
//if ((x_raz1 == y_raz1) && (x_raz2 == y_raz2)) {
//                if (((x > x1) && (x2 > x)) || ((y > y1) && (y2 > y)) || ((x1 > x) && (x > x2)) ||
//                    ((y1 > y) && (y > y2))) {
//                    fprintf(fout, "%i %i", x, y);
//                    return 0;
//                }
//            }