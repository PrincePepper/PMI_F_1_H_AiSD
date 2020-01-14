#include <stdio.h>
#include <string.h>

typedef struct {
    int combination;
    int number;
} accordance_combination_number;

typedef struct {
    int number;
    int number_of_picture;
} acccordance_number_picture;

int main() {
    accordance_combination_number coordination[14];
    int counter = 0;
    int digit = 0;
    int boolean_invert[4] = {0};
    int boolean[4] = {0};
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 4; ++j) {
            if ((counter > 0) && (counter % 2 != 0)) {
                boolean_invert[j] = 1;
                counter = counter / 2;
            }
            if ((counter > 0) && (counter % 2 == 0)) {
                boolean_invert[j] = 0;
                counter = counter / 2;
            }
        }
        for (int k = 0; k < 4; ++k) {
            boolean[k] = boolean_invert[3 - k];
        }

        if (counter > 0) {
            for (int i = 0; i < 4; ++i) {
                digit *= 10;
                digit += boolean[i];
            }
        }
        counter++;
        coordination[i].combination = digit;
    }
    //NEED TO BRING NUMBERS GUYS
    acccordance_number_picture coordination_2[54]; //or more
    //должно быть strcopy с номеров, введенных в 1 структуре, во 2 структуру
    int counter_2 = 1;
    for (int l = 0; l < 54; ++l) {
        coordination_2[l].number_of_picture = counter_2;
        counter_2++;
    }
    //ввод пользовательских данных
    int user_data = 0;
    int randomize_number = 0;

    scanf("%d", &user_data);
    for (int m = 0; m < 16; ++m) {
        if (user_data == coordination[m].combination) {
            randomize_number = coordination[m].number;
            break;
        }
        //прописать рандомайзер
    }
}