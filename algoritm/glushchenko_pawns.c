#include <stdio.h>
#include <math.h>
int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int x1, x2, y1, y2, x, y, x_raz1, y_raz1, x_raz2, y_raz2;
    fscanf(fin, "%i%i%i%i", &x1, &y1, &x2, &y2);

    for (x = 1; x <= 8; x++) {
        for (y = 1; y <= 8; y++) {
            x_raz1 = abs(x - x1);
            x_raz2 = abs(x - x2);
            y_raz1 = abs(y - y1);
            y_raz2 = abs(y - y2);
            if ((x_raz1 == y_raz1) && (x_raz2 == y_raz2)) {
                if (((x > x1) && (x2 > x)) || ((y > y1) && (y2 > y)) || ((x1 > x) && (x > x2)) ||
                    ((y1 > y) && (y > y2))) {
                    fprintf(fout, "%i %i", x, y);
                    return 0;
                }
            }
        }
    }
}