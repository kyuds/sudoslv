#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

#define BOARD_SIZE 9

void printBoard(int **board, int n);
int compareBoard(int **board1, int **board2, int n);

int main(void) {
    // board initialization.
    int *board[BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = (int *) malloc(BOARD_SIZE * sizeof(int));
    }

    // read-in board.

    // processing.
    solve(board, BOARD_SIZE);
    printBoard(board, BOARD_SIZE);

    // freeing allocated space.
    for (int i = 0; i < BOARD_SIZE; i++) free(board[i]);

    return 0;
}

void printBoard(int **board, int n){
    for (int * row = *board; row < *board + n; row++) {
        for (int * col = row; col < row + n; col++) {
            printf("%d ", *col);
        }
        printf("\n");
    }
}

// 1 if same, 0 if different.
// use for boards with unique solutions. 
int compareBoard(int **board1, int **board2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(board1 + i) + j) != *(*(board2 + i) + j)) {
                return 0;
            }
        }
    }

    return 1;
}
