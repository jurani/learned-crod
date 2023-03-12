#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define MINE 80

//ÉùÃ÷
void Initboard(char board[ROWS][COLS], int rows, int cols);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Mine(char board[ROWS][COLS], int row, int col);
void Sweepmine(char mineboard[ROWS][COLS], char showboard[ROWS][COLS], int row, int col);