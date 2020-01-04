#include <stdio.h>
#include <limits.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0;
    int value = 0;

    fscanf(fin, "%d", &N); //кол-во человек

    int max_prog = INT_MIN, max_match = INT_MIN, max_teach = INT_MIN, max = INT_MIN;

    int mass[N][3];
    for (int i = 0; i < N; i++) { //нахождения максимума
        fscanf(fin, "%d%d%d", &mass[i][0], &mass[i][1], &mass[i][2]);
        if (mass[i][0] > max_prog) max_prog = mass[i][0];
        if (mass[i][1] > max_match) max_match = mass[i][1];
        if (mass[i][2] > max_teach) max_teach = mass[i][2];
    }
    for (int i = 0; i < N; i++) {
        int max_students = mass[i][0] + mass[i][1] + mass[i][2];

        if (max_students == max_prog) value++;

        else if (max_students == max_match) value++;

        else if (max_students == max_match) value++;

        else if (mass[i][0] == max_match || mass[i][0] == max_prog || mass[i][0] == max_teach) value++;
    }

    fprintf(fout, "%d", value);
    for (int i = 0; i < N; i++) {
        int max_students = mass[i][0] + mass[i][1] + mass[i][2];

        if (max_students == max_prog || max_students == max_match || max_students == max_match)
            fprintf(fout, " %d", i + 1);

        else if (mass[i][0] == max_match || mass[i][0] == max_prog || mass[i][0] == max_teach)
            fprintf(fout, " %d", i + 1);
    }
}