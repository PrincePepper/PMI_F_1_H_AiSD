#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cd ./cmake-build-debug
#define  MAX_ELEMENT 1000

typedef struct {
    char stroke[MAX_ELEMENT];
    char pattern[MAX_ELEMENT];
    int NUM;
    int key_v;
    int key_m;
    int key_H;
    int key_c;
    int number_files;
    int name_file;
    FILE *fin;

} GREP;

GREP grep;

void CheckFileTrue(char *input) {

    if (!grep.fin) {
        fprintf(stderr, "grep:%s: No such file or directory\n", input);
        exit(1);
    }

    fseek(grep.fin, 0, SEEK_END);
    long pos = ftell(grep.fin);
    if (pos <= 0) {
        exit(1);
    }
    fseek(grep.fin, 0, SEEK_SET);
}

int ValueCandValueH(char *input, int kol) {

    kol++;
    if ((grep.key_H == 1) && (grep.key_c == 0)) {
        printf("\033[0;36m%s\033[0m:", input);
    }
    if (grep.key_c == 0) {
        printf("%s", grep.stroke);

    }
    return kol;
}


void PrintMain(char *input) {

    int kol = 0;

    while (!feof(grep.fin)) {

        if (grep.key_m == 1 && kol == grep.NUM) {
            break;
        }
        fgets(grep.stroke, MAX_ELEMENT, grep.fin);
        char *b = strstr(grep.stroke, grep.pattern);
        if ((grep.key_v == 0 && b) || (grep.key_v == 1 && !b)) {
            kol = ValueCandValueH(input, kol);
        }

    }

    if (grep.key_H == 1 && grep.key_c == 1) {
        printf("\033[0;36m%s\033[0m:", input);
        printf("\033[0;31m%d\033[0m", kol);
    } else if (grep.key_c == 1) {
        printf("\033[0;31m%d\033[0m", kol);
    }

}

int main(int argc, char **argv) {

    grep.key_c = 0;
    grep.key_H = 0;
    grep.key_v = 0;
    grep.key_m = 0;
    grep.NUM = 0;
    const int path_name = 1;
    const int arg_patern = 1;
    grep.number_files = argc - path_name - arg_patern;

    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-') {
            if (argv[i][1] == 'm') {
                grep.number_files--;
                i++;
            }
            grep.number_files--;
        }
    }

    grep.name_file = argc - grep.number_files;

    strcpy(grep.pattern, argv[grep.name_file - 1]); // запись шаблона в pattern

    for (int cal = 1; cal < argc; cal++) {
        switch (argv[cal][1]) {
            case 'v':
                grep.key_v = 1;
                break;
            case 'm':
                grep.key_m = 1;
                grep.NUM = atoi(argv[cal + 1]);
                cal++;
                break;
            case 'H':
                grep.key_H = 1;
                break;
            case 'c':
                grep.key_c = 1;
                break;
            default:
                break;
        }
    }

//    printf("%d %d %d %d %d\n", grep.key_v, grep.key_m, grep.key_H, grep.key_c, grep.NUM);
//    printf("%d %s %s\n", grep.name_file, argv[grep.name_file], argv[grep.name_file - 1]);
//    printf("%s \n", grep.pattern);
//    printf("\n");

    if ((grep.NUM != 0 && grep.key_m == 1) || (grep.NUM == 0 && grep.key_m == 0)) {
        if (grep.number_files == 0) {
            grep.fin = stdin;
            PrintMain("(stardart input)");

        } else {
            for (int i = 0; i < grep.number_files; i++) {
                grep.fin = fopen(argv[grep.name_file + i], "r");
                CheckFileTrue(argv[grep.name_file + i]);
                PrintMain(argv[grep.name_file + i]);
                fclose(grep.fin);
            }

        }
        printf("\n");
    } else fprintf(stderr, "grep: invalid max count\n");
    return 0;
}