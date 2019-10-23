#include <stdio.h>
#include <string.h>
//cd ./cmake-build-debug
#define  MAX_ELEMENT (1000)
FILE *fin;

int main(int argc, char **argv) {
    int parametr = 0;            // параметр на данный момент
    int NUM = 0;                 // кол-во строк для параметра -m
    int cal = 1;                 // кол-во параметров(сложно обьяснить)
    char stroke[MAX_ELEMENT];    // массив 1 строки из файла
    int kol = 0;                 // колличество строк встречающийся с патерном(используется для -c)
//------------------------------------------------------------------------------------------------
    //подсчет колличесва параметров
//------------------------------------------------------------------------------------------------
    int chet = 2;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if ((argv[i][0] == '-' && argv[i][1] == 'm')) {
                chet += 2;
            } else chet++;
        }
    }
//------------------------------------------------------------------------------------------------
    //определение какой на данный момент параметр
//------------------------------------------------------------------------------------------------
    for (; cal < argc - 2; cal++) {
        switch (argv[cal][1]) {
            case 'v':
                parametr = 1;
                break;
            case 'm':
                parametr = 2;
                NUM = argv[cal + 1][0];
                cal++;
                break;
            case 'H':
                parametr = 3;
                break;
            case 'h':
                parametr = 4;
                break;
            case 'c':
                parametr = 5;
                break;
            default:
                break;
        }

    }
//------------------------------------------------------------------------------------------------
    //проверка на присутствие файла
//------------------------------------------------------------------------------------------------
    if (chet == 2) {
        fin = stdin;
    } else fin = fopen(argv[chet], "r");
//------------------------------------------------------------------------------------------------
    //распредение в зависимости какой у на параметр
//------------------------------------------------------------------------------------------------
    switch (parametr) {
        case 1:
            while (!feof(fin)) {
                fgets(stroke, MAX_ELEMENT, fin);
                if (!(strstr(stroke, argv[cal]))) {
                    printf("%s", stroke);
                }
            }
            break;

        case 2:
            while (!feof(fin)) {
                fgets(stroke, MAX_ELEMENT, fin);
                if (strstr(stroke, argv[cal]) && NUM > 48) {
                    printf("%s", stroke);
                    NUM--;
                }
            }
            break;

        case 3:
            for (int i = 0; i < argc - chet; i++) {
                fin = fopen(argv[chet + i], "r");
                while (!feof(fin)) {
                    fgets(stroke, MAX_ELEMENT, fin);
                    if (strstr(stroke, argv[chet - 1])) {
                        printf("%s: %s", argv[chet + i], stroke);
                    }
                }

            }
            break;

        case 4:
            for (int i = 0; i < argc - chet; i++) {
                fin = fopen(argv[chet + i], "r");
                while (!feof(fin)) {
                    fgets(stroke, MAX_ELEMENT, fin);
                    if (strstr(stroke, argv[chet - 1])) {
                        printf("%s", stroke);
                    }
                }
            }
            break;

        case 5:
            for (int i = 0; i < argc - chet; i++) {
                fin = fopen(argv[chet + i], "r");
                while (!feof(fin)) {
                    fgets(stroke, MAX_ELEMENT, fin);
                    if (strstr(stroke, argv[chet - 1])) {
                        kol++;
                    }
                }
                printf("%s: %d\n", argv[chet + i], kol);
                kol = 0;
            }
            break;

        default:
            while (!feof(fin)) {
                fgets(stroke, MAX_ELEMENT, fin);
                if (strstr(stroke, argv[cal])) {
                    printf("%s", stroke);
                }
            }
            break;
    }

    printf("\n");
    fclose(fin);
}