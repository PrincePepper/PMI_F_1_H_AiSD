#include <stdio.h>

FILE *fin, *fout;


int main() {
    fout = fopen("output.txt", "wt");
    fin = fopen("input.txt", "rt");

    int index;
    fscanf(fin, "%d", &index);
    int mass[index];
    int kol=0;
    for (int i = 1; i <= index; i++) {
        fscanf(fin, "%d", &mass[i]);
        if (mass[i]!=i)
            kol++;
    }
    fprintf(fout, "%d\n", kol * 2);

    int empty_file = 0, empty_doc = 0, new_doc = 0;
    for (int i = 1; i <= index; i++) {
        if (mass[i] != i) {
            empty_file = i;
            empty_doc = mass[i];

            fprintf(fout, "-%d %d\n", mass[i], i);

            while (empty_file != empty_doc) {
                new_doc = mass[empty_doc];
                fprintf(fout, "-%d %d\n", new_doc, empty_doc);
                fprintf(fout, "%d %d\n", empty_doc, empty_doc);
                mass[empty_doc] = empty_doc;
                empty_doc = new_doc;
            }
            fprintf(fout, "%d %d\n", empty_file, empty_doc);
            mass[empty_file] = empty_doc;
        }
    }
}