#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

#include "tictactoe.h"

//   col col col     diag
//   -0- -1- -2- -7-
//   [0] [1] [2] -3- row
//   [3] [4] [5] -4- row
//   [6] [7] [8] -5- row
//               -6-
//                   diag

int TicTacToe::linesMap[8][3]=  {{0,1,2},{3,4,5},{6,7,8}, // rows 0-2
                                {0,3,6},{1,4,7},{2,5,8},  // columns 3-5
                                {0,4,8},{2,4,6}};         //diagonales 6-7

//----------------------------------------------------------------------------------------------------

TicTacToe::TicTacToe(QWidget *parent, int cellSize, int fontSize, int firstCellOccupied)
     : QWidget(parent)
{

    gameBoard = new int[9];
    linesScore = new int[8];
    gameStatus=NOT_DEFINED;

    QSize qSize = QSize(cellSize,cellSize);
    QFont qFont = QFont("Arial", fontSize);

    //lbStatus = new QLabel;
    btnCells = new QPushButton[9]; // cells-buttons

    QSignalMapper *signalMapper = new QSignalMapper;
    QGridLayout *gridbox = new QGridLayout(this);

    for (int i=0; i<BOARD_CELLS_NUM; i++)
    {
        btnCells[i].setFixedSize(qSize);
        btnCells[i].setFont(qFont);
        btnCells[i].setCursor(Qt::PointingHandCursor);
        cellInit(i,0);

        gridbox->addWidget(&btnCells[i], i/3, i%3);

        connect(btnCells+i, SIGNAL(clicked()), signalMapper, SLOT (map()));
        signalMapper->setMapping(btnCells+i, i);
    }

    connect(signalMapper, &QSignalMapper::mappedInt,this, &TicTacToe::handleCellClick);

    if (firstCellOccupied!=-1) cellInit(firstCellOccupied,1);
}

//----------------------------------------------------------------------------------------------------

TicTacToe::~TicTacToe()
{
    this->hide();

    //delete lbStatus;
    delete [] gameBoard;
    delete [] linesScore;
    delete [] btnCells;

    emptyCells.clear();
}
//----------------------------------------------------------------------------------------------------
int TicTacToe::getGameStatus () const
{
    return gameStatus;
}
//----------------------------------------------------------------------------------------------------
void TicTacToe::handleCellClick (int cell)
{
    cellInit(cell,-1);

    boardAnalysis();

    if (gameStatus==NOT_DEFINED)
    {
      compTurn();
      boardAnalysis();
    }

    checkGameEnd();
}
//----------------------------------------------------------------------------------------------------

void TicTacToe::boardAnalysis ()
{

    // populating score array of all 8 lines with sums of all lines cells;
    for (int line=0; line<LINES_NUM; line++)
    {
       linesScore[line]=0;
       for (int k=0; k<3;k++)linesScore[line]+=gameBoard[linesMap[line][k]];
    }

    //   col col col     diag
    //   -0- -1- -2- -7-
    //   [0] [1] [2] -3- row
    //   [3] [4] [5] -4- row
    //   [6] [7] [8] -5- row
    //               -6-
    //                   diag


    int maxLineScore=0;
    int minLineScore=0;

    for(int i=0; i<LINES_NUM; i++)
        {
            if (minLineScore>linesScore[i])
               {
                minLineScore=linesScore[i];
                if (minLineScore==-3)
                {
                    winLineNum=i;
                    gameStatus=WIN_HUMAN;
                    return;
                }
               }
            if (maxLineScore<linesScore[i])
               {
                maxLineScore=linesScore[i];
                if(maxLineScore==3)
                {
                    winLineNum=i;
                    gameStatus=WIN_COMP;
                    return;
                }

               }
         }

    emptyCells.clear();

    for(int cellnum=0; cellnum<BOARD_CELLS_NUM; cellnum++)
    {
        if (gameBoard[cellnum]==0)
            emptyCells.push_back(cellnum);
    }

 if (emptyCells.isEmpty()) gameStatus=GAME_DRAW;
                      else gameStatus=NOT_DEFINED;

}
//----------------------------------------------------------------------------------------------------

void TicTacToe::checkGameEnd()
{

    if (gameStatus==NOT_DEFINED) return;


    //QRgb colorValue;

    for(int i=0;i<9;i++)
    {
        btnCells[i].setDisabled(true);
        btnCells[i].setStyleSheet("background-color: lightYellow");
    }

    if (gameStatus==GAME_DRAW) return;

    for (int i=0; i<3;i++)
    {
        int cell=linesMap[winLineNum][i];
       /* QPalette palette = btnCells[cell].palette();
        palette.setColor(btnCells[cell].backgroundRole(), colorValue);
        palette.setColor(btnCells[cell].foregroundRole(), colorValue);
        btnCells[cell].setPalette(palette);*/

        if (gameStatus==WIN_COMP) btnCells[cell].setStyleSheet("background-color: Red");
        if (gameStatus==WIN_HUMAN) btnCells[cell].setStyleSheet("background-color: lightGreen");

    }

}
//----------------------------------------------------------------------------------------------------

int TicTacToe::getEmptyCellInLine(int line) const
{
    for (int i=0; i<3;i++)
    {
        if (gameBoard[linesMap[line][i]]==0)
        {
           return linesMap[line][i];
        }
    }
    return -1;
}

//----------------------------------------------------------------------------------------------------

void TicTacToe::cellInit(int cell, int type)
{
    if (type==0)
        {
        btnCells[cell].setText(" ");
        btnCells[cell].setDisabled(false);
        gameBoard[cell]=0;
        }

    if (type==1)
        {
        btnCells[cell].setText("O");
        btnCells[cell].setDisabled(true);
        gameBoard[cell]=1;
        }

    if (type==-1)
        {
        btnCells[cell].setText("X");
        btnCells[cell].setDisabled(true);
        gameBoard[cell]=-1;
        }
}

//----------------------------------------------------------------------------------------------------

void TicTacToe::compTurn()
{
    //int cell=emptyCells[0];

    for (int line=0; line<LINES_NUM;line++) //if x2 "O" in line
     if (linesScore[line]==2)
     {
         cellInit(getEmptyCellInLine(line),1);
         return;
     }

    for (int line=0; line<LINES_NUM;line++) //if x2 "X" in line
     if (linesScore[line]==-2)
     {
         cellInit(getEmptyCellInLine(line),1);
         return;
     }

    if(emptyCells.size()==1)            // no choise if 1 empty left
     {
        cellInit(emptyCells[0],1);
        return;
     }

    if(emptyCells.contains(4))          // center
    {
       cellInit(4,1);
       return;
    }


    if(emptyCells.contains(0))          // corners
    {
       cellInit(0,1);
       return;
    }


    if(emptyCells.contains(2))
    {
       cellInit(2,1);
       return;
    }


    if(emptyCells.contains(6))
    {
       cellInit(6,1);
       return;
    }

    if(emptyCells.contains(8))
    {
       cellInit(8,1);
       return;
    }

 // if nothing above than last empty cell in list
    cellInit(emptyCells.size()-1,1);

}
//----------------------------------------------------------------------------------------------------
