#include <time.h>
#include "main.h"
#include "chessboard_theme.h"


int main(int argc, char **argv)
{
	unsigned int chessboard[BOARD_SIZE][BOARD_SIZE];
	struct knight knight;
	int i, j;

	FILE *fSequence, *fPlot, *fStats;

	fSequence = fopen("./Data/sequence.dat", "w");
	if (fSequence == NULL) {
		printf("File sequence.dat coult not be opened.\n");
		return 0;
	}

	fPlot = fopen("./Data/plot.dat", "w");
	if (fPlot == NULL) {
		printf("File plot.dat coult not be opened.\n");
		return 0;
	}

	fStats = fopen("./Data/stats.dat", "w");
	if (fStats == NULL) {
		printf("File stats.dat coult not be opened.\n");
		return 0;
	}

	srandom(time(NULL));

	for (i = 0; i < BOARD_SIZE; i++) {
		for (j = 0; j < BOARD_SIZE; j++)
			chessboard[i][j] = 0;
	}

	knight.posX = 0;
	knight.posY = 0;
	knight.max = 0;
	knight.min = 0;
	knight.n = 0;
	knight.r = 0;
	knight.s = 0;
	knight.limits.plusX = 0;
	knight.limits.plusY = 0;
	knight.limits.minusX = 0;
	knight.limits.minusY = 0;


	init_chessboard(1, chessboard, &knight);
	knight_move(fSequence, fPlot, chessboard, &knight);

	fprintf(fStats, "pos=(%d, %d)\n", knight.posX, knight.posY);
	fprintf(fStats, "max=%d\n", knight.max);
	fprintf(fStats, "s=%d\nn=%d\n", knight.s, knight.n);
	fprintf(fStats, "\n");
	fprintf(fStats, "plus X=%d\n", knight.limits.plusX);
	fprintf(fStats, "minus X=%d\n", knight.limits.minusX);
	fprintf(fStats, "plus Y=%d\n", knight.limits.plusY);
	fprintf(fStats, "minus Y=%d\n", knight.limits.minusY);

	fclose(fSequence);
	fclose(fPlot);
	fclose(fStats);

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


void knight_move(FILE *fSequence, FILE *fPlot, unsigned int chessboard[][BOARD_SIZE], struct knight *knight)
{
	int posX, posY, newPosX, newPosY;
	int jump, stepX, stepY;
	int value;
	unsigned int k, maxK;

	k = 0;
	maxK = 8 * BOARD_SIZE * BOARD_SIZE;

	jump = 0;

	posX = (*knight).posX;
	posY = (*knight).posY;

	newPosX = 0;
	newPosY = 0;
	stepX = 0;
	stepY = 0;
	value = 0;

	(*knight).limits.plusX = posX;
	(*knight).limits.plusY = posY;
	(*knight).limits.minusX = posX;
	(*knight).limits.minusY = posY;


	while (k < maxK) {
		if (select_jump(jump, &stepX, &stepY) != 0)
			return;

		if (!is_out_bound(posX + stepX, posY + stepY) &&
			chessboard[posY + stepY][posX + stepX] != 0) {
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

		jump++;

		if (jump == 8) {
			if(value == 0) {
				(*knight).posX = posX;
				(*knight).posY = posY;

				(*knight).s = chessboard[posY][posX];

				fprintf(fSequence, "%d", chessboard[posY][posX]);
				return;
			}

			(*knight).n++;

			if(chessboard[posY][posX] > (*knight).max)
				(*knight).max = chessboard[posY][posX];

			if(posX > (*knight).limits.plusX)
				(*knight).limits.plusX = posX;
			else if(posX < (*knight).limits.minusX)
				(*knight).limits.minusX = posX;

			if(posY > (*knight).limits.plusY)
				(*knight).limits.plusY = posY;
			else if(posY < (*knight).limits.minusY)
				(*knight).limits.minusY = posY;

			fprintf(fSequence, "%d, ", chessboard[posY][posX]);
			fprintf(fPlot, "%d\t%d\n", posX, posY);
			chessboard[posY][posX] = 0;

			posX = newPosX;
			posY = newPosY;

			value = 0;
			jump = 0;
		}

		k++;
	}

	return;
}


bool is_out_bound(int a, int b) {
	if (a < 0 || a > BOARD_SIZE)
		return true;
	else if (b < 0 || b > BOARD_SIZE)
		return true;
	else
		return false;
}


int select_jump(int jump, int *stepX, int *stepY) {
	switch (jump) {
		case 0:
			*stepX = 2;
			*stepY = 1;
			break;
		case 1:
			*stepX = 1;
			*stepY = 2;
			break;
		case 2:
			*stepX = -1;
			*stepY = 2;
			break;
		case 3:
			*stepX = -2;
			*stepY = 1;
			break;
		case 4:
			*stepX = -2;
			*stepY = -1;
			break;
		case 5:
			*stepX = -1;
			*stepY = -2;
			break;
		case 6:
			*stepX = 1;
			*stepY = -2;
			break;
		case 7:
			*stepX = 2;
			*stepY = -1;
			break;
		default:
			printf("knight_move(): Switch case is default.");
			return 1;
	}

	return 0;
}
