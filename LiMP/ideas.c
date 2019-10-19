#include <stdio.h>
#include <math.h>

double give(double U, double W, double S, double T) {
    if (U - W == 0) if (S - U * T < 0.00001)return S;

    double t = (S - W * T) / (U - W);

    if (t < 0)t = 0;
    if (t > T)return -1000000;
    if ((t * U) > S) return -1000000;
    return (t * U);
}

double max3(double a, double b) {
    if (a > b && fabs(a - b) >= 0.1) {
        return a;
    } else return b;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    double S = 0, T = 0, u1 = 0, u2 = 0, w1 = 0, w2 = 0;
    fscanf(fin, "%lf %lf %lf %lf %lf %lf", &S, &T, &u1, &u2, &w1, &w2);
    double res = max3(give(u1, w2, S, T),
                      max3(give(u2, w1, S, T),
                           max3(give(u1, w1, S, T), give(u2, w2, S, T))));
    fprintf(fout, "%f", res);
}