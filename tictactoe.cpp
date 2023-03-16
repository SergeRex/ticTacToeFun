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

const int TicTacToe::linesMap[8][3]= {{0,1,2},{3,4,5},{6,7,8}, // rows 0-2
                                      {0,3,6},{1,4,7},{2,5,8}, // columns 3-5
                                      {0,4,8},{2,4,6}};        //diagonales 6-7

//----------------------------------------------------------------------------------------------------

TicTacToe::TicTacToe(QWidget *parent, int boardSize)
     : QWidget(parent)
{
    boardSize-=5;
    this->setFixedSize(boardSize,boardSize);
    int cellSize=(boardSize/3);

    QFont qFont = QFont("Arial", (cellSize*70)/100);
    QSignalMapper *signalMapper = new QSignalMapper;

    for (int i=0; i<BOARD_CELLS_NUM; i++)  //
    {
        btnCells[i] = new QPushButton(" ", this);

        btnCells[i]->setFixedSize(cellSize+3,cellSize+3);
        btnCells[i]->setFont(qFont);
        btnCells[i]->setCursor(Qt::PointingHandCursor);
        btnCells[i]->move((i/3)*cellSize,(i%3)*cellSize);

        btnCells[i]->setStyleSheet("");

        connect(btnCells[i], SIGNAL(clicked()), signalMapper, SLOT (map()));
        signalMapper->setMapping(btnCells[i], i);
    }

    connect(signalMapper, &QSignalMapper::mappedInt,this, &TicTacToe::handleCellClick);

    lblcellCompleted = new QLabel(this);
}
//----------------------------------------------------------------------------------------------------
TicTacToe::TicTacToe(QWidget *parent)
     : QWidget(parent)
{
    virtualBoard=true;
}
//----------------------------------------------------------------------------------------------------
TicTacToe::~TicTacToe()
{
    if(!virtualBoard)
    {
    this->hide();
    for (int i=0; i<9;i++) delete btnCells[i];
    //emptyCells.clear();
    delete lblcellCompleted;
    }
}
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

    winLineNum=-1;

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
                    if (!virtualBoard) MainWindow::boardsWin++;
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
                    if (!virtualBoard) MainWindow::boardsLost++;
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
     if (!virtualBoard) MainWindow::boardsDraw++;
     return GAME_DRAW;
    }

 gameStatus=NOT_DEFINED;
 return NOT_DEFINED;
}
//----------------------------------------------------------------------------------------------------

void TicTacToe::checkGameEnd()
{

    if ((virtualBoard)||(gameStatus==NOT_DEFINED)) return;// no draw for virtual game break or if game is not finished


    for(int i=0;i<BOARD_CELLS_NUM;i++)
        {
         btnCells[i]->setDisabled(true);

         if (gameStatus==WIN_COMP) btnCells[i]->setStyleSheet("background-color: rgb(255, 213, 219)");
         if (gameStatus==WIN_HUMAN) btnCells[i]->setStyleSheet("background-color: rgb(224, 255, 210);");
         if (gameStatus==GAME_DRAW) btnCells[i]->setStyleSheet("background-color: lightYellow");
        }

    if ((gameStatus!=GAME_DRAW)&&(winLineNum!=-1))
        {

        for (int i=0; i<3;i++)
            {
            int cell=linesMap[winLineNum][i];

            if (gameStatus==WIN_COMP) btnCells[cell]->setStyleSheet("background-color: Red");
            if (gameStatus==WIN_HUMAN) btnCells[cell]->setStyleSheet("background-color: lightGreen");
            }
        }

    lblcellCompleted->setGeometry(0,0,this->width(),this->height());


    if ((MainWindow::gameType==POW2_GAME)||(MainWindow::gameType==POW3_GAME))
    {
        if (gameStatus==WIN_COMP) lblcellCompleted->setPixmap(QPixmap("./srs/signO.png"));
        if ((gameStatus==WIN_HUMAN)||(gameStatus==GAME_DRAW)) lblcellCompleted->setPixmap(QPixmap("./srs/signX.png"));
    }
    else lblcellCompleted->setPixmap(QPixmap("./srs/checked2.png"));

    lblcellCompleted->setScaledContents(true);
    lblcellCompleted->show();

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
    gameBoard[cell]=type;

    // assign buttons if game is not virtual
    if((!virtualBoard)&&(type==0))
    {
        btnCells[cell]->setText(" ");
        btnCells[cell]->setDisabled(false);
    }

    if((!virtualBoard)&&(type==1))
    {
        btnCells[cell]->setText("O");
        btnCells[cell]->setDisabled(true);
    }

    if((!virtualBoard)&&(type==-1))
    {
        btnCells[cell]->setText("X");
        btnCells[cell]->setDisabled(true);
    }

    return boardAnalysis();  // check game status after move
}
//----------------------------------------------------------------------------------------------------
int TicTacToe::compTurn()
{

    //QMessageBox::information(this, "Msg", "Begin ");

    // priority 1 -- put 3rd "O" if two "O" in line - COMPUTER DEFINETLY WIN
    for (int line=0; line<LINES_NUM;line++)
     if (linesScore[line]==2) return getEmptyCellInLine(line);

    // priority 2 -- put "O" if two "X" in line - DEFENCE NOT LOOSE
    for (int line=0; line<LINES_NUM;line++)
     if (linesScore[line]==-2)return getEmptyCellInLine(line);

    // priority 3 -- put "O" in the center cell
    if(emptyCells.contains(4)) return 4;

    // priority 5 -- put "O" in any of 4 corners

    if(emptyCells.contains(0)) return 0;

    if(emptyCells.contains(2)) return 2;

    if(emptyCells.contains(6)) return 6;

    if(emptyCells.contains(8)) return 8;

    // lowest prioryty - -put "O" in the first free cell
    return emptyCells[0];
}
//----------------------------------------------------------------------------------------------------
int TicTacToe::getEmptyCellsQty() const
{
    int emptyCellsQty=0;
    for (int i=0; i<BOARD_CELLS_NUM;i++)
        if (gameBoard[i]==0) emptyCellsQty++;
    return emptyCellsQty;
}
