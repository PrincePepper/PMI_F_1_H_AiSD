//
// Created by User on 20.10.2019.
//
#include <stdio.h>

#define  MAX_ELEMENT (1000)

#include <string.h>

int main(int argc, char **argv) {
    FILE *fin = fopen(argv[3], "r");
    char a[MAX_ELEMENT];

    while (!feof(fin)) {
        fgets(a, MAX_ELEMENT, fin);
        if (strstr(a, argv[2])) {
            printf("%s", a);
        }
    }
    printf("\n");
}
