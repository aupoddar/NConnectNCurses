//
// Created by Auboni Poddar on 2019-02-13.
//

#ifndef NCURSESCONNECTN_BOARD_H
#define NCURSESCONNECTN_BOARD_H

#include "move.h"


typedef int phoneNumber;

typedef struct Board_Struct{
    char** theBoard;
    int numRows;
    int numCols;
    int n;
    char blankChar;
}Board;

typedef struct Height_Struct{
    int* h;
}Height;

void printBoard(CursorTrackedWindow* win, int numRows, int numCols, FILE *fp, int val);
Board makeBoard(int numRows, int numCols, int n, char blankChar);
Height makeHeight(int numRows, int numCols);
//void printBoard(Board board,FILE * input, int cursor_print, int current_state, TurnType playerTurn);
void cleanUpBoard(Board* board);

void placeMove(Move move, Board* board, CursorTrackedWindow* win);


#endif //NCURSESCONNECTN_BOARD_H
