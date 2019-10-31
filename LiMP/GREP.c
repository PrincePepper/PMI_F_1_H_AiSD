#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//cd ./cmake-build-debug

#define  MAX_ELEMENT (1000)
char stroke[MAX_ELEMENT];
char pattern[MAX_ELEMENT];

void CheakFileTrue(char *input, FILE *fin) {
    if (!fin) {
        fprintf(stderr, "grep:%s: No such file or directory\n", input);
        exit(1);
    }

    fseek(fin, 0, SEEK_END);
    long pos = ftell(fin);
    if (pos <= 0) {
        fprintf(stderr, "grep:%s: No such data\n", input);
        exit(1);
    }
}

int ValueCandValueH(char *input, int value_H, int value_c, int kol) {
    kol++;
    if ((value_H == 1) && (value_c == 0)) {
        printf("\033[36m%s\033[0m:", input);
    }
    if (value_c == 0) {
        printf("%s", stroke);

    }
    return kol;
}


void print_main(char *input, FILE *fin, int value_v, int value_H, int value_c, int value_m, int NUM) {
    int kol = 0;
    while (!feof(fin)) {

        if (value_m == 1) {
            if (kol == NUM) break;
        }
        fgets(stroke, MAX_ELEMENT, fin);
        char *b = strstr(stroke, pattern);

        if ((value_v == 0 && b) || (value_v == 1 && !b)) {
            kol = ValueCandValueH(input, value_H, value_c, kol);
        }
    }


    if (value_H == 1 && value_c == 1) {
        printf("\033[0;36m%s\033[0m: ", input);
        printf("\033[0;31m%d\033[0m\n", kol);
    } else if (value_c == 1) {
        printf("\033[0;31m%d\033[0m", kol);
    }
}


int main(int argc, char **argv) {

    setlocale(LC_ALL, "ru_UA.UTF-8");
    int NUM = 0; // кол-во строк для параметра -m
    int key_v = 0;
    int key_m = 0;
    int key_H = 0;
    int key_c = 0;

//------------------------------------------------------------------------------------------------
    //подсчет колличесва параметров
//------------------------------------------------------------------------------------------------
    int koll_files = argc - 2;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            koll_files--;
        }
    }

    strcpy(pattern, argv[argc - koll_files - 1]); // запись шаблона в pattern

//------------------------------------------------------------------------------------------------
    //проверка на присутствие файла и правильность его написания и на пустату файла
//------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------
    //определение какой на данный момент параметр
//------------------------------------------------------------------------------------------------
    for (int cal = 1; cal < argc; cal++) {
        switch (argv[cal][1]) {
            case 'v':
                key_v = 1;
                break;
            case 'm':
                key_m = 1;
                NUM = argv[cal + 1][0] - 48;
                cal++;
                break;
            case 'H':
                key_H = 1;
                break;
            case 'c':
                key_c = 1;
                break;
            default:
                break;
        }
    }
    //printf("%d %d %d %d \n", key_v, key_m, key_H, key_c);
//------------------------------------------------------------------------------------------------
    //работа главной части
//------------------------------------------------------------------------------------------------
    FILE *fin;
    if (koll_files == 0) {
        fin = stdin;
        print_main("(stardart input)", fin, key_v, key_H, key_c, key_m, NUM);
    } else {
        for (int i = 0; i < koll_files; i++) {
            fin = fopen(argv[argc - koll_files + i], "r");

            CheakFileTrue(argv[argc - koll_files + i], fin);
            fin = fopen(argv[argc - koll_files + i], "r");
            print_main(argv[argc - koll_files + i], fin, key_v, key_H, key_c, key_m, NUM);
            fclose(fin);
        }

    }
    return 0;
}