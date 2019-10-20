/*
Long integers library implementation
07.10.2019
*/

#include <stdlib.h>
#include "long_int.h"

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

void copy_LongInt(LongInt *a, const LongInt *b) {
    // are the radixes equal ?
    if (a->radix != b->radix)
        exit(1);

    a->num_digits = b->num_digits;
    int i;
    for (i = 0; i < b->num_digits; i++)
        a->digits[i] = b->digits[i];
}

void add_LongInt(LongInt *a, const LongInt *b) {
    // are the radixes equal ?
    if (a->radix != b->radix)
        exit(1);

    int shift = 0;
    for (int i = 0; i < (a->num_digits > b->num_digits ? a->num_digits : b->num_digits) || shift; i++) {
        if (i == a->num_digits) {
            a->digits[i] = 0;
            a->num_digits++;
        }

        a->digits[i] += shift + (i < b->num_digits ? b->digits[i] : 0);
        shift = a->digits[i] >= a->radix ? 1 : 0;
        a->digits[i] = a->digits[i] - shift * a->radix;
    }

}


void multiply_LongInt_int(LongInt *a, int c) {
    if (c == 0) {
        init_LongInt(a, 0);
        return;
    }
    int shift = 0;
    for (int i = 0; i < a->num_digits || shift; i++) {
        if (i == a->num_digits) {
            a->digits[i] = 0;
            a->num_digits++;
        }

        int temp = shift + a->digits[i] * c;
        a->digits[i] = temp % a->radix;
        shift = temp / a->radix;
    }
}
