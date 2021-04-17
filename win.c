//
// Created by Auboni Poddar on 2019-02-13.
//

#include <stdio.h>
#include "win.h"
#include "CursorTrakedWindow.h"

bool isGameOver(Board board) {
    return win(board) || tie(board);
}

bool win(Board board) {
    return horzWin(board) || vertWin(board) || diagWin(board);
}

bool horzWin(Board board) {
// printf("board.n = %d", board.n);
    int numInARow;
    char curPlayer;


    numInARow = 0;
    curPlayer = board.blankChar;

    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {

            //fprintf(fp, "r = %d, c = %d, numInARow = %d, curPlayer = %c board.theBoard[row][col] = %c \n", row, col, numInARow, curPlayer, board.theBoard[row][col]);

            if (board.theBoard[row][col] == board.blankChar) {
                numInARow = 0;
                curPlayer = board.blankChar;
                continue;
            } else {
                // new non-blank char
                if(numInARow == 0) {
                    //new non-blank char
                    curPlayer = board.theBoard[row][col];
                    numInARow++;
                } else {
                    // successive player keep counting
                    if(curPlayer == board.theBoard[row][col]) {
                        // same player keep counting
                        numInARow++;
                        if (numInARow == board.n) {
                            //printf("DoneH\n");
                            return true;
                        }
                    }
                    else {
                        // different player, count one and update curtrent player
                        curPlayer = board.theBoard[row][col];
                        numInARow = 1;
                    }

                }

            }
        }
        numInARow = 0;
        curPlayer = board.blankChar;
    }
    return false;
}

bool vertWin(Board board) {
    int numInARow;
    for (int col = 0; col < board.numCols; ++col) {
        numInARow = 0; //0
        // printf("%c",board.theBoard[0][col]);
        if (board.theBoard[board.numRows-1][col] == board.blankChar) {
            //printf("here");
            continue;
        }

        int board_compare_v = board.theBoard[board.numRows - 1][col];
        for (int row = board.numRows - 1; row >= 0; --row) {
            //   printf("row = %d, board.theBoard[row-1][col] = %c, board.theBoard[board.numROws-i][col = %c", row,board.theBoard[row][col],board.theBoard[board.numRows-i][col] );
            if (board.theBoard[row][col] == board_compare_v) {
                //  printf("here");
                numInARow++;
                //   printf("numINRow = %d\n",numInARow);
                if (numInARow == board.n) {
                    // printf("numInRow = %d, board.n = %d", numInARow, board.n) ;
                    return true;
                }
            } else {
                if (board.theBoard[row][col] != board.blankChar){
                    board_compare_v = board.theBoard[row][col];
                } else
                    break;
            }
        }
    }
    return false;
}

bool diagWin(Board board) {
    return leftDiagWin(board) || rightDiagWin(board);
}

bool leftDiagWin(Board board) {

    //Scan all rows with column 0

    for(int m=0; m < board.numRows -board.n + 1; m++) {
        if(subleftDiagWinR(board, m, 0)) return true;
    }

    //Scan all columns with row 0
    for(int n=0; n < board.numCols -board.n + 1; n++) {
        if(subleftDiagWinC(board, 0, n)) return true;
    }

    return false;
}

bool subleftDiagWinC(Board board, int r, int c) {
    int numInARow;
    char curPlayer;

    numInARow = 0;
    curPlayer = board.blankChar;


    while ( (c < board.numCols) && (r < board.numRows) ) {

        if (board.theBoard[r][c] == board.blankChar) {
            numInARow = 0;
            c++; r++;
            continue;


        } else {
            // non blank character
            if(numInARow == 0) {
                // new non-blank character
                curPlayer = board.theBoard[r][c];
                numInARow++;
            } else {
                // same player keep counting
                if(curPlayer == board.theBoard[r][c]) {
                    numInARow++;
                    if (numInARow == board.n) {
                        return true;
                    }

                }
                else {
                    // different player, count one and update curtrent player
                    curPlayer = board.theBoard[r][c];
                    numInARow = 1;
                }
            }

        }
        c++; r++;
    }
    return false;
}

