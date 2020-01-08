//
// Created by User on 08.01.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define all_numb 5
typedef struct {
    int x;
    int y;
    int mass[all_numb];
} XY;

int main() {
    XY xy;
    //scanf("%d", &xy.x);
    //scanf("%d", &xy.y);
    xy.x = 0;
    xy.y = 100;
    srand(time(NULL));
    int g = 0;
    int b = 0;
    while (1) {
        for (int i = 0; i < all_numb; i++)
            xy.mass[i] = xy.x + rand() % xy.y;
        for (int i = 0; i < all_numb - 1; i++) {
            for (int j = i + 1; j < all_numb; j++) {
                b = xy.mass[j];

                if (xy.mass[i] == xy.mass[j]) {
                    g = 0;
                    break;
                } else {
                    g = 1;
                }
            }
            if (xy.mass[i] == b) {
                g = 0;
                break;
            }
        }
        if (g != 0) break;
    }
    for (int i = 0; i < all_numb; i++) {
        printf("%d ", xy.mass[i]);
    }
}