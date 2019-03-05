#include "main.h"
#include "chessboard_theme.h"


int init_chessboard(int theme, unsigned int chessboard[][BOARD_SIZE], struct knight *knight)
{
	switch (theme) {
		case 2:
			(*knight).posX = 0;
			(*knight).posY = 0;
			return chessboard_theme_2(chessboard);
		case 3:
			(*knight).posX = random() % BOARD_SIZE;
			(*knight).posY = random() % BOARD_SIZE;
			return chessboard_theme_3(chessboard, (*knight).posX, (*knight).posY);
		case 1:
		default:
			(*knight).posX = (BOARD_SIZE - (BOARD_SIZE % 2)) / 2;
			(*knight).posY = (*knight).posX;
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

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = i; j >= 0; j--) {
			n++;
			chessboard[i-j][j] = n;
		}
	}


	for(i = 1; i < BOARD_SIZE; i++) {
		for (j = BOARD_SIZE - 1; j >= i; j--) {
			n++;
			chessboard[BOARD_SIZE - j + i - 1][j] = n;
		}
	}

	return 0;
}


int chessboard_theme_3(unsigned int chessboard[][BOARD_SIZE], int init_posX, int init_posY)
{
	int posX, posY;
	int list[BOARD_SIZE * BOARD_SIZE - 1];
	int a, n, v, i;

	n = init_posX + init_posY * BOARD_SIZE;
	for (i = 0; i < n; i++)
		list[i] = i;

	i++;
	n = BOARD_SIZE * BOARD_SIZE;
	for (; i < n; i++)
		list[i-1] = i;

	n--;
	chessboard[init_posX][init_posY] = 1;

	a = 2;
	while (n > 0) {
		v = random() % n;

		posX = list[v] % BOARD_SIZE;
		posY = (list[v] - posX) / BOARD_SIZE;
		chessboard[posX][posY] = a;

		list[v] = list[n - 1];
		list[n - 1] = 0;

		a++;
		n--;
	}

	return 0;
}
