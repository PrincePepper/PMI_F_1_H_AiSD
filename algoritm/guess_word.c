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

    int mass[len_word];
    for (int i = 0; i < len_word; i++) {
        mass[i] = 0;
    }

    int alphabet_new[26] = {0};
    for (int j = 0; j <= 20; j++) {
        for (int i = 'a'; i < 'z'; i++)
            if (combination[j] == i) {
                alphabet_new[i - 'a']++;
            }
    }

    char alphabet2[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                          't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int j = 0; j < len_word; j++) {
        for (int i = 0; i < 26; i++) {
            if (alphabet2[i] == word[j]) {
                if (alphabet_new[i] % 2 == 0) {
                    fprintf(fout, ".");
                } else {
                    fprintf(fout, "%c", word[j]);
                }
            }
        }
    }
}
