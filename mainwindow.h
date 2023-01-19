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



#include "tictactoe.h"

enum gameTypeEnum
{
    IDLE_MODE,
    GAME_MODE,
    FUN_GAME,
    CHALENGE_GAME,
    POW2_GAME,
    POW3_GAME,     // in game
};

//const int FUN_GAME = 1;
//const int CHALENGE_GAME = 2;
//const int POW2_GAME = 3;
//const int POW3_GAME = 4;

const int BLACKBOARD_WIDTH = 640;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    // static variables:
    static QString playerName;
    static int boardsWin;
    static int boardsLost;
    static int boardsDraw;
    static int boardsQty;  //number of boards of the current game
    static int inGameTime; //play time of the current game
    static int gameType;  // FUN_GAME, CHALENGE_GAME, POW2_GAME

private slots:

    void on_btnStartPow2_pressed();

    void on_btnStartFun_pressed();

    void on_btnStartChalenge_pressed();

private:



    //methods:
    Ui::MainWindow *ui;
    QVector <TicTacToe*> gameList;   // dynamic boards list

    //QLabel* lblcellCompleted[9];


    TicTacToe* pow2Game;
    void timerEvent(QTimerEvent *e); // check game status - main cycle


    bool openRecordsDB();
    void loadResultsFromDB();        // loading data from DB
    void loadResultsFromFile();      // SPARE - loading data from file to results table widget

    void addRecord(int score);

    void saveRecordsToFile();        // SPARE - savng data to file from results table widget


    // fields:
    QSqlDatabase db;
    int boardsLeft=0;
    int gameScore=0;

    int startTime; //time of the start of the current game

    void startNewGame(int gameType);
    void breakGame();                // break button action - deleting all current boards and results
    void pauseGame();                // pause button action

    void switchToBriefResults();     // top players at the left of window table widget
    void switchToFullResults();      // show full version of the results
    void activeElementsSwitcher(int mode);

    void enterPlayerNameDialog();


};
#endif // MAINWINDOW_H
