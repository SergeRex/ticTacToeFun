#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tictactoe.h"
#include "enternamedialog.h"

#include <QGridLayout>
#include <QString>
#include <qmessagebox.h>
#include <QFileDialog>
#include <QLineEdit>

int timerId;

//-----------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect (ui->btnBreak, &QPushButton::clicked, this, &MainWindow::breakGame);
    connect (ui->btnPause, &QPushButton::clicked, this, &MainWindow::pauseGame);
    connect (ui->btnResults, &QPushButton::clicked, this, &MainWindow::switchToFullResults);
    connect (ui->btnCloseResults, &QPushButton::clicked, this, &MainWindow::switchToBriefResults);

    QSignalMapper *signalMapper = new QSignalMapper;

    connect(ui->btnStartChalenge, SIGNAL(clicked()), signalMapper, SLOT (map()));
    connect(ui->btnStartFun, SIGNAL(clicked()), signalMapper, SLOT (map()));

    signalMapper->setMapping(ui->btnStartChalenge, CHALENGE_GAME);
    signalMapper->setMapping(ui->btnStartFun, FUN_GAME);

    connect(signalMapper, &QSignalMapper::mappedInt,this, &MainWindow::startNewGame);

    ui->lbTimer->hide();
    ui->btnBreak->setDisabled(true);
    ui->btnPause->setDisabled(true);
    ui->btnCloseResults->hide();

    loadResults();
    switchToBriefResults();

    QPixmap pixmap("tttn1.png");
    ui->lblImage->setPixmap(pixmap);

    //ui->lblImage->show();

    ui->statusbar->showMessage(tr("                                                           "
                                  "                                                           "
                                  "                                                           "
                                  "                                Sergio Rex (c) 2022  v.1.0 "));
}

//-----------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::pauseGame()
{
    QTime qtime;

    qtime = QTime::currentTime();
    int beginPause = qtime.msecsSinceStartOfDay();

    killTimer(timerId);

    for(TicTacToe *game : gameList)
    {
      game->hide();
    }

    QMessageBox mb;
    mb.setText("Game paused, timer stopped..\nAnd all boards are hided :)\n\nPress OK to continue...");
    mb.exec();

    // continue...

    for(TicTacToe *game : gameList)
    {
      game->show();
    }

    qtime = QTime::currentTime();
    int endPause = qtime.msecsSinceStartOfDay();

    startTime=startTime+(endPause-beginPause);

    timerId=startTimer(1000);
}

