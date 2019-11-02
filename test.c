#include <stdio.h>
#include <string.h>


#define MAX_NUM_DIGITS 10000

typedef struct {
    const int count;
    int num_digits;  // количество цифр
    int digits[MAX_NUM_DIGITS];
    // digits[0..num_digits - 1] цифры длинного целого числа
    // digits[num_digits - 1] != 0
} LongInt;

int char2digit(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else
        return -1;
}

void add_LongInt(LongInt *a, const LongInt *b) {

    int shift = 0;
    for (int i = 0; i < ((*a).num_digits > (*b).num_digits ? (*a).num_digits : (*b).num_digits) || shift; i++) {
        if (i == (*a).num_digits) {
            (*a).digits[i] = 0;
            (*a).num_digits++;
        }

        (*a).digits[i] += shift + (i < (*b).num_digits ? (*b).digits[i] : 0);
        shift = (*a).digits[i] >= (*a).count ? 1 : 0;
        (*a).digits[i] = (*a).digits[i] - shift * (*a).count;
    }
}


int nod(int N, int K) {
    return K ? nod(K, N % K) : N;
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int N, K;
    fscanf(fin, "%d %d\n", &N, &K);
    char s[MAX_NUM_DIGITS];
    fgets(s, MAX_NUM_DIGITS, fin);
    int len = strlen(s);
    if (s[len - 1] == '\n')
        len--;

    LongInt FIB[201];
    FIB->num_digits = len;

    FIB->digits[0] = 0;
    FIB->digits[1] = 1;
    FIB->digits[2] = 1;
    add_LongInt(&FIB[1], &FIB[2]);
    fprintf(fout, "%d", FIB->digits[1]);


    fclose(fin);
    fclose(fout);
    return 0;
}
