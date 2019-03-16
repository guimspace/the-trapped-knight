#include <time.h>
#include "main.h"
#include "chessboard_theme.h"
#include "file_manager.h"
#include "plot.h"
#include "knight.h"


int main(int argc, char **argv)
{
	int c, i, j;
	unsigned int chessboard[BOARD_SIZE][BOARD_SIZE];
	struct knight knight;
	struct str_files files;


	c = 1;
	c = open_files(&files);
	if(c)
		return 0;

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
	fprintf(files.fStats, "%d\t%d\n", knight.posX, knight.posY);

	knight_move(files, chessboard, &knight);

	fprintf(files.fStats, "%d\t%d\n", knight.posX, knight.posY);

	fprintf(files.fStats, "%d\t%d\n%d\n", knight.n, knight.s, knight.max);

	fprintf(files.fStats, "%d\t%d\n", knight.limits.minusX, knight.limits.plusX);
	fprintf(files.fStats, "%d\t%d\n", knight.limits.minusY, knight.limits.plusY);

	close_files(&files);

	return 0;
}
