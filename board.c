//
// Created by Auboni Poddar on 2019-02-13.
//

//
// Created by mfbut on 7/17/2018.
//
#include <stdlib.h>
#include <stdio.h>
#include "board.h"
#include "CursorTrakedWindow.h"

Board makeBoard(int numRows, int numCols, int n, char blankChar) {
    Board board;
// Height height;

    board.theBoard = (char**)malloc(numRows * sizeof(char*));
    for (int i = 0; i < numRows; ++i) {
        board.theBoard[i] = (char*)malloc(numCols * sizeof(char));
        for (int j = 0; j < numCols; ++j) {
            board.theBoard[i][j] = blankChar;
        }
    }
    //height.h  = (int*)malloc(numCols * sizeof(int)); //making space for array height
//  for (int i = 0; i < numCols; i++)
//  {
//     height.h[i] = 0;
    //  printf("height %d = %d\n", i, height.h[i] );
    //}
    board.numRows = numRows;
    board.numCols = numCols;
    board.blankChar = blankChar;
    board.n = n;
    return board;
}

Height makeHeight(int numRows, int numCols){
    Height height;
    height.h  = (int*)malloc(numCols * sizeof(int)); //making space for array height
    for (int i = 0; i < numCols; i++)
    {
        height.h[i] = 0;
        //printf("height %d = %d\n", i, height.h[i] );
    }
    return height;

}





void printBoard(CursorTrackedWindow* win, int numRows, int numCols, FILE * input, int val){

    if (val == 0){
        for (int i = 0; i < numRows + 1; i++){
            for (int j = 0; j <numCols; j++){
                chtype winChar = mvwinch(win->cursesWin, i, j);
                char theChar = winChar & A_CHARTEXT;
                fprintf(input, "%c", theChar);

            }
            fprintf(input,"%s", "\n");
        }
        //fprintf(input,"%s", "\n");
        //mvwaddstr(

    } else if (val == 13){
        for (int i = 0; i< val; i++){
            chtype winChar = mvwinch(win->cursesWin, 0, i);
            char theChar = winChar & A_CHARTEXT;
            fprintf(input, "%c", theChar);

        }
        fprintf(input,"%s", "\n");
    }

}


void cleanUpBoard(Board* board) {

    for (int row = 0; row < board->numRows; ++row) {
        free(board->theBoard[row]);
    }
    free(board->theBoard);
    board->theBoard = NULL;
    board->numRows = 0;
    board->numCols = 0;
}

void placeMove(Move move, Board* board, CursorTrackedWindow* win) {
    board->theBoard[move.row][move.col] = move.marker;
    addCharacter(win, move.marker);
    CursorTrackedWindowMove(win, win->cursorRow, win->cursorCol);
    wrefresh(win->cursesWin);
}

