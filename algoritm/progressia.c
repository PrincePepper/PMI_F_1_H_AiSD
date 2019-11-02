#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x2, const void *x1) {
    return (*(int *) x2 - *(int *) x1);
}

int bpos[100] = {0};
int pos[100] = {0};
int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N;
    fscanf(fin, "%d", &N);

    int a[N];

    for (int i = 0; i < N; i++) {
        fscanf(fin, "%d", &a[i]);
    }

}
