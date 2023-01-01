#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <QLabel>
#include <QPushButton>
#include <QSignalMapper>
#include <QWidget>
#include <QVector>


//const int CELL_NORMAL_SIZE = 50;
//const QSize BUTTON_SIZE = QSize(CELL_NORMAL_SIZE,CELL_NORMAL_SIZE);
//const QFont FONT_SIZE = QFont("Arial", 35);



const int BOARD_CELLS_NUM = 9;
const int LINES_NUM = 8;

enum gameCond
{
    WIN_HUMAN,
    WIN_COMP,
    GAME_DRAW,
    NOT_DEFINED,     // not yet
    FULL_GAMEBOARD,
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
        TicTacToe(QWidget *parent, int size, int font_size, int firstCellOccupied);
        ~TicTacToe();

        int getGameStatus () const;

    private:

        //
        QLabel *lbStatus;
        QPushButton *btnCells;
        //

        int *gameBoard;
        int  *linesScore;

        int gameStatus;
        int winLineNum;

        QVector <int> emptyCells;
        static int linesMap[LINES_NUM][3];

        //

        void boardAnalysis();
        void checkGameEnd();
        void compTurn();
        int findEmptyInLine (int line);

        int getEmptyCellInLine(int line) const;
        void cellInit(int cell, int type);


    signals:

        void handleCellClick (int cell);

};


#endif // TICTACTOE_H
