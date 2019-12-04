#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef struct {
    unsigned int iCount;
    unsigned int iDigits[1000] = {0};
    bool negative;
} bigint;

int convert(char a) {
    switch (a) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}

void bigint_read(bigint *a, string input) {
    if (input[0] == '-') {
        a->negative = true;
        a->iCount = input.size() - 1;
    } else {
        a->negative = false;
        a->iCount = input.size();
    }
    for (int i = 0; i < a->iCount; i++) {
        a->iDigits[i] = convert(input[input.size() - 1 - i]);
    }
}

void bigint_print(bigint *a) {
    a->negative ? cout << "-" : cout << "";
    for (int i = 0; i < a->iCount; i++) {
        fout << a->iDigits[a->iCount - 1 - i];
    }
}

void bigint_addition(bigint *a, bigint *b, bigint *res) {
    a->iCount > b->iCount ? res->iCount = a->iCount + 1 : res->iCount = b->iCount + 1;
    for (int i = 0; i < res->iCount; i++) {
        res->iDigits[i] += a->iDigits[i] + b->iDigits[i];
        if (res->iDigits[i] > 9) {
            res->iDigits[i + 1] += 1;
            res->iDigits[i] = res->iDigits[i] % 10;
        }
    }
    res->iDigits[res->iCount - 1] == 0 ? res->iCount -= 1 : res->iCount;
}

int nod(int N, int K) {
    return K ? nod(K, N % K) : N;
}

int main() {
    int n, k;
    fin >> n >> k;
    int z = nod(n, k);
    bigint fib[201];
    bigint_read(&fib[0], "0");
    bigint_read(&fib[1], "1");
    if (z < 2) {
        bigint_print(&fib[z]);
        return 0;
    }
    for (int i = 2; i <= nod(n, k); i++) {
        bigint_addition(&fib[i - 2], &fib[i - 1], &fib[i]);
        if (i == z) {
            bigint_print(&fib[i]);
        }
    }
    return 0;
}

