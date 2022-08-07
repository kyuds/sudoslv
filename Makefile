CC=gcc

sudoslv: sudoku.c solver.c
	$(CC) sudoku.c solver.c -o sudoku