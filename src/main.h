#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 100

void plot_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void plot_mod_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void plot_char_chessboard(unsigned int chessboard[][BOARD_SIZE]);
void knight_move(unsigned int chessboard[][BOARD_SIZE], int init_posX, int init_posY);
