#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 100

int init_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void plot_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void knight_move(unsigned int chessboard[][BOARD_SIZE]);


int main(int argc, char **argv)
{
	unsigned int chessboard[BOARD_SIZE][BOARD_SIZE];
	int i, j;

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			chessboard[i][j] = 0;
	}


	init_chessboard(chessboard);
	knight_move(chessboard);

	return 0;
}


int init_chessboard(unsigned int chessboard[][BOARD_SIZE])
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
				printf("build_path(): Switch case is default.\n\n");
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


void plot_chessboard(unsigned int chessboard[][BOARD_SIZE])
{
	int i, j;


	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			printf("%d", chessboard[i][j] % 10);

		printf("\n");
	}

	return;
}


void knight_move(unsigned int chessboard[][BOARD_SIZE])
{
	int posX, posY, newPosX, newPosY;
	int jump, stepX, stepY;
	int value;
	int isTrapped;

	jump = 0;
	isTrapped = 0;

	posX = (BOARD_SIZE - 1) / 2;
	posY = (BOARD_SIZE - 1) / 2;

	newPosX = 0;
	newPosY = 0;
	stepX = 0;
	stepY = 0;
	value = 0;


	while (!isTrapped) {
		switch (jump) {
			case 0:
				stepX = 2;
				stepY = 1;
				break;
			case 1:
				stepX = 1;
				stepY = 2;
				break;
			case 2:
				stepX = -1;
				stepY = 2;
				break;
			case 3:
				stepX = -2;
				stepY = 1;
				break;
			case 4:
				stepX = -2;
				stepY = -1;
				break;
			case 5:
				stepX = -1;
				stepY = -2;
				break;
			case 6:
				stepX = 1;
				stepY = -2;
				break;
			case 7:
				stepX = 2;
				stepY = -1;
				break;
			default:
				printf("knight_move(): Switch case is default.");
				return;
		}

		if (posX + stepX < 0 || posX + stepX >= BOARD_SIZE ||
				posY + stepY < 0 || posY + stepY >= BOARD_SIZE) {
			jump++;
		} else if (chessboard[posY + stepY][posX + stepX] != 0) {
			if (value == 0) {
				newPosX = posX + stepX;
				newPosY = posY + stepY;
				value = chessboard[newPosY][newPosX];
			} else if (chessboard[posY + stepY][posX + stepX] < value) {
				newPosX = posX + stepX;
				newPosY = posY + stepY;
				value = chessboard[newPosY][newPosX];
			}

			jump++;
		} else {
			if (jump == 7 && value == 0)
				return;

			jump++;
		}

		if (jump == 8) {
			if (value == 0)
				return;

			chessboard[posY][posX] = 0;

			posX = newPosX;
			posY = newPosY;

			value = 0;
			jump = 0;
		}
	}

	return;
}
