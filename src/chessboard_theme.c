#include "main.h"
#include "chessboard_theme.h"


int init_chessboard(int theme, unsigned int chessboard[][BOARD_SIZE], int *posX, int *posY)
{
	switch (theme) {
		case 2:
			*posX = 0;
			*posY = 0;
			return chessboard_theme_2(chessboard);
		case 1:
		default:
			*posX = (BOARD_SIZE - 1) / 2;
			*posY = (BOARD_SIZE - 1) / 2;
			return chessboard_theme_1(chessboard);
	}
}


/*
7	8	9
6	1	2
5	4	3
*/
int chessboard_theme_1(unsigned int chessboard[][BOARD_SIZE])
{
	int dir, posX, posY;
	int incX, incY;
	int stepsX, stepsY;
	int i, n, N;

	n = 0;
	N = 0;
	stepsX = 0;
	stepsY = 0;

	dir = 0;
	posX = (BOARD_SIZE - 1) / 2;
	posY = (BOARD_SIZE - 1) / 2;


	while (N < BOARD_SIZE) {
		switch (dir) {
			case 0:
				incX = 1;
				incY = 0;

				stepsX++;
				N = stepsX;

				dir++;
				break;

			case 1:
				incX = 0;
				incY = 1;

				stepsY++;
				N = stepsY;

				dir++;
				break;

			case 2:
				incX = -1;
				incY = 0;

				stepsX++;
				N = stepsX;

				dir++;
				break;

			case 3:
				incX = 0;
				incY = -1;

				stepsY++;
				N = stepsY;

				dir = 0;
				break;

			default:
				printf("chessboard_theme_1(): Switch case is default.\n\n");
				return 1;
		}

		i = 0;
		while (i < N) {
			n++;
			chessboard[posY][posX] = n;

			posX += incX;
			posY += incY;

			i++;
		}
	}

	return 0;
}

/*
1	2	4	7
3	5	8
6	9
10
*/
int chessboard_theme_2(unsigned int chessboard[][BOARD_SIZE])
{
	int i, j;
	int n;

	n = 0;

	for(i = 0; i < BOARD_SIZE; i++) {
		for(j = 0; j <= i; j++) {
			n++;
			chessboard[j][i-j] = n;
		}
	}

	return 0;
}
