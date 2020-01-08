//
// Created by User on 08.01.2020.
//
#include <stdio.h>
#include <math.h>

int IsPrime(int N) {
    for (int i = 2; i <= sqrt(N); i++)
        if (N % i == 0)
            return 0;
    if (N < 2)
        return 0;
    return 1;
}

int main() {
    int a, b, c = 0;
    scanf("%d%d", &a, &b);
    for (int i = a; i <= b; i++) {
        if (IsPrime(i)) {
            printf("%d ", i);
            c = 1;
        }
    }
    if (c == 0) printf("0");
}
