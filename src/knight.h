void knight_move(struct str_files files, unsigned int chessboard[][BOARD_SIZE], struct knight *knight);
bool is_out_bound(int a, int b);
int select_jump(int jump, int *stepX, int *stepY);
