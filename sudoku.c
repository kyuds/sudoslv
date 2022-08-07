#include <stdio.h>
#include <stdlib.h>
#include "solver.h"

#define SIZE 9

int readBoard(int **board);
void printBoard(int **board, int n);
int compareBoard(int **board1, int **board2, int n);

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
    solve(board, SIZE);
    printf("Solved Board: \n");
    printBoard(board, SIZE);

    // freeing allocated space.
    for (int i = 0; i < SIZE; i++) free(board[i]);

    return 0;
}

int readBoard(int **board) {
    FILE *file = NULL;
    file = fopen("./samples/q.txt", "r");

    if (file == NULL) {
        return 0;
    }

    int c, cnt = 0;
    while ((c = fgetc(file)) != EOF) {
        if (48 <= c && c <= 57) {
            *(*(board + cnt / 9) + cnt % 9) = ((char) c - '0');
            cnt++;
        }
    }

    fclose(file);
    return 1;
}

void printBoard(int **board, int n){
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            int temp = *(*(board + row)+col);
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
