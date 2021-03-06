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
