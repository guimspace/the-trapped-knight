#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 100

typedef enum {false, true} bool;
struct knight {
	int posX, posY;
	int max, min;
	int s, n;
	int r;
};

void plot_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void plot_mod_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void plot_char_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void knight_move(unsigned int chessboard[][BOARD_SIZE], int init_posX, int init_posY);
bool is_out_bound(int a, int b);
