#include <stdio.h>
#include <limits.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    long long int b = LLONG_MIN;
    long long int a = LLONG_MIN;
    while (!feof(fin)) {
        fscanf(fin, "%lld", &a);
        if (a > b) {
            b = a;
        }
    }
    fprintf(fout, "%lld", a);
}
