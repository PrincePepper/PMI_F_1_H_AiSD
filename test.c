#include <stdio.h>


int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    long long int a = 1000000000000000000;
    printf("%lld", a % 10);
}
