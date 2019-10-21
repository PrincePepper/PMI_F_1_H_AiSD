#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int index_mass = 0, index = 0;
    long int n = 0;
    fscanf(fin, "%d", &index_mass);

    long int mass[index_mass];

    for (int i =0; i < index_mass; i++) {
        fscanf(fin, "%ld", &n);
        if(i>0){
            mass[i] = mass[i - 1] + n;
        }else mass[i]=n;

    }
    int first, second;
    fscanf(fin, "%d", &index);

    long int mass2[index];
    for (int i = 0; i < index; i++) {
        fscanf(fin, "%d%d", &first, &second);

        if (first >= 2) {
            mass2[i] = mass[second - 1] - mass[first - 2];
        } else {
            mass2[i] = mass[second - 1];
        }
        fprintf(fout, "%ld ", mass2[i]);
    }
}