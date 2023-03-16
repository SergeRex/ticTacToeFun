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
    CHECKED,
    GAME_FINISHED,
    COMPLETED,
    LOST
    // for pow games
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
        TicTacToe(QWidget *parent, int boardSize);
        TicTacToe(QWidget *parent); // virtual board
        ~TicTacToe();

        int gameStatus=NOT_DEFINED;

        QPushButton *btnCells[9];

        int cellInit(int cell, int type);
        int boardAnalysis();
        int compTurn();
        void checkGameEnd();

        int getEmptyCellsQty() const;



    private:

        bool virtualBoard=false;
        QLabel *lblcellCompleted;

        int gameBoard[9]={0,0,0,0,0,0,0,0,0};

        int linesScore[8];

        int winLineNum=-1;
        QVector <int> emptyCells;

        static const int linesMap[LINES_NUM][3];

        int getEmptyCellInLine(int line) const;

    signals:

        void handleCellClick (int cell);

};


#endif // TICTACTOE_H
