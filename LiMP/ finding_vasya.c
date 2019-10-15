#include <stdio.h>
#include <stdlib.h>

int compare(const void *x1, const void *x2) // функция сравнения элементов массива
{
    return (*(int *) x2 - *(int *) x1); // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int N = 0, M = 0, X = 0, K = 0, L = 0, min = 1, a = 0, d = 0;
    fscanf(fin,"%d%d%d%d", &N, &M, &X, &K);
    int x2 = X, floor = 0;
    int mass[K];
    for (int i = 0; i < K; i++) {
        fscanf(fin,"%d", &mass[i]);
    }

    qsort(mass, K, sizeof(int), compare);

    L = M * mass[0];
    d = L;
    int c = mass[0];

    if (N * M * mass[0] > X) {

        for (int i = 0; i < K; i++) {
            while (L <= x2) {
                min++;
                L += d;
            }
            mass[i] = mass[i] * min;
            if (mass[i] != X) {
                while (X > mass[i]) {
                    floor++;
                    mass[i] += c;
                }
            }

            L = M * mass[i + 1];
            d = L;
            c = mass[i + 1];
            a = floor + a;
            mass[i + 1] = mass[i + 1] * a;
            min = 1;
            x2 = X;
            floor = 0;
        }
        fprintf(fout,"%d", a);
    } else fprintf(fout,"%d", a - 1);


}




