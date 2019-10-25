#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <io.h>

//cd ./cmake-build-debug

#define  MAX_ELEMENT (1000)
char stroke[MAX_ELEMENT];
char pattern[MAX_ELEMENT];

FILE *fin;

int ValueCandValueH(char *input, int value_H, int value_c, int kol) {
    kol++;
    if ((value_H == 1) && (value_c == 0)) {
        printf("%s:", input);
    }
    if (value_c == 0) {
        printf("%s", stroke);
    }
    return kol;
}


void print_main(char *input, FILE *FILE, int value_v, int value_H, int value_c, int value_m, int NUM) {
    int kol = 0;
    while (!feof(FILE)) {
        if (value_m == 1) {
            if (kol == NUM) break;
        }
        fgets(stroke, MAX_ELEMENT, FILE);
        if (value_v == 0 && strstr(stroke, pattern)) {
            kol = ValueCandValueH(input, value_H, value_c, kol);
        } else if (value_v == 1 && !strstr(stroke, pattern) && !(strstr(stroke, "\n"))) {
            kol = ValueCandValueH(input, value_H, value_c, kol);
        }
    }


    if (value_H == 1 && value_c == 1) {
        printf("%s:%d", input, kol);
    } else if (value_c == 1) {
        printf("%d\n", kol);
    }
}


int main(int argc, char **argv) {

    setlocale(LC_ALL, "Rus");
    int NUM = 0; // кол-во строк для параметра -m
    int value_v = 0;
    int value_m = 0;
    int value_H = 0;
    int value_c = 0;

//------------------------------------------------------------------------------------------------
    //подсчет колличесва параметров
//------------------------------------------------------------------------------------------------
    int koll_files = 2;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if ((argv[i][0] == '-' && argv[i][1] == 'm')) {
                koll_files += 2;
            } else koll_files++;
        }
    }

    strcpy(pattern, argv[koll_files - 1]); // запись шаблона в pattern
//------------------------------------------------------------------------------------------------
    //проверка на присутствие файла и правильность его написания и на пустату файла
//------------------------------------------------------------------------------------------------
    if (koll_files == 2) {
        fin = stdin;
    } else {
        fin = fopen(argv[koll_files], "r");

        if (!fin) {
            printf("grep:%s: No such file or directory\n", argv[koll_files]);
            return 0;
        }

        fseek(fin, 0, SEEK_END);
        long pos = ftell(fin);
        if (pos > 0) {
        } else printf("grep:%s: No such data\n", argv[koll_files]);
    }

//------------------------------------------------------------------------------------------------
    //определение какой на данный момент параметр
//------------------------------------------------------------------------------------------------
    for (int cal = 1; cal < koll_files - 1; cal++) {
        switch (argv[cal][1]) {
            case 'v':
                value_v = 1;
                break;
            case 'm':
                value_m = 1;
                NUM = argv[cal + 1][0] - 48;
                cal++;
                break;
            case 'H':
                value_H = 1;
                break;
            case 'c':
                value_c = 1;
                break;
            default:
                break;
        }
    }

//------------------------------------------------------------------------------------------------
    //работа главной части
//------------------------------------------------------------------------------------------------
    for (int i = 0; i < argc - koll_files; i++) {
        fin = fopen(argv[koll_files + i], "r");
        print_main(argv[koll_files + i], fin, value_v, value_H, value_c, value_m, NUM);
    }
    fclose(fin);

    printf("\n");
    fclose(fin);
    return 0;
}