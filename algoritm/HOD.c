//
// Created by User on 20.10.2019.
//
#include <stdio.h>

int nod(int a, int b) {
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else b = b - a;
    }
    return a;
}

int fib(int n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int n, k;
    fscanf(fin, "%d%d", &n, &k);
    int a = 0, b = 0;
    a = fib(n);
    b = fib(k);
    fprintf(fout, "%d\n", nod(a, b));
}