//-----------------------------------------------------------------------------------------------------
void MainWindow::breakGame()
{

    killTimer(timerId);

    for(TicTacToe *game : gameList)
    {
        game->hide();
        delete game;
    }
    gameList.clear();

    ui->btnBreak->setDisabled(true);
    ui->btnPause->setDisabled(true);
    ui->btnStartChalenge->setDisabled(false);
    ui->btnStartFun->setDisabled(false);
    ui->btnResults->setDisabled(false);

     ui->lbTimer->hide();

     ui->lbBoardsLeft->setText(QString::number(0));
     ui->lbBoardsWin->setText(QString::number(0));
     ui->lbBoardsDraw->setText(QString::number(0));
     ui->lbBoardsLost->setText(QString::number(0));

}
//-----------------------------------------------------------------------------------------------------
void MainWindow::startNewGame(int gameType)
{

    TicTacToe* newgame;
    int bdWide=146;  // size of board for 4x4 boards field
    int bdOffs=158;  // offsets between boards for 4x4 boards field
    int bdFontSz=32; // size of field signs for 4x4 boards field
    int bdCols=1;    // number of cols/rows

    this->gameType=gameType;

    if (gameType==FUN_GAME)
        boardsQty=ui->sbGamesQty->value();
    else boardsQty=16;

    if ((boardsQty>1)&&(boardsQty<=4)) bdCols=2;
    if ((boardsQty>4)&&(boardsQty<=9)) bdCols=3;
    if ((boardsQty>9)&&(boardsQty<=16)) bdCols=4;
    if ((boardsQty>16)&&(boardsQty<=25)) bdCols=5;
    if ((boardsQty>25)&&(boardsQty<=36)) bdCols=6;
    if ((boardsQty>36)&&(boardsQty<=49)) bdCols=7;
    if ((boardsQty>49)&&(boardsQty<=64)) bdCols=8;
    if ((boardsQty>64)&&(boardsQty<=81)) bdCols=9;
    if ((boardsQty>81)&&(boardsQty<=100)) bdCols=10;
    if ((boardsQty>100)&&(boardsQty<=121)) bdCols=11;

    bdWide=(bdWide*4)/bdCols;
    bdOffs=(bdOffs*4)/bdCols;
    bdFontSz=(bdFontSz*4)/(bdCols);
    if (bdCols==7) { bdWide+=5;bdOffs-=2; }
    if (bdCols==8) { bdWide+=5;bdOffs-=2; }
    if (bdCols==9) { bdWide+=5;bdOffs-=2; }
    if (bdCols==10) { bdWide+=5;bdOffs-=2; }
    if (bdCols==11) { bdWide+=5;bdOffs-=2; }

    ui->lbBoardsLeft->setText(QString::number(boardsQty));

    ui->btnBreak->setDisabled(false);
    ui->btnPause->setDisabled(false);
    ui->btnStartChalenge->setDisabled(true);
    ui->btnStartFun->setDisabled(true);
    ui->btnResults->setDisabled(true);


    for (int i=0; i<boardsQty; i++)
    {
        if (i%2==0) newgame = new TicTacToe (this,bdWide/3,bdFontSz,i/2%8);
        else newgame = new TicTacToe (this,bdWide/3,bdFontSz,-1);
        gameList.push_back(newgame);
    }


    for (int i=0; i<boardsQty; i++)
    {
        gameList[i]->setGeometry(bdOffs*(i%bdCols)+170+10, bdOffs*(i/bdCols)+40, bdWide, bdWide);
        gameList[i]->show();
    }

     QTime startTimeC = QTime::currentTime();

     startTime = startTimeC.msecsSinceStartOfDay();

     ui->lbTimer->setText("0");
     ui->lbTimer->show();

     timerId=startTimer(1000);

}
//-----------------------------------------------------------------------------------------------------
void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    boardsWin=0;
    boardsLost=0;
    boardsDraw=0;

    int boardsLeft=-1;
    int score=0;

    QTime qtime = QTime::currentTime();

    int ms = qtime.msecsSinceStartOfDay();
    inGameTime=ms-startTime;
    ui->lbTimer->setText(QString::number(inGameTime/1000));

    for(int i=0;i<boardsQty;i++)
    {
        int status=gameList[i]->getGameStatus();

        if (status==WIN_HUMAN) boardsWin++;
        if (status==WIN_COMP) boardsLost++;
        if (status==GAME_DRAW) boardsDraw++;
    }

    boardsLeft=boardsQty-boardsWin-boardsLost-boardsDraw;

    ui->lbBoardsLeft->setText(QString::number(boardsLeft));
    ui->lbBoardsWin->setText(QString::number(boardsWin));
    ui->lbBoardsDraw->setText(QString::number(boardsDraw));
    ui->lbBoardsLost->setText(QString::number(boardsLost));

    // if all boards completed than calc the score and show result
    if(boardsLeft==0)
    {
        EnterNameDialog showResultDialog(nullptr, this);// = new EntNameDialog;
        showResultDialog.setFixedSize(290,450);
        showResultDialog.exec();
        playerName=showResultDialog.getName();

        score=(boardsWin*2000+boardsDraw*1000-boardsLost*1000)/(inGameTime/1000);

        if((score>0)&&(boardsQty>=16)) addRecord(score);
        breakGame();  // delete finished game
    }
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::switchToFullResults()
{
    //move table to center area location and enlarge to view all field
    ui->tableResult->setGeometry(250,50,480,580);
    ui->btnCloseResults->show();
    ui->btnResults->hide();
    // make visible both headers and vertical scroll bar
    ui->tableResult->verticalHeader()->show();
    ui->tableResult->horizontalHeader()->show();
    ui->tableResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //
    ui->btnStartChalenge->setDisabled(true);
    ui->btnStartFun->setDisabled(true);
}

