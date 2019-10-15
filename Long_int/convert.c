#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "long_int.h"

#define MAX_STR_LEN 1001

int ch2digit (char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else
        return -1;
}

char digit2ch (int d)
{
    if (d >= 0 && d <= 9)
        return '0' + d;
    else if (d >= 10 && d <= 35)
        return 'A' + d - 10;
}

void convert (const LongInt* a, LongInt* x)
{
    int p = a->radix;
    int q = x->radix;
    int k = a->num_digits - 1;

    LongInt y = { q };
    init_LongInt(x, a->digits[0]);
    init_LongInt(&y, 1);

    LongInt z = { q };
    int i;
    for (i = 1; i <= k; i++) {
        // y = p^{i-1}, x = a[0] + a[1]*p + a[2]*p^2 + ... + a[i-1]*p^{i-1}
        multiply_LongInt_int(&y, p);
        copy_LongInt(&z, &y);
        multiply_LongInt_int(&z, a->digits[i]);
        add_LongInt(x, &z);
        // y = p^i, x = a[0] + a[1]*p + a[2]*p^2 + ... + a[i]*p^i
    }
    // y = p^k, x = a[0] + a[1]*p + a[2]*p^2 + ... + a[k]*p^k
}

int main ()
{
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w");

    // Input data
    int p, q;
    char s[MAX_STR_LEN];
    fscanf(fin, "%d %d\n", &p, &q);
    fgets(s, MAX_STR_LEN, fin);
    int len = strlen(s);
    if (s[len - 1] == '\n')
        len--;

    // Initialize a long number
    LongInt a = { p };
    a.num_digits = len;
    int i;
    for (i = 0; i < len; i++)
        a.digits[len - 1 - i] = ch2digit(s[i]);

    // Convert the long number to another radix
    LongInt b = { q };
    convert(&a, &b);

    // Output data
    for (i = b.num_digits - 1; i >= 0; i--) {
        fprintf(fout, "%c", digit2ch(b.digits[i]));
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
