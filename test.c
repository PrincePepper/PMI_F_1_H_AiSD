#include <stdio.h>

void swap(int *a, int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int Bucket_Sort(int *a, int n, int k) {
    for (unsigned l = 1, r = n;;) {

        if (r <= l + 1) {
            // текущая часть состоит из 1 или 2 элементов -
            //	 легко можем найти ответ
            if (r == l + 1 && a[r] < a[l])
                swap(&a[l], &a[r]);
            return *a;
        }

        // упорядочиваем a[l], a[l+1], a[r]
        unsigned mid = (l + r) >> 1;
        swap(&a[mid], &a[l + 1]);
        if (a[l] > a[r])
            swap(&a[l], &a[r]);
        if (a[l + 1] > a[r])
            swap(&a[l + 1], &a[r]);
        if (a[l] > a[l + 1])
            swap(&a[l], &a[l + 1]);

        // выполняем разделение
        // барьером является a[l+1], т.е. медиана среди a[l], a[l+1], a[r]
        unsigned i = l + 1, j = r;

        int cur = a[l + 1];
        while (1) {
            while (a[++i] < cur);
            while (a[--j] > cur);
            if (i > j)
                break;
            swap(&a[i], &a[j]);
        }

        // вставляем барьер
        a[l + 1] = a[j];
        a[j] = cur;

        // продолжаем работать в той части,
        //	 которая должна содержать искомый элемент
        if (j >= k)
            r = j - 1;
        if (j <= k)
            l = i;

    }

}

int main() {
    const unsigned short N = 7, M = 10;

    unsigned short int i, j;
    int numbers[] = {6, 2, 6, 10, 3, 6, 3}, aux[M + 1];//2 3 3 6 6 6 10
    printf("%d", Bucket_Sort(numbers, 7, 2));
    /*// initializing the auxiliary array elements to 0
    for (i = 0; i <= M; i++) {
        aux[i] = 0;
    }

    // filling the auxiliary array with elements of unsorted array
    for (i = 0; i < N; i++) {
        aux[numbers[i]]++;
    }

    // emptying the auxiliary array
    for (i = 0, j = 0; i <= M; i++) {
        for (; aux[i] > 0; (aux[i])--) {
            numbers[j] = i;
            j++;
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d ", numbers[i]);
    }*/
}