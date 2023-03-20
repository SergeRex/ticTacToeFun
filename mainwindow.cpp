#include "mainwindow.h"
#include "qspinbox.h"
#include "ui_mainwindow.h"

#include "tictactoe.h"
#include "game.h"

#include <QGridLayout>
#include <QString>
#include <qmessagebox.h>
#include <QFileDialog>
#include <QLineEdit>
#include <QtMath>

int timerId=1;
int BLACKBOARD_WIDTH;

QString MainWindow::playerName="unknown player";

int MainWindow::boardsWin=0;
int MainWindow::boardsLost=0;
int MainWindow::boardsDraw=0;
int MainWindow::boardsQty=0;  //number of boards of the current game
int MainWindow::boardsLeft=0;  //number of boards of the current game
int MainWindow::gameScore=0;
int MainWindow::inGameTime; //play time of the current game
int MainWindow::gameType;

//----------------------------------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    initSignals();
    loadIcons();
    activeElementsSwitcher(IDLE_MODE);
    assignDataBases();

    if (dbServer.open())
    {
        loadResultsFromDB(*ui->tableResult, CHALENGE_GAME);
        loadResultsFromDB(*ui->tableResultPow2, POW2_GAME);
        loadResultsFromDB(*ui->tableResultPow3, POW3_GAME);
        dbServer.close();
    }
    else QMessageBox::information(this, "Can't load results from server. ", dbServer.lastError().text());
}
//----------------------------------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::initSignals()
{
    connect (ui->btnPause, &QPushButton::clicked, this, &MainWindow::pauseGame);
    connect (ui->btnChangeName, &QPushButton::clicked, this, &MainWindow::enterPlayerNameDialog);

    //game buttons linked to startGame function
    QSignalMapper *signalMapper = new QSignalMapper;

    connect(ui->btnStartFun, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->btnStartChalenge, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->btnStartPow2, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->btnStartPow3, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->btnCrazyMode, SIGNAL(clicked()), signalMapper, SLOT (map()));

    signalMapper->setMapping(ui->btnStartFun, FUN_GAME);
    signalMapper->setMapping(ui->btnStartChalenge, CHALENGE_GAME);
    signalMapper->setMapping(ui->btnStartPow2, POW2_GAME);
    signalMapper->setMapping(ui->btnStartPow3, POW3_GAME);
    signalMapper->setMapping(ui->btnCrazyMode, CRAZY_GAME);

    connect(signalMapper, &QSignalMapper::mappedInt,this, &MainWindow::startGame);
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::handleGameOver(int matchStatus)
{
    QString msg1={"\nYour score is "};
    QString msg2={" points.\nYou completed the game in  "};
    QString msg3={" seconds."};

    if (matchStatus==LOST)
      QMessageBox::information(this, "GAME OVER", playerName+", unfortunately you lost this match :(");
    else
    {
        int timeScoreComponent=inGameTime/5000;

        if (timeScoreComponent==0) timeScoreComponent=1; // avoid div 0

        if((gameType==FUN_GAME)||(gameType==CHALENGE_GAME)||(gameType==CRAZY_GAME))
        {

            gameScore=(boardsWin*2000+boardsDraw*1000-boardsLost*1000)/(timeScoreComponent);
            QMessageBox::information(this, "GAME OVER", playerName+", your completed the TocTacToe match."
                                     +msg1+QString::number(gameScore)+msg2+QString::number(inGameTime/1000)+msg3);

            if ((gameScore>0)&&(boardsQty>15)) addRecord(*ui->tableResult,CHALENGE_GAME);
        }

        if(gameType==POW2_GAME)
        {
            gameScore=(9*1000)/(timeScoreComponent);
            QMessageBox::information(this, "GAME OVER", playerName+", your completed the Ultimate GAME."
                                     +msg1+QString::number(gameScore)+msg2+QString::number(inGameTime/1000)+msg3);
            addRecord(*ui->tableResultPow2,POW2_GAME);
        }
        if(gameType==POW3_GAME)
        {
            gameScore=(81*1000)/(timeScoreComponent);
            QMessageBox::information(this, "GAME OVER", playerName+", your completed the Extreme GAME."
                                     +msg1+QString::number(gameScore)+msg2+QString::number(inGameTime/1000)+msg3);
            addRecord(*ui->tableResultPow3,POW3_GAME);
        }

    }

   breakGame(); // clear all date for the new game
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    QTime qtime = QTime::currentTime();

    int ms = qtime.msecsSinceStartOfDay();
    inGameTime=ms-startTime;
    ui->lbTimer->setText(QString::number(inGameTime/1000));

    showResults();

    if(((gameType==FUN_GAME)||(gameType==CHALENGE_GAME)||(gameType==CRAZY_GAME))&&(gamesList[0]->matchStatus==GAME_FINISHED))
    {
        gamesList[0]->matchStatus=CHECKED;
        handleGameOver(COMPLETED);
    }

    if(gameType==POW2_GAME)
    {
        if (gamesList[0]->matchStatus==WIN_COMP)  handleGameOver(LOST);
        if (gamesList[0]->matchStatus==WIN_HUMAN) handleGameOver(COMPLETED);
    }

     if(gameType==POW3_GAME)
    {

      if(pow3Game->gameStatus==WIN_COMP) handleGameOver(LOST);
      if((pow3Game->gameStatus==WIN_HUMAN)||(pow3Game->gameStatus==GAME_DRAW)) handleGameOver(COMPLETED);


      for (int i=0; i<9; i++)
      {
      if ((gamesList[i]->matchStatus==WIN_HUMAN)||(gamesList[i]->matchStatus==GAME_DRAW))
       {
          boardsDraw+=gamesList[i]->pow2Game->getEmptyCellsQty();

          if (pow3Game->cellInit(i,-1)==NOT_DEFINED)
           {

             int tmpcell=pow3Game->compTurn();
             MainWindow::boardsLost+=9;

             gamesList[tmpcell]->matchStatus=WIN_COMP;
             gamesList[tmpcell]->checkGameEnd();
             pow3Game->cellInit(tmpcell,1);
             gamesList[tmpcell]->matchStatus=CHECKED;
           }
        gamesList[i]->matchStatus=CHECKED;
        return;
      }
      if (gamesList[i]->matchStatus==WIN_COMP)
       {
        boardsDraw+=gamesList[i]->pow2Game->getEmptyCellsQty();
        pow3Game->cellInit(i,1);
        gamesList[i]->matchStatus=CHECKED;
        return;
        }
       }
    }
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::pauseGame()
{
    QTime qtime;

    qtime = QTime::currentTime();
    int beginPause = qtime.msecsSinceStartOfDay();

    killTimer(timerId);
    timerId = 0;

    for(int i=0; i<gamesList.size();i++) gamesList[i]->hideBoard();

    QMessageBox mb;
    mb.setText("Game paused, timer stopped..\nAnd all boards are hided :)\n\nPress Enter to continue...");

    QAbstractButton *breakGameButton = mb.addButton("Break game",QMessageBox::ResetRole);
    QAbstractButton *continueGameButton = mb.addButton("Continue game",QMessageBox::AcceptRole);

    mb.exec();

    // continue...

    if (mb.clickedButton()==breakGameButton)
    {
       breakGame();
    }

    if (mb.clickedButton()==continueGameButton)
    {
        for(int i=0; i<gamesList.size();i++) gamesList[i]->showBoard();

        qtime = QTime::currentTime();
        int endPause = qtime.msecsSinceStartOfDay();
        startTime=startTime+(endPause-beginPause);
        timerId=startTimer(200);
    }
}

//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::breakGame()
{
    killTimer(timerId);
    timerId = 0;

    for(int i=0; i<gamesList.size();i++)
    {
        gamesList[i]->hide();
        delete gamesList[i];
    }
    gamesList.clear();
    if(gameType==POW3_GAME) delete pow3Game;

    boardsWin=0;
    boardsLost=0;
    boardsDraw=0;
    boardsLeft=0;
    boardsQty=0;
    gameScore=0;
    inGameTime=0;

    activeElementsSwitcher(IDLE_MODE);

    ui->lbTimer->setText(QString::number(inGameTime/1000));
}
//----------------------------------------------------------------------------------------------------------------------------
bool MainWindow::addRecordtoDB(QSqlDatabase &db)
{
    QDate cDate=QDate::currentDate();
    //QString cDateStr=cDate.toString("yyyy-MM-dd");
    int inGameTimeSec=inGameTime/1000;

    db.open();

    if (!db.isOpen()) return false;

    QSqlQuery query(db);

    query.prepare("INSERT INTO `TicTacToeChallengeResults` (`Player Name`, `Score`, `Time`, `Boards`, `Won`, `Draw`, `Lost`, `Date`, `Gametype`)"
                  "VALUES (:playerName, :score, :inGameTimeSec, :boardsQty, :boardsWin, :boardsDraw, :boardsLost, :cDate, :Gametype)");

    query.bindValue(":playerName", playerName);
    query.bindValue(":score", gameScore);
    query.bindValue(":inGameTimeSec", inGameTimeSec);
    query.bindValue(":boardsQty", boardsQty);
    query.bindValue(":boardsWin", boardsWin);
    query.bindValue(":boardsDraw",boardsDraw);
    query.bindValue(":boardsLost",boardsLost);
    query.bindValue(":cDate", cDate);
    query.bindValue(":Gametype", gameType);

    query.exec();

    db.close();
    return true;
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::addRecord(QTableWidget &table,int gameType)
{
    enterPlayerNameDialog();

    int inGameTimeSec=inGameTime/1000;

    // adding to result table
    table.insertRow(table.rowCount());
    table.setItem(table.rowCount()-1,0,new QTableWidgetItem(playerName));                       // player's name
    table.setItem(table.rowCount()-1,1,new QTableWidgetItem(QString::number(gameScore)));       // score
    table.setItem(table.rowCount()-1,2,new QTableWidgetItem(QString::number(inGameTimeSec)));   // game time

    if (gameType==CHALENGE_GAME)
    {
    table.setItem(table.rowCount()-1,3,new QTableWidgetItem(QString::number(boardsQty)));
    table.setItem(table.rowCount()-1,4,new QTableWidgetItem(QString::number(boardsWin)));
    table.setItem(table.rowCount()-1,5,new QTableWidgetItem(QString::number(boardsDraw)));
    table.setItem(table.rowCount()-1,6,new QTableWidgetItem(QString::number(boardsLost)));
    }
    sortTableRows(table, 1);

    if (addRecordtoDB(dbServer)) QMessageBox::information(this, "Saving results", "Your result is saved successfully");
                            else QMessageBox::information(this, "Can't save results to server. ", dbServer.lastError().text());
}
//----------------------------------------------------------------------------------------------------------------------------

void MainWindow::assignDataBases()
{
    dbServer = QSqlDatabase::addDatabase("QMYSQL", "server");
    dbServer.setHostName("91.239.234.10");
    dbServer.setDatabaseName("jetpromc_RecordsDB");
    dbServer.setUserName("jetpromc_admin");
    dbServer.setPassword("Admn_2023");
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::loadResultsFromDB(QTableWidget &table, int gameType)
{
    const int columnsWidth[]={99,40,40,40,7,7,7,80,10};
    ui->tableResult->setSortingEnabled(false);

    for (int col=1; col<table.columnCount();col++)      // setting column widthes
        table.setColumnWidth(col, columnsWidth[col]);
    //QSqlQuery query(dbLocal);

    QSqlQuery query(dbServer);

    if (gameType==CHALENGE_GAME) query.exec("SELECT * FROM `TicTacToeChallengeResults` WHERE `Gametype`= 1;");
    if (gameType==POW2_GAME) query.exec("SELECT * FROM `TicTacToeChallengeResults` WHERE `Gametype`= 2;");
    if (gameType==POW3_GAME) query.exec("SELECT * FROM `TicTacToeChallengeResults` WHERE `Gametype`= 3;");

            while (query.next())
            {
                QSqlRecord rec = query.record();
                table.insertRow(table.rowCount()); // add new row

                for (int col = 0; col < table.columnCount(); ++col)
                {
                    table.setItem(table.rowCount()-1,col,new QTableWidgetItem(rec.value(col).toString()));
                }
            }
    sortTableRows(table, 1);
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::enterPlayerNameDialog()
{
    QDialog *enterNameDlg = new QDialog;
    QLineEdit *nameEdit = new QLineEdit(playerName, enterNameDlg);
    QPushButton *pbOK = new QPushButton("OK", enterNameDlg);
    QLabel *label = new QLabel ("Please enter you name: ");
    QGridLayout *grid = new QGridLayout(enterNameDlg);

    grid->addWidget(label, 0, 0);
    grid->addWidget(nameEdit, 1, 0);
    grid->addWidget(pbOK, 1, 1);

    connect (pbOK, &QPushButton::clicked, enterNameDlg, &QDialog::close);
    enterNameDlg->exec();
    playerName=nameEdit->text();

    ui->lbPlayerName->setText(playerName);
}
//----------------------------------------------------------------------------------------------------------------------------
void MainWindow::activeElementsSwitcher(int mode)
{
    if(mode==IDLE_MODE)
    {
        setFixedSize(1020,590);
        ui->allGamesGroupBox->show();
        ui->btnCrazyMode->show();
        ui->btnPause->setDisabled(true);

        ui->lblImage->hide();
        ui->lblGameType->setText("");

     }

    if((mode==GAME_MODE)||(mode==LARGE_GAME_MODE))
    {
        if(mode==GAME_MODE)
        {
            BLACKBOARD_WIDTH = 635;
            ui->lblImage->setGeometry(170,0,670,730);
            setFixedSize(860,740);
            move((1920-1120)/2,0);
        }
         else
        {
            BLACKBOARD_WIDTH = 880;
            ui->lblImage->setGeometry(170,0,920,980);
            setFixedSize(1120,990);
            move((1920-1120)/2,0);
        }
        ui->allGamesGroupBox->hide();
        ui->btnCrazyMode->hide();
        ui->btnPause->setDisabled(false);

        switch (gameType) // indicating the game mode
        {
            case FUN_GAME:      ui->lblGameType->setText("Training"); break;
            case CHALENGE_GAME: ui->lblGameType->setText("Competition"); break;
            case POW2_GAME:     ui->lblGameType->setText("Ultimate"); break;
            case POW3_GAME:     ui->lblGameType->setText("Extereme"); break;
            case CRAZY_GAME:    ui->lblGameType->setText("Crazy Game"); break;
            default: break;
        }
        if ((gameType==FUN_GAME)||(gameType==CHALENGE_GAME)) {QPixmap pixmap("./srs/blackboard.png");ui->lblImage->setPixmap(pixmap);};
        if (gameType==POW2_GAME) {QPixmap pixmap("./srs/board9.jpg");ui->lblImage->setPixmap(pixmap);};
        if (gameType==POW3_GAME) {QPixmap pixmap("./srs/board81r.jpg");ui->lblImage->setPixmap(pixmap);};
        if (gameType==CRAZY_GAME) {QPixmap pixmap("./srs/crazy_brd.jpg");ui->lblImage->setPixmap(pixmap);};
        ui->lblImage->show();
     }
    showResults(); // setting all inducationg results to defult

}
//----------------------------------------------------------------------------------------------------------------------------

void MainWindow::startGame (int gameType)
{
    Game* newgame;

    this->gameType=gameType;
    boardsQty=enterBoardsNum(gameType);
    if (boardsQty>16) activeElementsSwitcher(LARGE_GAME_MODE);
     else activeElementsSwitcher(GAME_MODE);

    startGameTimer();

    if ((gameType==FUN_GAME)||(gameType==CHALENGE_GAME)||(gameType==POW2_GAME))
    {
        newgame = new Game(this,boardsQty, BLACKBOARD_WIDTH,0,0);
        gamesList.push_back(newgame);
    }

    if (gameType==POW3_GAME)
    {
       int boardSize=BLACKBOARD_WIDTH/3;
       for (int i=0; i<9; i++)
        {
          newgame = new Game (this,9, (boardSize-12),boardSize*(i%3)+7,boardSize*(i/3)+7);
          gamesList.push_back(newgame);
        }
        pow3Game = new TicTacToe (this);
    }

    if (gameType==CRAZY_GAME)
    {
        int gData[12][4] = {{1,2,4,3},{1,2,6,4},{1,2,5,6},{1,2,3,5},
                          {1,3,4,0},{1,3,0,4},{1,3,8,4},{1,3,4,8},
                          {1,4,0,0},{4,4,7,0},{9,4,0,7},{16,4,7,7}};
        int unit = BLACKBOARD_WIDTH/11;

        boardsQty=0;

        for (int i=0; i<12;i++)
        {
            boardsQty+=gData[i][0];
            newgame = new Game (this,gData[i][0], gData[i][1]*unit,gData[i][2]*unit,gData[i][3]*unit);
            gamesList.push_back(newgame);
            showResults();
        }
    }
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::showResults()
{
    boardsLeft=boardsQty-boardsWin-boardsDraw-boardsLost;

    ui->lbBoardsQty->setText(QString::number(boardsQty));
    ui->lbBoardsLeft->setText(QString::number(boardsLeft));
    ui->lbBoardsWin->setText(QString::number(boardsWin));
    ui->lbBoardsDraw->setText(QString::number(boardsDraw));
    ui->lbBoardsLost->setText(QString::number(boardsLost));
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::startGameTimer()
{
    ui->lbBoardsLeft->setText(QString::number(boardsQty));
    QTime startTimeC = QTime::currentTime();
    startTime = startTimeC.msecsSinceStartOfDay();
    ui->lbTimer->setText("0");
    ui->lbTimer->show();
    timerId=startTimer(200);
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::sortTableRows(QTableWidget &table, int colNum)
{
    QString str;

    for (int row = 0; row < table.rowCount(); ++row)
    {
      str=table.item(row,colNum)->text();
      if (str.length()==1) str="0000"+str;
      if (str.length()==2) str="000"+str;
      if (str.length()==3) str="00"+str;
      if (str.length()==4) str="0"+str;
      table.setItem(row,colNum, new QTableWidgetItem(str));
    }

    //sorting of the table
    table.setSortingEnabled(true);
    table.sortByColumn(colNum,Qt::DescendingOrder);
    table.setSortingEnabled(false);

    for (int row = 0; row < table.rowCount(); ++row)
    {
        QString str=table.item(row,colNum)->text();
        if (str[0]=="0") str=str.mid(1);
        if (str[0]=="0") str=str.mid(1);
        if (str[0]=="0") str=str.mid(1);

        table.setItem(row,colNum, new QTableWidgetItem(str));
    }

    // disable edit
    table.setEditTriggers(QAbstractItemView::NoEditTriggers);
}

//-----------------------------------------------------------------------------------------------------
void MainWindow::loadIcons()
{

    QPixmap pixmap("./srs/3t.png");ui->lb2t->setPixmap(pixmap);

    ui->btnStartFun->setIcon(QIcon("./srs/training.png"));
    ui->btnStartFun->setIconSize(QSize(65, 65));

    ui->btnStartChalenge->setIcon(QIcon("./srs/chalicon.png"));
    ui->btnStartChalenge->setIconSize(QSize(65, 65));

    ui->btnStartPow2->setIcon(QIcon("./srs/pow2icon.png"));
    ui->btnStartPow2->setIconSize(QSize(65, 65));

    ui->btnStartPow3->setIcon(QIcon("./srs/pow3icon.png"));
    ui->btnStartPow3->setIconSize(QSize(65, 65));

    ui->btnCrazyMode->setIcon(QIcon("./srs/crazymode.png"));
    ui->btnCrazyMode->setIconSize(QSize(65, 65));
    //QGroupBox
}
//-----------------------------------------------------------------------------------------------------
int MainWindow::enterBoardsNum(int gameType)
{

    if (gameType==POW2_GAME) return 9;
    if (gameType==POW3_GAME) return 81;
    if (gameType==CRAZY_GAME) return 17;

    QLabel *label;

    QDialog *enterBoardsNumDialog = new QDialog;
    QSpinBox *spBox = new QSpinBox;
    QPushButton *pbOK = new QPushButton("OK", enterBoardsNumDialog);
    QGridLayout *grid = new QGridLayout(enterBoardsNumDialog);

    if (gameType==FUN_GAME)
    {
        label = new QLabel ("Enter number of boards for TRAINING match(1-121):");
        spBox->setRange(1,121);
    }
    else
    {
        label = new QLabel ("Enter number of boards for CHALLENGE (min 16):");
        spBox->setRange(16,121);
    }

    grid->addWidget(label, 0, 0);
    grid->addWidget(spBox, 0, 1);
    grid->addWidget(pbOK, 1, 1);

    connect (pbOK, &QPushButton::clicked, enterBoardsNumDialog, &QDialog::close);
    enterBoardsNumDialog->exec();

    return spBox->value();
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::on_pbRules_clicked()
{
    QFile inputFile("Game rules.txt");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in (&inputFile);
    QString msg=in.readAll();
    in.flush();
    inputFile.close();
    QMessageBox::information(this, "Game rules", msg);
}
//-----------------------------------------------------------------------------------------------------
