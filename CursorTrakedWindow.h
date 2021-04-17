//
// Created by Auboni Poddar on 2019-02-13.
//

#ifndef NCURSESCONNECTN_CURSORTRAKEDWINDOW_H
#define NCURSESCONNECTN_CURSORTRAKEDWINDOW_H

#include <ncurses.h>

typedef struct CursorTrackedWindow_Struct{
    WINDOW* cursesWin;
    int cursorRow, cursorCol;
}CursorTrackedWindow;

CursorTrackedWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart);
void fillWindow(CursorTrackedWindow* win, char fillChar);

int getNumRows(CursorTrackedWindow* win);
int getNumCols(CursorTrackedWindow* win);

void moveAndAddCharacter(CursorTrackedWindow* win, int row, int col, char toAdd);
void addCharacter(CursorTrackedWindow* win, char toAdd);
void CursorTrackedWindowMove(CursorTrackedWindow* win, int row, int col);


#endif //NCURSESCONNECTN_CURSORTRAKEDWINDOW_H
