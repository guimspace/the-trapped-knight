#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 100

void plot_number_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void knight_move(unsigned int chessboard[][BOARD_SIZE], int init_posX, int init_posY);
