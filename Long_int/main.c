#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_DIGITS 10000
#define MAX_STR_LEN 1001

typedef struct {
    const int radix;
    int num_digits;  // number of digits
    int digits[MAX_NUM_DIGITS];
    // digits[0..num_digits - 1] are the digits of the long integer
    // digits[num_digits - 1] != 0
} LongInt;

int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

void copy_LongInt(LongInt *a, const LongInt *b) {
    // are the radixes equal ?
    if (a->radix != b->radix)
        exit(1);

    a->num_digits = b->num_digits;
    int i;
    for (i = 0; i < b->num_digits; i++)
        a->digits[i] = b->digits[i];
}

void add_LongInt(LongInt *iInp, const LongInt *iAdd) {
    // are the radixes equal ?
    if (iInp->radix != iAdd->radix)
        exit(1);
    if (iAdd->num_digits > iInp->num_digits) {
        iInp->num_digits = iAdd->num_digits;
    } else if ((iAdd->num_digits == iInp->num_digits) && (iInp->digits[0] + iAdd->digits[0] >= iInp->radix)) {
        iInp->num_digits++;
    }
    for (int i = 0; i < max(iInp->num_digits, iAdd->num_digits); i++) {
        iInp->digits[i] += iAdd->digits[i];
        iInp->digits[i + 1] += (iInp->digits[i] / (iInp->radix));
        iInp->digits[i] %= (iInp->radix);
    }
}

void init_LongInt(LongInt *a, int val) {
    int m = a->radix;

    // is the radix positive ?
    if (m <= 0)
        exit(1);

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

void multiply_LongInt_int(LongInt *iInp, int c) {
    if (c == 0) {
        init_LongInt(iInp, 0);
        return;
    }
    for (int i = 0; i < iInp->num_digits; i++) {
        iInp->digits[i] *= c;
    }
    for (int i = 0; i < iInp->num_digits; i++) {
        iInp->digits[i + 1] = iInp->digits[i] / iInp->radix;
        iInp->digits[i] %= iInp->radix;
    }
    int i = 0;
    while (iInp->digits[i] != 0) {
        iInp->digits[i + 1] = iInp->digits[i] / iInp->radix;
        iInp->digits[i] %= iInp->radix;
    }

}

int ch2digit(char c) {
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    else
        return -1;
}

char digit2ch(int d) {
    if (d >= 0 && d <= 9)
        return '0' + d;
    else if (d >= 10 && d <= 35)
        return 'A' + d - 10;
}

void Read_LongInt(FILE *fin, LongInt *a) {
    int i = 0;
    char buf[MAX_STR_LEN];
    fgets(buf, MAX_STR_LEN, fin);

    int len = strlen(buf);
    for (i = len - 2; i >= 0; i--) {
        a->digits[i] = ch2digit(buf[i]);
    }
    a->num_digits = len - 1;
}

void Print_LongInt(FILE *fout, LongInt a) {
    for (int i = a.num_digits - 1; i >= 0; i--) {
        fprintf(fout, "%c", digit2ch(a.digits[i]));
    }
    fprintf(fout, "\n");
}

void convert(const LongInt *a, LongInt *x) {
    int p = a->radix;
    int q = x->radix;
    int k = a->num_digits - 1;

    LongInt y = {q};
    init_LongInt(x, a->digits[0]);
    init_LongInt(&y, 1);

    LongInt z = {q};
    int i;
    for (i = 1; i <= k; i++) {
        // y = p^{i-1}, x = a[0] + a[1]*p + a[2]*p^2 + ... + a[i-1]*p^{i-1}
        multiply_LongInt_int(&y, p);
        copy_LongInt(&z, &y);
        multiply_LongInt_int(&z, a->digits[i]);
        add_LongInt(x, &z);
        // y = p^i, x = a[0] + a[1]*p + a[2]*p^2 + ... + a[i]*p^i
    }
}

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");
    LongInt a, b;
    int radix1, radix2;
    fscanf(fin, "%d%d\n", &a.radix, &b.radix);
    Read_LongInt(fin, &a);
    Read_LongInt(fin, &b);
    add_LongInt(&a, &b);
    //convert(&a,&a);
    Print_LongInt(fout, a);
    fclose(fin);
    fclose(fout);
    return 0;
}