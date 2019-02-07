#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 100


int main(int argc, char **argv)
{
	unsigned int chessboard[BOARD_SIZE][BOARD_SIZE];
	int i, j;

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			chessboard[i][j] = 0;
	}


	return 0;
}
