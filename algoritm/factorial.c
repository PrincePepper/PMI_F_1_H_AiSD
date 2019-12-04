#include <stdio.h>

#define MAX_NUM_DIGITS 100000

typedef struct {
    const int radix; //система счисления
    int num_digits;  // количество цифр
    int digits[MAX_NUM_DIGITS];
    // digits[0..num_digits - 1] цифры длинного целого числа
    // digits[num_digits - 1] != 0
} LongInt;

void multiply_LongInt_int(LongInt *a, int c) {

    int shift = 0;
    for (int i = 0; i < (*a).num_digits || shift; i++) {
        if (i == (*a).num_digits) {
            (*a).digits[i] = 0;
            (*a).num_digits++;
        }

        int temp = shift + (*a).digits[i] * c;
        (*a).digits[i] = temp % (*a).radix;
        shift = temp / (*a).radix;
    }
}

void init_LongInt(LongInt *a, int val) {
    int m = a->radix;

    if (val == 0) {
        a->num_digits = 1;
        a->digits[0] = 0;
        return;
    }

    int i = 0;
    int b = val;
    while (b > 0) {
        a->digits[i++] = b % m;
        b = b / m;
    }
    a->num_digits = i;
}

long long digitalization(LongInt *a) {
    int value = 0;
    for (int i = 0; i < a->num_digits; i++) {
        value += a->digits[i];
        a->digits[i] = 0;
    }
    if (value >= 0 && value <= 9) {
        return value;
    } else {
        init_LongInt(a, value);
        return digitalization(a);
    }
}

long long int ProdTree(int l, int r) {
    if (l > r)
        return 1;
    if (l == r)
        return l;
    if (r - l == 1)
        return l * r;
    int m = (l + r) / 2;
    return ProdTree(l, m) * ProdTree(m + 1, r);
}

long long int FactTree(int n) {
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1 || n == 2)
        return n;

    return ProdTree(2, n);
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    int p, q = 10;
    fscanf(fin, "%d", &p);

    LongInt a = {q};
    a.num_digits = 1;
    a.digits[0] = 1;
    LongInt b = {q};
    init_LongInt(&b, FactTree(p));

    for (int i = 2; i <= p; ++i)
        multiply_LongInt_int(&a, i);
    fprintf(fout, "%lld", digitalization(&a));
}