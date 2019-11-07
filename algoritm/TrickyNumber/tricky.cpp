/*
Задача "Хитрый член"
*/

#include <cmath>

/*
Вход :
    n - длина последовательности (n >= 1)
    a[0..n-1] - последовательность натуральных чисел
Выход :
    m - длина последовательности "хитрых" индексов
    tricky_indices[0..m-1] - последовательность "хитрых" индексов
      (индексы от 1 до n)
*/
int compare(const void *x1, const void *x2) { //компаратор для сортировки массива
    return (*(int *) x1 - *(int *) x2);
}

void get_tricky_numbers(int amount_of_elements, const int main_mass[], int *m, int tricky_indices[]) {
    int a = 0;
    int two_main_mass[amount_of_elements];
    for (int i = 0; i < amount_of_elements; i++) {
        two_main_mass[i] = main_mass[i];
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
    int N2 = -1;
    for (int i = 0; i < amount_of_elements; i++) {
        if (abs(array_right_to_left[i] - array_left_to_right[i]) < minimal_tricky_number) {
            minimal_tricky_number = abs(array_right_to_left[i] - array_left_to_right[i]);
            N = i;
        }
    }
    for (int i = 0; i < amount_of_elements; i++) {
        if (abs(array_right_to_left[i] - array_left_to_right[i]) == minimal_tricky_number) {
            N2 = i;
        }
    }

    for (int i = 0; i < amount_of_elements; i++) {
        if (main_mass[i] == two_main_mass[N] || (main_mass[i] == two_main_mass[N2] && N2 != -1)) {
            //fprintf(fout, "%d ", i + 1);
            tricky_indices[a] = i + 1;
            a++;
        }
    }

    *m = a;
}
