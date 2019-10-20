//
// Created by User on 19.10.2019.
//
#include <stdio.h>
#include <stdlib.h>


int compare(const void *x1, const void *x2) { //компаратор для сортировки массива
    return (*(int *) x1 - *(int *) x2);
}


int main() {

    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int amount_of_elements = 1;

    fscanf(fin, "%d", &amount_of_elements);

    int main_mass[amount_of_elements];
    int two_main_mass[amount_of_elements];


    int count = 0, a = 0;
    fscanf(fin, "%d", &a);
    main_mass[0] = a;
    two_main_mass[0] = a;
    for (int i = 1; i < amount_of_elements; i++) {
        fscanf(fin, "%d", &a);

        main_mass[i] = a;
        two_main_mass[i] = a;

        if (main_mass[0] == main_mass[i]) {
            count++;
        }
    }
    qsort(two_main_mass, amount_of_elements, sizeof(int), compare);

    int array_sums_ascend[amount_of_elements];
    int array_sums_descend[amount_of_elements];
    int amount_ascend_order = 0;
    int amount_descend_order = 0;

    array_sums_ascend[0] = 0;
    array_sums_descend[amount_of_elements - 1] = 0;

    for (int i = 0; i < amount_of_elements; i++) {
        amount_descend_order += two_main_mass[amount_of_elements - 1 - i];
        amount_ascend_order += two_main_mass[i];
        array_sums_ascend[i] = amount_ascend_order;
        array_sums_descend[amount_of_elements - i - 1] = amount_descend_order;
    }

    int array_left_to_right[amount_of_elements];

    int array_right_to_left[amount_of_elements];
    array_left_to_right[0] = 0;
    array_right_to_left[amount_of_elements - 1] = 0;

    int minimal_tricky_number = INT_MAX;

    for (int i = 0; i < amount_of_elements - 1; i++) {
        if (two_main_mass[i] == two_main_mass[i + 1]) {
            array_left_to_right[i] != 0 ? array_left_to_right[i + 1] = array_left_to_right[i]
                                        : (array_left_to_right[i + 1] = 0);
        } else {
            array_left_to_right[i + 1] = array_sums_ascend[i];
        }

        int A = amount_of_elements - i - 2;
        int B = amount_of_elements - i - 1;

        if (two_main_mass[B] == two_main_mass[A]) {

            array_right_to_left[B] != 0 ? array_right_to_left[A] = array_right_to_left[B]
                                        : (array_right_to_left[A] = 0);
        } else {
            array_right_to_left[A] = array_sums_descend[B];
        }
    }
    int N = 0;
    for (int i = 0; i < amount_of_elements; i++) {
        if (abs(array_right_to_left[i] - array_left_to_right[i]) < minimal_tricky_number) {
            minimal_tricky_number = (array_right_to_left[i] - array_left_to_right[i]);
            N = i;
        }
    }

    for (int i = 0; i < amount_of_elements; i++) {
        if (main_mass[i] == two_main_mass[N] ||
            (abs(array_right_to_left[i] - array_left_to_right[i]) == minimal_tricky_number &&
             two_main_mass[i] != two_main_mass[N])) {
            fprintf(fout, "%d ", i + 1);
        }
    }
}