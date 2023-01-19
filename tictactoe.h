#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <QWidget>
#include <QVector>


const int BOARD_CELLS_NUM = 9;
const int LINES_NUM = 8;

enum gameCond
{
    WIN_HUMAN,
    WIN_COMP,
    GAME_DRAW,
    NOT_DEFINED, // in game
    CHECKED      // for pow games
};


//   col col col     diag
//   -0- -1- -2- -7-
//   [0] [1] [2] -3- row
//   [3] [4] [5] -4- row
//   [6] [7] [8] -5- row
//               -6-
//                   diag


class TicTacToe : public QWidget
{

    public:
        TicTacToe(QWidget *parent, int sizeNum);
        ~TicTacToe();

        QPushButton *btnCells;
        int cellSize;

        //int getGameStatus () const;
        //void setGameStatus (gameCond);
        int cellInit(int cell, int type);
        int gameStatus;

        int boardAnalysis();
        int compTurn();
        void checkGameEnd();


    private:


        QLabel *lblcellCompleted;

        int gameBoard[9];
        int linesScore[8];

        int winLineNum;

        QVector <int> emptyCells;
        static const int linesMap[LINES_NUM][3];
        static int fontSizeMap[13];

        //




        //int findEmptyInLine (int line);

        int getEmptyCellInLine(int line) const;

    signals:

        void handleCellClick (int cell);

};


#endif // TICTACTOE_H
