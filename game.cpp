#include "game.h"
#include "mainwindow.h"

#include <QtMath>

Game::Game(QMainWindow *parent, int boardsQty, int gameFieldSize, int gameFieldPosX,int gameFieldPosY)
{
   TicTacToe* newgame;
   matchStatus=NOT_DEFINED;

   this->boardsQty=boardsQty;

   int columnsNum = qSqrt(boardsQty);    // number of cols/rows
   if ((columnsNum*columnsNum)!=boardsQty) columnsNum++;

   int boardSize = gameFieldSize / columnsNum;

   for (int i=0; i<boardsQty; i++)
   {
       newgame = new TicTacToe (parent,boardSize);
       gameList.push_back(newgame);


       gameList[i]->setGeometry(gameFieldPosX+ORIGIN_X+(i%columnsNum)*boardSize,
                                gameFieldPosY+ORIGIN_Y+(i/columnsNum)*boardSize,0,0);
       gameList[i]->show();
       if ((i%2==1)&&(MainWindow::gameType!=CRAZY_GAME)) gameList[i]->cellInit((i/2)%8,1);
    }

   if ((MainWindow::gameType==POW2_GAME)||(MainWindow::gameType==POW3_GAME))
   {
       pow2Game = new TicTacToe (parent); // create virtual game
   }

   lblcellCompleted = new QLabel(parent); // create label to draw x or 0 ans set it to size of the game
   lblcellCompleted->setGeometry(gameFieldPosX+ORIGIN_X,gameFieldPosY+ORIGIN_Y,gameFieldSize,gameFieldSize);

   startTimer(200);
}
//-----------------------------------------------------------------------------------------------------------------------
Game::~Game()
{
    for(int i=0; i<gameList.size();i++)
    {
        gameList[i]->hide();
        delete gameList[i];
    }
    gameList.clear();

    delete lblcellCompleted;

    if ((MainWindow::gameType==POW2_GAME)||(MainWindow::gameType==POW3_GAME)) delete pow2Game;
}
//-----------------------------------------------------------------------------------------------------------------------
void Game::timerEvent(QTimerEvent *e)

{
    Q_UNUSED(e);

    if(matchStatus==CHECKED) return;

    if ((MainWindow::gameType==FUN_GAME)||(MainWindow::gameType==CHALENGE_GAME)||(MainWindow::gameType==CRAZY_GAME))
    {
        MainWindow::boardsLeft=MainWindow::boardsQty-MainWindow::boardsWin-MainWindow::boardsLost-MainWindow::boardsDraw;
        // if all boards completed than calc the score and show result
        if(MainWindow::boardsLeft==0)
        {
           matchStatus=GAME_FINISHED;          
        }
    }

    if ((MainWindow::gameType==POW2_GAME)||(MainWindow::gameType==POW3_GAME))
    {
        if(pow2Game->gameStatus==WIN_COMP)
        {
            matchStatus=WIN_COMP;
            checkGameEnd();
            return;
        }
        if((pow2Game->gameStatus==WIN_HUMAN)||(pow2Game->gameStatus==GAME_DRAW))
        {
            matchStatus=WIN_HUMAN;
            checkGameEnd();
            return;
        }
        for (int i=0; i<9; i++)
        {
          if ((gameList[i]->gameStatus==WIN_HUMAN)||(gameList[i]->gameStatus==GAME_DRAW))
          {
              if (pow2Game->cellInit(i,-1)==NOT_DEFINED)
              {
                  int tmpcell=pow2Game->compTurn();
                  MainWindow::boardsLost++; //!
                  pow2Game->cellInit(tmpcell,1);
                  gameList[tmpcell]->gameStatus=WIN_COMP;
                  gameList[tmpcell]->checkGameEnd();
              }
              gameList[i]->gameStatus=CHECKED;
              return;
          }
          if (gameList[i]->gameStatus==WIN_COMP)
          {
              pow2Game->cellInit(i,1);
              gameList[i]->gameStatus=CHECKED;
              return;

          }
        }
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void Game::hideBoard()
{
    for (int i=0; i<boardsQty; i++)
    {
     gameList[i]->hide();
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void Game::showBoard()
{
    for (int i=0; i<boardsQty; i++)
    {
     gameList[i]->show();
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void Game::checkGameEnd()
{
    if((pow2Game->gameStatus==WIN_COMP)||(matchStatus==WIN_COMP))
    {
        lblcellCompleted->setScaledContents(true);
        lblcellCompleted->setPixmap(QPixmap("./srs/O2.png"));
        lblcellCompleted->show();
    }
    if((pow2Game->gameStatus==WIN_HUMAN)||(pow2Game->gameStatus==GAME_DRAW)||(matchStatus==WIN_HUMAN))
    {
        lblcellCompleted->setPixmap(QPixmap("./srs/X2.png"));
        lblcellCompleted->setScaledContents(true);
        lblcellCompleted->show();
    }
}