//-----------------------------------------------------------------------------------------------------
void MainWindow::switchToBriefResults()
{
    ui->tableResult->setGeometry(10,430,140,240);
    ui->btnCloseResults->hide();
    ui->btnResults->show();

    ui->tableResult->verticalHeader()->hide();
    ui->tableResult->horizontalHeader()->hide();

    ui->tableResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    ui->btnStartChalenge->setDisabled(false);
    ui->btnStartFun->setDisabled(false);

}
//-----------------------------------------------------------------------------------------------------
void MainWindow::loadResults()
{
    const int numColumns=8;
    const int columnsWidth[]={99,40,40,50,40,40,40,80};

    ui->tableResult->clear();
    ui->tableResult->setColumnCount(numColumns);
    // setting column names
    ui->tableResult->setHorizontalHeaderLabels(QStringList()
    << tr("Player's Name") << tr("Score") << tr("Time")<< tr("Boards")<< tr("Win")
    << tr("Draw")<< tr("Lost")<< tr("Date"));
    // setting column widthes
    for (int col=0; col<numColumns;col++)
        ui->tableResult->setColumnWidth(col, columnsWidth[col]);

    // read from file
    QFile inputFile("gameRecords.csv");
    inputFile.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream in (&inputFile);

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList rowArr = line.split(";");

        ui->tableResult->insertRow(ui->tableResult->rowCount()); // add new row
        // add all columns to the row
        for (int col=0; col<numColumns; col++)
            ui->tableResult->setItem(ui->tableResult->rowCount()-1,col,
                                     new QTableWidgetItem(rowArr.at(col)));
    }
    in.flush();
    inputFile.close();
    // file closed

    // sorting of table by score
    // ui->tableResult->setSortingEnabled(true);
    // ui->tableResult->sortByColumn(1,Qt::DescendingOrder);

    ui->tableResult->setSortingEnabled(false);

    ui->tableResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::addRecord(int score)
{
    // get current date
    QDate cDate=QDate::currentDate();
    QString cDateStr=cDate.toString("dd/MM/yyyy");
    // adding to result table
    ui->tableResult->insertRow(ui->tableResult->rowCount());
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,0,new QTableWidgetItem(playerName));                      //player's name
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,1,new QTableWidgetItem(QString::number(score)));           //score
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,2,new QTableWidgetItem(QString::number(inGameTime/1000))); // game time
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,3,new QTableWidgetItem(QString::number(boardsQty)));       // total boards
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,4,new QTableWidgetItem(QString::number(boardsWin)));
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,5,new QTableWidgetItem(QString::number(boardsDraw)));
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,6,new QTableWidgetItem(QString::number(boardsLost)));
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,7,new QTableWidgetItem(cDateStr));                         // current date
    // sorting by score
    ui->tableResult->setSortingEnabled(true);
    ui->tableResult->sortByColumn(1,Qt::DescendingOrder);
    ui->tableResult->setSortingEnabled(false);
    // save all records to file
    saveRecordsToFile();
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::saveRecordsToFile()
{
    QFile outputFile("gameRecords.csv");
    outputFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out (&outputFile);

    for (int row=0; row < ui->tableResult->rowCount(); row++)
     for (int column=0; column<ui->tableResult->columnCount(); column++)
        {
            out<<ui->tableResult->item(row,column)->text();
            if (column<ui->tableResult->columnCount()-1) out<<";";
             else out<<Qt::endl;
        }

    out.flush();
    outputFile.close();
}
//-----------------------------------------------------------------------------------------------------
