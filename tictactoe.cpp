#include <QPushButton>
#include <QApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QLabel>

#include "tictactoe.h"
#include "mainwindow.h"

//   col col col     diag
//   -0- -1- -2- -7-
//   [0] [1] [2] -3- row
//   [3] [4] [5] -4- row
//   [6] [7] [8] -5- row
//               -6-
//                   diag

const int TicTacToe::linesMap[8][3]=  {{0,1,2},{3,4,5},{6,7,8}, // rows 0-2
                                {0,3,6},{1,4,7},{2,5,8},        // columns 3-5
                                {0,4,8},{2,4,6}};               //diagonales 6-7

int TicTacToe::fontSizeMap[13]={0,60,50,45,32,28,24,20,16,12,8,4,4};

//----------------------------------------------------------------------------------------------------

TicTacToe::TicTacToe(QWidget *parent, int cellSize)
     : QWidget(parent)
{

    //TicTacToe *ttt = new TicTacToe(this,cellSize);



    this->cellSize=cellSize;
    //gameBoard = new int[9];
    //linesScore = new int[8];
    gameStatus=NOT_DEFINED;

    int bdWide = (BLACKBOARD_WIDTH)/cellSize;
    int bdFontSz=fontSizeMap[cellSize];

    this->setFixedSize(bdWide-10,bdWide-10);

    bdWide=bdWide/3;

    //bdWide=bdWide*19/20;

    QSize qSize;
    qSize = QSize(bdWide,bdWide);
    QFont qFont = QFont("Arial", bdFontSz);

    btnCells = new QPushButton[9]; // cells-buttons

    QSignalMapper *signalMapper = new QSignalMapper;
    QGridLayout *gridbox = new QGridLayout(this);
    //QPushButton *pbt = new QPushButton(this);
    //pbt->setGeometry(QRect(100, 50, 141, 31));
    //pbt->show();
    gridbox->setSpacing(0);
    gridbox->setContentsMargins(0, 0, 0, 0);

    for (int i=0; i<BOARD_CELLS_NUM; i++)  //
    {
        btnCells[i].setFixedSize(bdWide-10,bdWide-10);
        btnCells[i].setFont(qFont);
        btnCells[i].setCursor(Qt::PointingHandCursor);
        cellInit(i,0);

        //gridbox->setAlignment(&btnCells[i], Qt::AlignHCenter | Qt::AlignHCenter);

        gridbox->addWidget(&btnCells[i], i/3, i%3, Qt::AlignHCenter | Qt::AlignHCenter);

        connect(btnCells+i, SIGNAL(clicked()), signalMapper, SLOT (map()));
        signalMapper->setMapping(btnCells+i, i);
    }

    connect(signalMapper, &QSignalMapper::mappedInt,this, &TicTacToe::handleCellClick);

    //if (firstCellOccupied!=-1) cellInit(firstCellOccupied,1);
    lblcellCompleted = new QLabel(this);
}

//----------------------------------------------------------------------------------------------------
TicTacToe::~TicTacToe()
{
    this->hide();
    delete [] btnCells;

    emptyCells.clear();
    delete lblcellCompleted;

}
//----------------------------------------------------------------------------------------------------
/*int TicTacToe::getGameStatus () const
{
    return gameStatus;
}*/
//----------------------------------------------------------------------------------------------------
void TicTacToe::handleCellClick (int cell)
{
   if (cellInit(cell,-1)==NOT_DEFINED) cellInit(compTurn(),1);
    checkGameEnd();




    /* cellInit(cell,-1);  //human's turn

    boardAnalysis();    // check game status

    if (gameStatus==NOT_DEFINED)
    {
      cellInit(compTurn(),1);      // comp's turn
      boardAnalysis(); // check game status
    }

    checkGameEnd();  // board end game actions

   */
}
//----------------------------------------------------------------------------------------------------

int TicTacToe::boardAnalysis ()
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
                    MainWindow::boardsWin++;
                    return WIN_HUMAN;
                }
               }
            if (maxLineScore<linesScore[i])
               {
                maxLineScore=linesScore[i];
                if(maxLineScore==3)
                {
                    winLineNum=i;
                    gameStatus=WIN_COMP;
                    MainWindow::boardsLost++;
                    return WIN_COMP;
                }

               }
         }

    emptyCells.clear();

    for(int cellnum=0; cellnum<BOARD_CELLS_NUM; cellnum++)
    {
        if (gameBoard[cellnum]==0)
            emptyCells.push_back(cellnum);
    }

 if (emptyCells.isEmpty())
    {
     gameStatus=GAME_DRAW;
     MainWindow::boardsDraw++;
     return GAME_DRAW;
    }

 gameStatus=NOT_DEFINED;
 return NOT_DEFINED;

}
//----------------------------------------------------------------------------------------------------

void TicTacToe::checkGameEnd()
{

    if (gameStatus==NOT_DEFINED) return;

    for(int i=0;i<9;i++)
        {
            btnCells[i].setDisabled(true);
            btnCells[i].setStyleSheet("background-color: lightYellow");
        }

    if (gameStatus!=GAME_DRAW)
        {
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
    if (MainWindow::gameType==POW2_GAME)
    {

        lblcellCompleted->setGeometry(0,0,this->width(),this->height());

        if (gameStatus==WIN_COMP) lblcellCompleted->setPixmap(QPixmap("./srs/signO.png"));
        if ((gameStatus==WIN_HUMAN)||(gameStatus==GAME_DRAW)) lblcellCompleted->setPixmap(QPixmap("./srs/signX.png"));
        //if  lblcellCompleted->setPixmap(QPixmap("./srs/signX.png"));

        //lblcellCompleted->setPixmap(pixmap);
        lblcellCompleted->setScaledContents(true);
        lblcellCompleted->show();

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

int TicTacToe::cellInit(int cell, int type)
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

    return boardAnalysis();  // check game status after move
}

//----------------------------------------------------------------------------------------------------

int TicTacToe::compTurn()
{
    //int cell=emptyCells[0];

    for (int line=0; line<LINES_NUM;line++) //if x2 "O" in line
     if (linesScore[line]==2)
     {
        // cellInit(getEmptyCellInLine(line),1);
         return getEmptyCellInLine(line);
     }

    for (int line=0; line<LINES_NUM;line++) //if x2 "X" in line
     if (linesScore[line]==-2)
     {
        // cellInit(getEmptyCellInLine(line),1);
         return getEmptyCellInLine(line);
     }

    if(emptyCells.size()==1)            // no choise if 1 empty left
     {
        //cellInit(emptyCells[0],1);
        return emptyCells[0];
     }

    if(emptyCells.contains(4))          // center
    {
       //cellInit(4,1);
       return 4;
    }


    if(emptyCells.contains(0))          // corners
    {
       //cellInit(0,1);
       return 0;
    }


    if(emptyCells.contains(2))
    {
       //cellInit(2,1);
       return 2;
    }


    if(emptyCells.contains(6))
    {
       //cellInit(6,1);
       return 6;
    }

    if(emptyCells.contains(8))
    {
       //cellInit(8,1);
       return 8;
    }

 // if nothing above than last empty cell in list
    //cellInit(emptyCells.size()-1,1);
    return emptyCells.size()-1;

}
//----------------------------------------------------------------------------------------------------
