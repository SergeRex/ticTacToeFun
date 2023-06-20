#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include "tictactoe.h"
#include <QPointer>

class Game : public QMainWindow
{

public:
    Game(QMainWindow *parent, int boardsQty, int gameFieldSize, int gameFieldPosX, int gameFieldPosY);
    ~Game();

    TicTacToe *pow2Game;
    QVector <TicTacToe*> gameList;   // dynamic boards list
    QLabel *lblcellCompleted;

    int matchStatus;
    int boardsQty;

    void timerEvent(QTimerEvent *e);
    void hideBoard();
    void showBoard();
    void checkGameEnd();
};

#endif //GAME_H
