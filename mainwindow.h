#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTime>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QTableWidget>

#include "game.h"

enum gameTypeEnum
{
    FUN_GAME=0,
    CHALENGE_GAME=1,
    POW2_GAME=2,
    POW3_GAME=3,
    CRAZY_GAME=4,
    IDLE_MODE=5,
    GAME_MODE=6,
    LARGE_GAME_MODE=7,
};


const int ORIGIN_X = 195;
const int ORIGIN_Y = 50;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initSignals();

   // static variables:
   static QString playerName;
   static int boardsWin;
   static int boardsLost;
   static int boardsDraw;
   static int boardsLeft;
   static int boardsQty;  //number of boards of the current game
   static int gameScore;
   static int inGameTime; //play time of the current game
   static int gameType;  // FUN_GAME, CHALENGE_GAME, POW2_GAME

private slots:


   void on_pbRules_clicked();

private:

    Ui::MainWindow *ui;

    QVector <Game*> gamesList;
    TicTacToe *pow3Game;

    void timerEvent(QTimerEvent *e); // check game status - main cycle

    QSqlDatabase dbServer; // server SQL base

    void assignDataBases();
    bool addRecordtoDB(QSqlDatabase &db);

    void loadResultsFromDB(QTableWidget &table, int gameType);
    void sortTableRows(QTableWidget &table, int colNum);
    void addRecord(QTableWidget &table,int gameType);

    void startGame (int gameType);

    int startTime;          //time of the start of the current game
    void startGameTimer();
    void breakGame();       // break button action - deleting all current boards and results
    void pauseGame();       // pause button action

    void activeElementsSwitcher(int mode);
    void enterPlayerNameDialog();
    void loadIcons();
    void showResults();
    void handleGameOver(int matchStatus);
    int enterBoardsNum(int gameType);

};
#endif // MAINWINDOW_H
