/*
Заголовок библиотеки длинных целых
07.10.2019
*/

#ifndef LONG_INT_H_INCLUDED
#define LONG_INT_H_INCLUDED

#define MAX_NUM_DIGITS 10000

typedef struct {
    const int radix; //система счисления
    int num_digits;  // количество цифр
    int digits[MAX_NUM_DIGITS];
    // digits[0..num_digits - 1] цифры длинного целого числа
    // digits[num_digits - 1] != 0
} LongInt;

// Инициализировать длинное целое число a с целым числом val
void init_LongInt(LongInt *a, int val);

// Скопируйте длинное целое число b в длинное целое число a
void copy_LongInt(LongInt *a, const LongInt *b);

// Добавьте длинное целое число b к длинному целому числу a и сохраните результат в a
void add_LongInt(LongInt *a, const LongInt *b);

// Умножьте длинное целое число a на целое число c и сохраните результат в
void multiply_LongInt_int(LongInt *a, int c);

#endif // LONG_INT_H_INCLUDED
