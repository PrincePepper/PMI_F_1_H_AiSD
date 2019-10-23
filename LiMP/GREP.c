#include <stdio.h>
#include <string.h>

#define  MAX_ELEMENT (1000)

FILE *fin;

int main(int argc, char **argv) {

    //cd ./cmake-build-debug

    char b = argv[argc - 2][0];
    if (b == '-') {
        printf("hello world");

        //fin = stdin;
    } else fin = fopen(argv[argc - 1], "r");

    int parametr = 0;
    int NUM = 0;
    int cal = 1;
    for (cal; cal < argc - 2; cal++) {
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
                parametr = -1;
                break;
        }
        //printf("%d\n", parametr);
        //printf("%d\n", NUM);
    }

    char stroke[MAX_ELEMENT];


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
            while (!feof(fin)) {
                fgets(stroke, MAX_ELEMENT, fin);
                if (strstr(stroke, argv[cal])) {
                    printf("%s", stroke);
                }
            }
            break;
        case 4:
            break;
        case 5:
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