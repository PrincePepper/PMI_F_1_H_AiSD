//
// Created by User on 08.01.2020.
//

#include <stdio.h>

int nod(int a, int b) {
    int i = 1;
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else b = b - a;
        i++;
    }
    printf("%d ", a);
    return i;
}

int main() {
    int a = 0, b = 0;
    scanf("%d%d", &a, &b);
    printf("%d\n", nod(a, b));
}
