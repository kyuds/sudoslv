#include <stdio.h>
#include <stdbool.h>
#include "solver.h"

bool checkPos(int **board, int row, int col, int n, int target);
// void debugBoard(int **board, int n);

bool solve(int **board, int n, int row, int col) {
    if (row == n - 1 && col == n) {
        return true;
    }

    if (col == n) {
        row++;
        col = 0;
    }

    if (*(*(board + row) + col) != 0) {
        return solve(board, n, row, col + 1);
    }

    for (int i = 1; i <= n; i++) {
        if (checkPos(board, row, col, n, i)) {
            *(*(board + row) + col) = i;

            if (solve(board, n, row, col + 1)) {
                return true;
            }
        }
        *(*(board + row) + col) = 0;
    }

    //debugBoard(board, n);

    return false;
}

// 1 for valid, 0 for invalid.
bool checkPos(int **board, int row, int col, int n, int target) {
    // check row.
    for (int * c = *(board + row); c < *(board + row) + n; c++) {
        if (*c == target) {
            return false;
        }
    }

    // check column.
    for (int r = 0; r < n; r++) {
        if (*(*(board + r) + col) == target) {
            return false;
        }
    }

    // check box.
    int sr = (row / 3) * 3, sc = (col / 3) * 3;
    for (int r = sr; r < sr + n / 3; r++) {
        for (int c = sc; c < sc + n / 3; c++) {
            if (*(*(board + r) + c) == target) {
                return false;
            }
        }
    }

    return true;
}

/*
void debugBoard(int **board, int n){
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int temp = *(*(board + row) + col);
            if (temp) {
                printf("%d ", temp);
            } else {
                printf("- ");
            }
            if (col == 2 || col == 5) {
                printf("| ");
            }
        }
        printf("\n");
        if (row == 2 || row == 5) {
            printf("--------------------- \n");
        }
    }
    printf("\n");
}
*/