#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "solver.h"

#define SIZE 9

bool readBoard(int **board);
void printBoard(int **board, int n);
bool compareBoard(int **board1, int **board2, int n);

int main(void) {
    // board initialization.
    int *board[SIZE];
    for (int i = 0; i < SIZE; i++) {
        board[i] = (int *) malloc(SIZE * sizeof(int));
    }

    // read-in board.
    if (readBoard(board) == 0) {
        printf("File couldn't be read.\n");
        return 0;
    }

    // processing.
    if (solve(board, SIZE, 0, 0)) {
        printf("Solved Board: \n");
    } else {
        printf("The puzzle could not be solved.\n");
    }

    printBoard(board, SIZE);
    
    // freeing allocated space.
    for (int i = 0; i < SIZE; i++) free(board[i]);

    return 0;
}

bool readBoard(int **board) {
    FILE *file = NULL;
    file = fopen("./samples/q.txt", "r");

    if (file == NULL) {
        return false;
    }

    int c, cnt = 0;
    while ((c = fgetc(file)) != EOF && cnt <= 81) {
        if (48 <= c && c <= 57) {
            *(*(board + cnt / 9) + cnt % 9) = ((char) c - '0');
            cnt++;
        }
    }

    fclose(file);
    return true;
}

void printBoard(int **board, int n){
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
}

// 1 if same, 0 if different.
// use for boards with unique solutions. 
bool compareBoard(int **board1, int **board2, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (*(*(board1 + i) + j) != *(*(board2 + i) + j)) {
                return false;
            }
        }
    }
    return true;
}