bool subleftDiagWinR(Board board, int r, int c) {
    int numInARow;
    char curPlayer;

    numInARow = 0;
    curPlayer = board.blankChar;

    while ( (c < board.numCols) && (r < board.numRows) ) {


        if (board.theBoard[r][c] == board.blankChar) {
            numInARow = 0;
            c++; r++;
            continue;
        } else {
            // non blank character
            if(numInARow == 0) {
                // new non-blank character
                curPlayer = board.theBoard[r][c];
                numInARow++;
            } else {
                // same player keep counting
                if(curPlayer == board.theBoard[r][c]) {
                    numInARow++;
                    if (numInARow == board.n) {
                        return true;
                    }
                }
                else {
                    // different player, count one and update curtrent player
                    curPlayer = board.theBoard[r][c];
                    numInARow = 1;
                }
            }

        }
        c++; r++;
    }
    return false;
}

/**
 * Check for a right diagonal win
 * One that looks like
 *      X
 *    X
 *  X
 * @param board
 * @return
 */
bool rightDiagWin(Board board) {

    //Scan all cols(0 to max) with last row
    for(int n=0; n < board.numCols -board.n + 1; n++) {
        if(subrightDiagWinC(board, board.numRows-1, n)) return true;
    }
    //Scan all rows(max to min) with column 0
    for(int m=board.numRows-1; m > board.numRows -board.n; m--) {
        if(subrightDiagWinR(board, m, 0)) return true;
    }
    return false;
}

bool subrightDiagWinC(Board board, int r, int c) {
    int numInARow;
    char curPlayer;

    numInARow = 0;
    curPlayer = board.blankChar;

    while ( (c < board.numCols) && (r >= 0) ) {

        if (board.theBoard[r][c] == board.blankChar) {
            numInARow = 0;
            r--; c++;
            continue;
        } else {
            // non blank character
            if(numInARow == 0) {
                // new non-blank character
                curPlayer = board.theBoard[r][c];
                numInARow++;
            } else {
                // same player keep counting
                if(curPlayer == board.theBoard[r][c]) {
                    numInARow++;
                    if (numInARow == board.n) {
                        return true;
                    }

                }
                else {
                    // different player, count one and update curtrent player
                    curPlayer = board.theBoard[r][c];
                    numInARow = 1;
                }
            }

        }
        r--; c++;
    }
    return false;
}

bool subrightDiagWinR(Board board, int r, int c) {
    int numInARow;
    char curPlayer;

    numInARow = 0;
    curPlayer = board.blankChar;

    while ( r >= 0 && c < board.numCols) {

        if (board.theBoard[r][c] == board.blankChar) {
            numInARow = 0;
            r--; c++;
            continue;
        } else {
            // non blank character
            if(numInARow == 0) {
                // new non-blank character
                curPlayer = board.theBoard[r][c];
                numInARow++;
            } else {
                // same player keep counting
                if(curPlayer == board.theBoard[r][c]) {
                    numInARow++;
                    if (numInARow == board.n) {

                        return true;
                    }

                }
                else {
                    // different player, count one and update curtrent player
                    curPlayer = board.theBoard[r][c];
                    numInARow = 1;
                }
            }

        }
        r--; c++;
    }
    return false;
}

bool tie(Board board) {

    if(win(board)){
        return false;
    }

    for (int row = 0; row < board.numRows; ++row) {
        for (int col = 0; col < board.numCols; ++col) {
            if(board.theBoard[row][col] == board.blankChar){
                return false;
            }
        }
    }
    return true;
}

void declareWinner(Board board, TurnType playerTurn, FILE *input, CursorTrackedWindow* window) {
    if(win(board)){
        //if someone one it would actually be the loser's turn
        //so account for this here
        int winner = playerTurn == Player1 ? Player2 : Player1;
        winner++;
        if (winner == 1){
            char player_one[14] = "Player 1 won!";
            //mvwaddstr(CursorTrackedWindow* window, board.numRows + 1, 0, player_one);
            fprintf(input,"%s", player_one);
        }else if(winner ==2){
            char player_two[14] = "Player 2 won!";
            fprintf(input,"%s", player_two);
        }
        //fprintf(input,"Player %d won!\n", winner,);

    }else{
        char tie[9] = "Tie Game";
        fprintf(input,"%s", tie);
    }
}
