//
// Created by User on 08.01.2020.
//

#include <stdio.h>

#ifndef all_numb
#define all_numb 3
int mass[3] = {0};
#endif

int amount() { return mass[0] + mass[1] + mass[2]; }

int composition() { return mass[0] * mass[1] * mass[2]; }

float average() { return (float) (mass[0] + mass[1] + mass[2]) / all_numb; }

int main() {
    //FILE *fin = fopen("input.txt", "r");
    //FILE *fout = fopen("output.txt", "w");
    for (int i = 0; i < all_numb; i++) {
        scanf("%d", &mass[i]);
    }
    printf("%d+%d+%d=%d\n", mass[0], mass[1], mass[2], amount());
    printf("%d*%d*%d=%d\n", mass[0], mass[1], mass[2], composition());
    printf("(%d+%d+%d)/%d=%.3f", mass[0], mass[1], mass[2], all_numb, average());
}