#include <stdio.h>
#include <stdlib.h>


int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    fscanf(fin, "%d", &N);

    int mass[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }
    int a = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int g = 1; g < N; g++) {
            int b = mass[g] - mass[i];
            for (int j = g; j < N; j += g) {
                if (b ==mass[g]-mass[j]){
                    a++;
                }else a=0;
            }
        }
    }
}
