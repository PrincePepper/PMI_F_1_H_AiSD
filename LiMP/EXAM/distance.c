//
// Created by User on 08.01.2020.
//

#include <stdio.h>
#include <math.h>

#define all_numb 4
typedef struct {
    float x1;
    float y1;
    float x2;
    float y2;
} XY;

int main() {
    XY xy;
    scanf("%f", &xy.x1);
    scanf("%f", &xy.y1);
    scanf("%f", &xy.x2);
    scanf("%f", &xy.y2);
    printf("%f", sqrt(pow(xy.x2 - xy.x1, 2) + pow(xy.y2 - xy.y1, 2)));
}
