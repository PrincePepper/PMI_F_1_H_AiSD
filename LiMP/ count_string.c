//
// Created by User on 26.10.2019.
//
#include <stdio.h>
#include <string.h>
#define  MAX_ELEMENT (10000)
char stroke[MAX_ELEMENT];

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int count = 0;
    fgets(stroke, MAX_ELEMENT, fin);
    char *pstr = strtok(stroke, " @#№!':;()_-+=*&?^%$><~`1234567890");
    while (pstr != NULL) {
        pstr = strtok(NULL, " @#№!':;()_-+=*&?^%$><~`1234567890");
        count++;
    }
    fprintf(fout, "Words - %d", count);

}