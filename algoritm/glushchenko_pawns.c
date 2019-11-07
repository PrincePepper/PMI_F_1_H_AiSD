#include <stdio.h>

//
// Created by User on 06.11.2019.
//
const int N = 8;
int mass[8][8] = {0};

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    fscanf(fin, "%d%d%d%d", &x1, &y1, &x2, &y2);
    mass[x1 - 1][y1 - 1] = 1;
    mass[x2 - 1][y2 - 1] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {

        }
    }
}