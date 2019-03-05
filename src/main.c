#include <time.h>
#include "main.h"
#include "chessboard_theme.h"


int main(int argc, char **argv)
{
	unsigned int chessboard[BOARD_SIZE][BOARD_SIZE];
	int posX, posY;
	int i, j;

	FILE *fSequence, *fGraph;

	fSequence = fopen("./Data/sequence.dat", "w");
	if (fSequence == NULL) {
		printf("File sequece.dat coult not be opened.\n");
		return 0;
	}

	fGraph = fopen("./Data/graph.dat", "w");
	if (fGraph == NULL) {
		printf("File sequece.dat coult not be opened.\n");
		return 0;
	}

	srandom(time(NULL));

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			chessboard[i][j] = 0;
	}


	init_chessboard(1, chessboard, &posX, &posY);
	knight_move(chessboard, posX, posY);

	fclose(fSequence);
	fclose(fGraph);

	return 0;
}


void plot_chessboard(unsigned int chessboard[][BOARD_SIZE])
{
	int i, j;


	for (i = 0; i < BOARD_SIZE; i++) {
		printf("%d", chessboard[i][0]);

		for (j = 1; j < BOARD_SIZE; j++)
			printf("\t%d", chessboard[i][j]);

		printf("\n");
	}

	return;
}


void plot_mod_chessboard(unsigned int chessboard[][BOARD_SIZE])
{
	int i, j;


	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			printf("%d", chessboard[i][j] % 10);

		printf("\n");
	}

	return;
}


void plot_char_chessboard(unsigned int chessboard[][BOARD_SIZE])
{
	int i, j;


	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			if(chessboard[i][j] == 0)
				printf("#");
			else
				printf(" ");

		printf("\n");
	}

	return;
}


void knight_move(unsigned int chessboard[][BOARD_SIZE], int init_posX, int init_posY)
{
	int posX, posY, newPosX, newPosY;
	int jump, stepX, stepY;
	int value;
	int isTrapped;

	jump = 0;
	isTrapped = 0;

	posX = init_posX;
	posY = init_posY;

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
			printf("The knight is cornered.\n\n");
			return;
		}

		if (chessboard[posY + stepY][posX + stepX] != 0) {
			if (value == 0) {
				newPosX = posX + stepX;
				newPosY = posY + stepY;
				value = chessboard[newPosY][newPosX];
			} else if (chessboard[posY + stepY][posX + stepX] < value) {
				newPosX = posX + stepX;
				newPosY = posY + stepY;
				value = chessboard[newPosY][newPosX];
			}
		}

		if (jump == 7 && value == 0)
			return;

		jump++;

		if (jump == 8) {
			chessboard[posY][posX] = 0;

			posX = newPosX;
			posY = newPosY;

			value = 0;
			jump = 0;
		}
	}

	return;
}
