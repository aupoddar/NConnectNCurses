#include <stdio.h>
#include <ncurses.h>
#include "board.h"
#include "move.h"
#include "win.h"
#include "CursorTrakedWindow.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc,char *argv[]) {
   // int dummy;
   // printf("Waiting for debugger. Press a number to continue: ");
  //  scanf("%d",&dummy);



    int rows = atoi(argv[1]); //get row from user
    int cols = atoi(argv[2]); //get col from user
    int n_val = atoi(argv[3]); //n
    int cursor_print;
    int current_state; //0 means player x, 1 means player 0, 2 means player x won, 3 means player 0 won, 4 means tie
    //FILE *fout;
    initscr();
    noecho();
    cbreak();

    CursorTrackedWindow boardWindow = newCursorTrackedWindow(rows, cols, 0, 0); //making the display for the window
    CursorTrackedWindow winnerDisplay = newCursorTrackedWindow(1, 13, rows+1, 0);
    fillWindow(&boardWindow, '*');
    fillWindow(&winnerDisplay, ' ');
    //mvaddch(0, 0, 'X');
    keypad(boardWindow.cursesWin, true);
    wrefresh(boardWindow.cursesWin);
    keypad(winnerDisplay.cursesWin, true);
    wrefresh(winnerDisplay.cursesWin);
    FILE *  fp = fopen(argv[4],"w");

    //make a board

    Board board = makeBoard(rows,cols,n_val,'*'); //making board for file?
    //  Board playArea = makeBoard(1, cols, ' ');
    Height height = makeHeight(rows, cols);
    TurnType playerTurn = Player1;
    //add ch
    // pick a starting player
    while(!isGameOver(board)){
        //show them the state of the game
        //printBoard(board);
        //get a move from the user
        Move move = getValidMove(&board, &height, playerTurn, &boardWindow, &winnerDisplay, &cursor_print, &current_state, fp);
        //place their move on the board
        placeMove(move, &board, &boardWindow);
        //change turn
        //playerTurn = (playerTurn + 1) % 2;
        //printBoard(board, fp, cursor_print, current_state, playerTurn);
        playerTurn = playerTurn == Player1 ? Player2 : Player1;
        //printf("%d", cursor_print);
        //printBoard(&boardWindow, rows, cols, fp); //printBoard(board, fp);
    }
    printBoard(&boardWindow, rows, cols, fp,0); //printBoard(board, fp);

    //printBoard(&winnerDisplay,1, 13, fp,13);

    delwin(boardWindow.cursesWin);
    endwin();
    //print the winning board
    //printBoard(board);

    //declare who wins or a tie
    declareWinner(board, playerTurn,fp,&winnerDisplay);
// fillWindow(&winnerDisplay, '_');
    //fillWinner(&winnerDisplay, winner);

//  wrefresh(winnerDisplay.cursesWin);
// printwinner(winner,&boardWindow);
//  FILE *  fp = fopen(argv[4],"w");
    //printBoard(board, fp, cursor_print, current_state, playerTurn);
// fout = fopen(argv[4], "w");

    fclose(fp);
    //clean up
    cleanUpBoard(&board);

    return 0;
}
