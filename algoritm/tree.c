#include <stdio.h>


int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int s = 0;
    int index = 0;
    int x = 0;
    fscanf(fin, "%d%d", &index, &s);
    int mass[index];
    for (int i = 0; i < s; ++i) {
        fscanf(fin, "%d", &mass[i]);
    }
    int m = 0, sm = 0, ia = 0;
    for (int i = s; i < index; i++) {
        fscanf(fin, "%d", &x);
        if (mass[ia] > m) {
            m = mass[ia];
        }
        if (m + x > sm) {
            sm = m + x;
        }
        mass[ia] = x;
        ia = (ia + 1) % s;
    }
    fprintf(fout,"%d",sm);
}
