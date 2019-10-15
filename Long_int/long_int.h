/*
Long integers library header
07.10.2019
*/

#ifndef LONG_INT_H_INCLUDED
#define LONG_INT_H_INCLUDED

#define MAX_NUM_DIGITS 10000

typedef struct {
    const int radix;
    int num_digits;  // number of digits
    int digits[MAX_NUM_DIGITS];
    // digits[0..num_digits - 1] are the digits of the long integer
    // digits[num_digits - 1] != 0
} LongInt;

// Initialize long integer  a  with integer  val
void init_LongInt (LongInt* a, int val);
// Copy long integer  b  to long integer  a
void copy_LongInt (LongInt* a, const LongInt* b);
// Add long integer  b  to long integer  a  and save the result to  a
void add_LongInt (LongInt* a, const LongInt* b);
// Multiply long integer  a  by integer  c  and save the result to  a
void multiply_LongInt_int (LongInt* a, int c);

#endif // LONG_INT_H_INCLUDED
