#include <stdio.h>

int main() {
    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    int index;
    fscanf(fin, "%d", &index);

    int mass[2001]={0};

    for (int j = 0, l = 0; j < index; j++) {
        fscanf(fin, "%d", &l);
        for (int i = 0; i < 2001; i++)
            if (l == i - 1000)
                mass[i]++;
    }
    for(int i=0;i<2001;i++){
        if(mass[i]!=0) fprintf(fout,"%d %d\n",i-1000,mass[i]);
    }

}