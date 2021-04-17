//
// Created by Auboni Poddar on 2019-02-13.
//

#ifndef NCURSESCONNECTN_WIN_H
#define NCURSESCONNECTN_WIN_H

#include <stdbool.h>
#include "board.h"
#include "move.h"


bool isGameOver(Board board);
bool win(Board board);
bool horzWin(Board board);
bool vertWin(Board board);
bool diagWin(Board board);
bool leftDiagWin(Board board);
bool subleftDiagWinL(Board board, int r, int c);
bool subleftDiagWinR(Board board, int r, int c);
bool subleftDiagWinC(Board board, int r, int c);
bool subrightDiagWinR(Board board, int r, int c);
bool subrightDiagWinC(Board board, int r, int c);
bool rightDiagWin(Board board);
bool tie(Board board);
void declareWinner(Board board, TurnType playerTurn,  FILE *input, CursorTrackedWindow* win);


#endif //NCURSESCONNECTN_WIN_H
