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

    char a[MAX_ELEMENT];
    /*for (int i = 1; i < argc - 2; i++) {
        if (argv[argc - 2][0] == '-'){

        }
    }*/
    while (!feof(fin)) {
        fgets(a, MAX_ELEMENT, fin);
        if (strstr(a, argv[argc - 2])) {
            printf("%s", a);
        }
    }
    printf("\n");
    fclose(fin);
}