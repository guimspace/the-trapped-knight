#include "main.h"
#include "chessboard_theme.h"


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
