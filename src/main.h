#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 100

typedef enum {false, true} bool;

struct arrayLimits {
	int plusX, plusY;
	int minusX, minusY;
};
struct knight {
	int posX, posY;
	int max, min;
	int s, n;
	int r;
	struct arrayLimits limits;
};
struct str_files {
	FILE *fSequence;
	FILE *fPlot;
	FILE *fStats;
	FILE *fLog;
};

void knight_move(struct str_files files, unsigned int chessboard[][BOARD_SIZE], struct knight *knight);
bool is_out_bound(int a, int b);
int select_jump(int jump, int *stepX, int *stepY);
