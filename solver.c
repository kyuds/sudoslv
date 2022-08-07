#include <stdio.h>
#include <stdbool.h>
#include "solver.h"

bool checkPos(int **board, int row, int col, int n);

bool solve(int **board, int n) {
    printf("%d\n", checkPos(board, 0, 4, n));
}

// 1 for valid, 0 for invalid.
bool checkPos(int **board, int row, int col, int n) {
    int target = *(*(board + row) + col);

    // check row.
    for (int * c = *(board + row); c < *(board + row) + n; c++) {
        if (*c == target && c != *(board + row) + col) {
            return false;
        }
    }

    // check column.
    for (int r = 0; r < n; r++) {
        if (*(*(board + r) + col) == target && r != row) {
            return false;
        }
    }

    // check box.
    int sr = row % 3 * 3, sc = col % 3 * 3;
    for (int r = sr; r < sr + n / 3; r++) {
        for (int c = sc; c < sc + n / 3; c++) {
            if (*(*(board + r) + c) == target && r != row && c != col) {
                return false;
            }
        }
    }

    return true;
}
