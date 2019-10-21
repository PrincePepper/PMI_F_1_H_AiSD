#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int index_mass;
    fscanf(fin, "%d", &index_mass);
    //scanf("%d", &index_mass);

    int mass[index_mass];
    for(int i =0;i<index_mass;i++){
        fscanf(fin,"%d", &mass[i]);
    }

    for(int i =0;i<index_mass-2;i++){
        if(mass[i+2]-mass[i]<7){
            fprintf(fout,"BAD");
            return 0;
        }
    }
    fprintf(fout,"GOOD");

}