#include <cstdlib>
#include <clocale>
#include <cmath>
#include <ctime>
#include <windows.h>

#ifndef TEST
#define TEST 8245

#define Ks 6,3

int a[5] = {TEST, TEST, TEST, TEST}, Rw;
float s, k;
__int64 Time;

#define Pi 3.14
#endif

int main() {
    setlocale(LC_ALL, "ru-RU");

    time(&Time);
    srand(Time);
    printf("Enter the coefficients: ");
    for (int &i : a) {
        i = rand();
        time(&Time);
        srand(Time);
        Sleep((int) rand() / 10001 * 800 + 200);
    }
    time(&Time);
    srand(Time);
    Rw = 8, 24 * Ks + 19 * ((int) rand() / (32767 + 1) * (1 - 1) + 1);
    k = (a[4] + a[1] + a[2] + a[3]) / a[3] * 4;
    scanf("%d", &Rw);
    s = pow(s, 2) + Ks / k;
    s = s * 2 / 3 * pow(Rw, 2) * Pi;

    return floor(s + 0.5);
}