//
// Created by User on 08.01.2020.
//
#include <stdio.h>


static int
factorial(int n) {
    if (n < 2) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d", factorial(n));
    }
}
