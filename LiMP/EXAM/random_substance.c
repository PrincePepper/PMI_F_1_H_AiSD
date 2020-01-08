//
// Created by User on 08.01.2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define all_numb 5
typedef struct {
    float x;
    float y;
} XY;

int main() {
    XY xy;
    scanf("%f", &xy.x);
    scanf("%f", &xy.y);
    srand(time(NULL));
    for (int i = 0; i < all_numb; i++) {
        printf("%.3f ", xy.x + fmodf(rand(), xy.y));
    }
    /* int i = 0;
     int g=10;
     int i2=0;
     while (1) {
         float a = xy.y / rand();
         int b = 0;
         while (1) {
             b = a;
             if (b != 0) break;
             a = a * 10;
         }
         if(i2>5){
             g*=10;
             i2=0;
         }
         a = a / g;
         b = xy.x + rand() % ((int) xy.y);
         if (i == all_numb)break;
         float c = a + b;
         if (xy.y > c && fabs(xy.y - c) >= 0.00000001) {
             printf("%.3f ", c);
             i++;
         }
         i2++;
     }*/
}