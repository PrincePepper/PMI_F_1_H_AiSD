//
// Created by User on 23.11.2019.
//

#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int H = 0, m = 0;
    fscanf(fin, "%d%d", &H, &m);

    if (m == 0) H = 24 - H;
    else {
        H = 24 - 1 - H;
        m = 60 - m;
    }
    fprintf(fout, "%d %d", H, m);
}
