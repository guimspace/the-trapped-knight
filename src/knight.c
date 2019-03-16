#include "main.h"
#include "knight.h"


void knight_move(struct str_files files, unsigned int chessboard[][BOARD_SIZE], struct knight *knight)
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
		if (select_jump(jump, &stepX, &stepY) != 0) {
			fprintf(files.fLog, "%d:%d\tjump=%d\tbad-jump\n",
				k, knight->n, jump);
			return;
		}

		if(is_out_bound(posX + stepX, posY + stepY)) {
			fprintf(files.fLog, "%d:%d\tjump=%d\tout-of-bounds\n",
				k, knight->n, jump);
		} else if (chessboard[posY + stepY][posX + stepX] != 0) {
			if (value == 0) {
				newPosX = posX + stepX;
				newPosY = posY + stepY;
				value = chessboard[newPosY][newPosX];
				fprintf(files.fLog, "%d:%d\tjump=%d\tfirst-value=%d\n",
					k, knight->n, jump, value);
			} else if (chessboard[posY + stepY][posX + stepX] < value) {
				newPosX = posX + stepX;
				newPosY = posY + stepY;
				value = chessboard[newPosY][newPosX];
				fprintf(files.fLog, "%d:%d\tjump=%d\tnext-value=%d\n",
					k, knight->n, jump, value);
			}
		}

		jump++;

		if (jump == 8) {
			if(value == 0) {
				(*knight).posX = posX;
				(*knight).posY = posY;

				(*knight).s = chessboard[posY][posX];

				fprintf(files.fPlot, "%d\t%d\n", posX, posY);
				fprintf(files.fSequence, "%d", chessboard[posY][posX]);
				return;
			}

			(*knight).n++;

			if (chessboard[posY][posX] > (*knight).max)
				(*knight).max = chessboard[posY][posX];

			if (posX > (*knight).limits.plusX)
				(*knight).limits.plusX = posX;
			else if (posX < (*knight).limits.minusX)
				(*knight).limits.minusX = posX;

			if (posY > (*knight).limits.plusY)
				(*knight).limits.plusY = posY;
			else if (posY < (*knight).limits.minusY)
				(*knight).limits.minusY = posY;

			fprintf(files.fSequence, "%d, ", chessboard[posY][posX]);
			fprintf(files.fPlot, "%d\t%d\n", posX, posY);
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
