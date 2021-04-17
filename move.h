//
// Created by Auboni Poddar on 2019-02-13.
//

#ifndef NCURSESCONNECTN_MOVE_H
#define NCURSESCONNECTN_MOVE_H

#include <stdbool.h>
#include "CursorTrakedWindow.h"
//#include "board.h"

typedef enum{Player1 = 0, Player2 = 1}TurnType;

typedef struct Move_Struct{
    int row, col;
    char marker;
}Move;

struct Board_Struct;
struct Height_Struct;

//void printWinnerinwindow(int winner);
//void printwinner(int winner, CursorTrackedWindow* win);
Move getValidMove(struct Board_Struct* board, struct Height_Struct* height, TurnType playerTurn, CursorTrackedWindow* win,CursorTrackedWindow* wind, int *cursor_print, int *current_state, FILE *fp);
bool isValidMove(Move move,  struct Board_Struct* board, int numArgsRead, int numArgsNeeded);
const char* PlayerToString(TurnType player);


#endif //NCURSESCONNECTN_MOVE_H
