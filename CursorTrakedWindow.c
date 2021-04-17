//
// Created by Auboni Poddar on 2019-02-13.
//

#include "CursorTrakedWindow.h"

CursorTrackedWindow newCursorTrackedWindow(int numRows, int numCols, int rowStart, int colStart){
    CursorTrackedWindow window;
    window.cursesWin = newwin(numRows + 1, numCols, rowStart, colStart); //changed to +1
    window.cursorRow = 0;
    window.cursorCol = 0;
    return window;
}



/**
* Doesn't advance the cursor
* @param win
* @param fillChar
*/
void fillWindow(CursorTrackedWindow* win, char fillChar){
    int curRow = win->cursorRow, curCol = win->cursorCol;
    if (fillChar == '*'){
        for (int i = 1; i < getNumRows(win); ++i) { //chnaged to 1
            for (int j = 0; j < getNumCols(win); ++j) {
                mvwaddch(win->cursesWin, i, j, fillChar);
            }
        }
        // mvwaddstr(win->cursesWin,5, 0, const char* str)
        // mvwaddch(win->cursesWin, 5, 0, 'l');
        //mvwaddstr(win->cursesWin, getNumRows(win),0, "win");
        wmove(win->cursesWin, curRow, curCol);
    } else if (fillChar == ' '){
        for (int i = 0; i < getNumRows(win)-1; ++i) { //chnaged
            for (int j = 0; j < getNumCols(win); ++j) {
                mvwaddch(win->cursesWin, i, j, fillChar);
            }
        }
        // mvwaddstr(win->cursesWin,5, 0, const char* str)
        // mvwaddch(win->cursesWin, 5, 0, 'l');
        //mvwaddstr(win->cursesWin, getNumRows(win),0, "win");
        wmove(win->cursesWin, curRow, curCol);
    }

}
/*void fillWinner(CursorTrackedWindow* win, int winner){
 int curRow = win->cursorRow, curCol = win->cursorCol;
 mvwaddstr(win->cursesWin,0, 0, "Winner is");
 // mvwaddch(win->cursesWin, 5, 0, 'l');
 //mvwaddstr(win->cursesWin, getNumRows(win),0, "win");
 wmove(win->cursesWin, curRow, curCol);

}
*/

int getNumRows(CursorTrackedWindow* win){
    return getmaxy(win->cursesWin);
}
int getNumCols(CursorTrackedWindow* win){
    return getmaxx(win->cursesWin);
}

void moveAndAddCharacter(CursorTrackedWindow* win, int row, int col, char toAdd) {
    mvwaddch(win->cursesWin, row, col, toAdd);
    win->cursorRow = row;
    win->cursorCol = col;
}

void addCharacter(CursorTrackedWindow* win, char toAdd) {
    moveAndAddCharacter(win, win->cursorRow, win->cursorCol, toAdd);
}

void CursorTrackedWindowMove(CursorTrackedWindow* win, int row, int col) {
    wmove(win->cursesWin, row, col);
    win->cursorRow = row;
    win->cursorCol = col;
}

