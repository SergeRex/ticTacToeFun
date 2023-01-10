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



#include "tictactoe.h"

const int FUN_GAME = 1;
const int CHALENGE_GAME = 2;

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

private:

    //methods:
    Ui::MainWindow *ui;
    QVector <TicTacToe*> gameList;   // dynamic boards list
    void timerEvent(QTimerEvent *e); // check game status - main cycle


    bool openRecordsDB();
    void loadResultsFromDB();        // loading data from DB
    void loadResultsFromFile();      // SPARE - loading data from file to results table widget

    void addRecord(int score);

    void saveRecordsToFile();        // SPARE - savng data to file from results table widget


    // fields:
    QSqlDatabase db;

    int startTime; //time of the start of the current game
    int gameType;  // FUN_GAME or CHALENGE_GAME

    //signals:
    void startNewGame(int gameType);
    void breakGame();                // break button action - deleting all current boards and results
    void pauseGame();                // pause button action

    void switchToBriefResults();     // top players at the left of window table widget
    void switchToFullResults();      // show full version of the results


};
#endif // MAINWINDOW_H
