#include <stdio.h>

#define FALSE 0
#define TRUE 1

typedef struct {
    char WALL;
    char BLANK;
    int W_grid;
    int H_grid;
    int len;
} GRID;

GRID grid;

void display_maze(char (*maze)[grid.W_grid]) {
    int i;
    for (i = 0; i < grid.H_grid; i++)
        for (int j = 0; j < grid.W_grid; j++)
            if (maze[i][j] == '+') grid.len++;
}

int find_path(int x, int y, char (*maze)[grid.W_grid]) {
    // Если x, y находится вне лабиринта, верните false.
    if (x < 0 || x > grid.W_grid - 1 || y < 0 || y > grid.H_grid - 1) return FALSE;

    // Если x, y - цель, верните true.
    if (maze[y][x] == '.' && x == grid.W_grid - 1 && y == grid.W_grid - 1) return TRUE;

    // Если x, y не открыт, верните false.
    if (maze[y][x] != grid.BLANK) {
        return FALSE;
    }

    // Отметьте x, y часть пути решения.
    maze[y][x] = '+';

    // Если find_path к северу от x, y равно true, вернуть true.
    if (find_path(x, y - 1, maze) == TRUE) {
        return TRUE;
    }

    // Если find_path к востоку от x, y равно true, вернуть true.
    if (find_path(x + 1, y, maze) == TRUE) {
        return TRUE;
    }

    // Если find_path к югу от x, y равно true, вернуть true.
    if (find_path(x, y + 1, maze) == TRUE) {
        return TRUE;
    }

    // Если find_path к западу от x, y равно true, вернуть true.
    if (find_path(x - 1, y, maze) == TRUE) {
        return TRUE;
    }

    // Снимите метку x, y как часть пути решения.
    maze[y][x] = 'x';

    return FALSE;
}

int main() {
    grid.WALL = '#';
    grid.BLANK = '.';
    grid.len = 0;

    FILE *fin = fopen("input.txt", "r");
    FILE *fout = fopen("output.txt", "w");

    fscanf(fin, "%d", &grid.H_grid);

    char grid_mass[grid.H_grid][grid.W_grid];
    grid.W_grid = grid.H_grid;
    for (int i = 0; i < grid.H_grid; i++) {
        fscanf(fin, "%s", grid_mass[i]);
    }

    if (find_path(0, 0, grid_mass) == TRUE) {
        display_maze(grid_mass);
        fprintf(fout, "%d\n", grid.len);
        //printf("YES\n");
    } else
        fprintf(fout, "-1\n");
}