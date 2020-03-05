//
// Created by semyo on 05.03.2020.
//

#include <stdio.h>

int mass[100000];

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void qsort(int left, int right) {
    int l = left, r = right;
    int mid = mass[(((l + r) / 2) + l + r) / 3];
    while (l <= r) {
        while (mass[l] < mid)
            l++;
        while (mass[r] > mid)
            r--;
        if (l <= r)
            swap(&mass[l++], &mass[r--]);
    }
    if (left < r)
        qsort(left, r);
    if (right > l)
        qsort(l, right);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N = 0;

    fscanf(fin, "%d", &N);
    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &mass[i]);
    }

    qsort(0, N - 1);

    for (int i = 0; i < N; i++) {
        fprintf(fout, "%d ", mass[i]);
    }
}
