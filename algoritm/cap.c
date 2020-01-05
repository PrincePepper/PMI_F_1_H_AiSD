//
// Created by User on 05.01.2020.
//
#include <stdio.h>

#define Pi 3.14159265

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int R, L;
    fscanf(fin, "%d%d", &R, &L);

    double length_circle = 2 * Pi * R;
    double area_circle = Pi * R * R;
    fprintf(fout, "%f", length_circle * R + (Pi * R * (R + L) / 2) - area_circle);
}
