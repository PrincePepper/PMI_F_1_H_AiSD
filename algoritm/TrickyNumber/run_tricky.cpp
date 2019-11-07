/*
Задача "Хитрый член" : ввод-вывод и запуск
18.10.2019
*/

#include <iostream>
#include <fstream>

using namespace std;

/*
Вычислительная функция
---
Вход :
    a[0..n-1] - последовательность
Выход :
    tricky_indices[0..m-1] - последовательность индексов хитрых членов
      (индексы от 1 до n)
*/
void get_tricky_numbers(int n, const int a[], int *m, int tricky_indices[]);


// Прочитать из файла длину последовательности чисел и последовательность
void read_counted_sequence_int(const char *input_file, int &n, int a[]) {
    ifstream fin(input_file);
    fin >> n;
    if (n <= 0) {
        cout << "n <= 0" << endl;
        throw;
    }
    for (int i = 0; i < n; ++i) {
        fin >> a[i];
        if (a[i] < 0) {
            cout << "a[" << i << "] < 0" << endl;
            throw;
        }
    }
}

// вывести в файл последовательность чисел
void write_sequence_int(const char *output_file, int n, const int a[]) {
    ofstream fout(output_file);
    for (int i = 0; i < n; ++i)
        fout << a[i] << " ";
}

int main() {
    const char *input_file = "input.txt";
    const char *output_file = "output.txt";
    const int MAX_N = 1000000;
    // входные данные
    static int a[MAX_N];
    int n;
    // выходные данные
    static int tricky_indices[MAX_N];
    int m;

    read_counted_sequence_int(input_file, n, a);
    get_tricky_numbers(n, a, &m, tricky_indices);
    write_sequence_int(output_file, m, tricky_indices);

    return 0;
}

