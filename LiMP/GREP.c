#include <stdio.h>
#include <string.h>

#define  MAX_ELEMENT (1000)

FILE *fin;

int main(int argc, char **argv) {

    //cd ./cmake-build-debug

    int chet = 2;
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if ((argv[i][0] == '-' && argv[i][1] == 'm')) {
                chet += 2;
            } else chet++;
        }
    }
    if (chet == 2) {
        fin = stdin;
    } else fin = fopen(argv[chet], "r");

    int parametr = 0;
    int NUM = 0;
    int cal = 1;
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

    char stroke[MAX_ELEMENT];
    int kol = 0;
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