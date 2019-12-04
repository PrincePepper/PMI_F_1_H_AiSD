#include <stdio.h>
#include <math.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int x1, x2, y1, y2, tochka_x, tochka_y;
    int center_x, center_y, a = 0, b = 0, x3, y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &tochka_x, &tochka_y);
    fscanf(fin, "%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &tochka_x, &tochka_y);

    center_x = (x2 + x1) / 2;
    center_y = (y2 + y1) / 2;
    a = pow(center_x - tochka_x, 2) + pow(center_y - tochka_y, 2);

    if (center_y > tochka_y) {
        if (y1 > y2) {
            y3 = y2;
        } else y3 = y1;
    } else {
        if (y1 > y2) {
            y3 = y1;
        } else y3 = y2;
    }
    if (center_x > tochka_x) {
        if (x1 > x2) {
            x3 = x2;
        } else x3 = x1;
    } else {
        if (x1 > x2) {
            x3 = x1;
        } else x3 = x2;
    }
    b = pow(tochka_x - x3, 2) + pow(tochka_y - y3, 2);

    if (a <= b) {
        fprintf(fout, "CENTER");
        printf("CENTER");
    } else {
        fprintf(fout, "CORNER");
        printf("CORNER");
    }
}
