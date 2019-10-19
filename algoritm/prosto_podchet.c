//
// Created by User on 19.10.2019.
//

#include <stdio.h>
#include <math.h>

int main() {
    FILE *fin = fopen("test14.in", "r");
    FILE *fout = fopen("test14.out", "w");

    float columns = 0, strings = 0, cell_color = 0;
    fscanf(fin, "%f%f%f", &columns, &strings, &cell_color);

    float a = 0;
    if (strings < columns && strings < 5) {//меняем местами строки истолбцы если они не меньше шаблона
        a = strings;
        strings = columns;
        columns = a;
    }
    if ((strings >= 5 && columns >= 2) || (cell_color == 0 && strings >= 5 && columns >= 2)) {

        float answer = 0;
        if ((int) strings % 2 == 0) {

            answer = (columns - 1) * (strings / 2 - 2);
            fprintf(fout, "%d", (int) answer);
            return 0;
        }
        float g = 0, f = 0;
        g = ceilf(columns / 2);
        f = columns - g;
        g--; // вычитаем т.к. в последней строке не будет шаблон полностью удовлетворен требованиям
        if (cell_color == 0) {
            answer = g * floorf(strings / 2 - 2) + f * floorf(strings / 2 - 1);
        } else {
            answer = g * floorf(strings / 2 - 1) + f * floorf(strings / 2 - 2);
        }

        fprintf(fout, "%d", (int) answer);

    } else fprintf(fout, "NO");
    return 0;
}