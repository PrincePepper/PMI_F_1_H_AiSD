//
// Created by User on 05.12.2019.
//
#include <stdio.h>

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void ShellSort(int array[], int size) {      // * ∆k = (b∆k−1)/2  ∆0 = N
    int step, i, j;
    // Выбор шага
    for (step = size / 2; step > 0; step /= 2)
        // Перечисление элементов, которые сортируются на определённом шаге
        for (i = step; i < size; i++)
            // Перестановка элементов внутри подсписка, пока i-тый не будет отсортирован
            for (j = i - step; j >= 0 && array[j] > array[j + step]; j -= step) {
                swap(&array[j], &array[j + step]);
            }
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0;
    fscanf(fin, "%d", &N);
    int mass[N];
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }

    ShellSort(mass, N);

    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", mass[i]);
    }
}
