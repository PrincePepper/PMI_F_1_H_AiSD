#include <stdio.h>
#include <string.h>

#define MAX_ELEMENT 1000
char mass[MAX_ELEMENT] = {'n'};
char mass2[MAX_ELEMENT] = {' '};

int main() {
    gets(mass);
    int probel = 0;
    for (int i = 0; i < MAX_ELEMENT ||  mass[i] == 'n'; i++) {
        if (mass[i] == ' ' || mass[i] == 'n') {
            probel++;
        }

    }

    //FILE *fin = fopen("input.txt", "r");

    //fscanf(fin,"%s",)

}