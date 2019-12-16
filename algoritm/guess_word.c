//
// Created by User on 23.11.2019.
//

#include <stdio.h>
#include <string.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    char word[16] = {0};
    char combination[21] = {0};

    fscanf(fin, "%s %s", word, combination);

    int len_word = strlen(word);
    int len_comb = strlen(combination);

    char mass[len_word];
    for (int i = 0; i < len_word; i++) {
        mass[i] = '.';
    }
    int g = 0;
    for (int i = 0; i < len_word; i++) {
        for (int j = 0; j < len_comb; j++) {
            if (word[i] == combination[j]) {
                if (g % 2 == 0) {
                    mass[i] = word[i];
                } else mass[i] = '.';
                g++;
            }
        }
        g = 0;
    }
    for (int i = 0; i < len_word; i++) {
        fprintf(fout, "%c", mass[i]);
    }
}
