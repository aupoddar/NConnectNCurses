//
// Created by Auboni Poddar on 2019-02-13.
//

//#include "move.h"
#include <stdio.h>
#include "board.h"
#include "InputValidation.h"
#include "CursorTrakedWindow.h"

Move getValidMove(struct Board_Struct* board, struct Height_Struct* height, TurnType playerTurn, CursorTrackedWindow* win,CursorTrackedWindow* wind, int *cursor_print, int *current_state, FILE * fp) {
    char blankSpace[1];
    blankSpace[0] = ' ';
    Move move;
    //  mvwaddch(win->cursesWin, win->cursorRow+ numRo, win->cursorCol,'j']);
    mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol,"XO"[playerTurn]); //
    wmove(win->cursesWin, win->cursorRow, win->cursorCol);
    while (true) {

        char input = wgetch(win->cursesWin);
        printBoard(win, board->numRows, board->numCols, fp,0);
        printBoard(wind, board->numRows, board->numCols, fp,13);
        if (input == 'j' || input == 'a') {
            //  mvwaddch(win->cursesWin , win->cursorRow - 1, win->cursorCol - 1, blankSpace[0]);
            //   printf("curscol = %d\n",'jx  vc xv cx c win->cursorCol);


            if (win->cursorCol > 0) {
                mvwaddch(win->cursesWin , 0, win->cursorCol , blankSpace[0]);
                //mvwaddch(win->cursesWin, 5,0,'f');
                win->cursorCol -= 1;
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol,"XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
                // printBoard(board->theBoard, file, cursor_print, current_state, playerTurn);
                //printBoard(board, fp, cursor_print, current_state, playerTurn);
                //mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol,"XO"[playerTurn]);
                // wmove(win->cursesWin, win->cursorRow, win->cursorCol);
                //  printf(">0 curscol = %d\n", win->cursorCol);
            } else if (win->cursorCol <= 0) {
                mvwaddch(win->cursesWin , 0, 0 , blankSpace[0]);
                win->cursorCol += board->numCols - 1; //why is it -1?
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol,"XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
                //  printf("<=0curscol = %d\n", win->cursorCol);
            }
        } else if (input == 's' || input == 'k') {
            if (win->cursorCol < board->numCols - 1) {
                win->cursorCol += 1;
                // printf("cursorR = %d cursorC = %d", win->cursorRow, win->cursorCol-1);
                mvwaddch(win->cursesWin , 0,win->cursorCol-1  , blankSpace[0]);
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol,"XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
            } else if (win->cursorCol >= board->numCols -1){
                //   printf("curscol is over limit = %d\n", win->cursorCol);
                win->cursorCol = 0;
                //printf("curscol should b 0 NOW = %d\n", win->cursorCol);
                mvwaddch(win->cursesWin , 0, board->numCols - 1  , blankSpace[0]);
                mvwaddch(win->cursesWin, win->cursorRow, win->cursorCol,"XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
            }
        }

        else if (input == ' ' || input == '\n') {

            if (height->h[win->cursorCol] <= board->numRows-1) {
                //   printf("works");
                // move.row = (board->numRows-1) - height->h[win->cursorCol];
                //  move.col = win->cursorCol;
                move.row = (board->numRows-1) - (height->h[win->cursorCol]);
                //   printf("%d",win->cursorCol);
                *cursor_print = win->cursorCol;
                // printf("numrowsboard = %d, heightatcursorcol = %d\n", board->numRows,height->h[win->cursorCol] );
                //printf("%d", move.row);
                move.col = win->cursorCol;
                if (win->cursorCol == 0 && win->cursorRow == 0){
                    // printf("Hello");
                    //  printf("move.col = %d move.row = %d",move.col, move.row);
                }
                //printf("move.col = %d move.row = %d",move.col, move.row);
                mvwaddch(win->cursesWin, win->cursorRow + ((board->numRows) - (height->h[win->cursorCol]) ), win->cursorCol,"XO"[playerTurn]);
                wmove(win->cursesWin, win->cursorRow, win->cursorCol);
                // printf("win->cursorCol = %d\n", win->cursorCol);
                //wmove(win->cursesWin, win->cursorRow, win->cursorCol);
                // win->cursorCol = win->cursorCol;
                // win->cursorRow = (board->numRows-1) - height->h[win->cursorCol];;
                move.marker = "XO"[playerTurn];
                *current_state = playerTurn;
                height->h[win->cursorCol] += 1;
                return move;
                //height.h[i] += 1;

            }
        }
        // printf("refresh");
        wrefresh(win->cursesWin);
    }
    //  printf("refresh");
    //  wrefresh(win->cursesWin);

}

//void printwinner(int winner, CursorTrackedWindow* win){
// printf("here");
//    mvwaddch(win->cursesWin, 0,0,'f');
//}



bool isValidMove(Move move, struct Board_Struct* board, int numArgsRead, int numArgsNeeded) {
    return isValidFormat(numArgsRead, numArgsNeeded) &&
           isInRange(move.row, 0, board->numRows - 1) &&
           isInRange(move.col, 0, board->numCols - 1) &&
           board->theBoard[move.row][move.col] == board->blankChar;
}

//void printWinnerinwindow(int winner){
//mvwaddch(win->cursesWin, 5,0,"XO"[winner]);
//}

const char* PlayerToString(TurnType player) {
    static const char p1[] = "Player1";
    static const char p2[] = "Player2";
    if (player == Player1) {
        return p1;
    } else {
        return p2;
    }
}
