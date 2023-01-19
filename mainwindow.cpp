#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "tictactoe.h"

#include <QGridLayout>
#include <QString>
#include <qmessagebox.h>
#include <QFileDialog>
#include <QLineEdit>
#include <QtMath>

int timerId=1;

QString MainWindow::playerName="";
int MainWindow::boardsWin=0;
int MainWindow::boardsLost=0;
int MainWindow::boardsDraw=0;
int MainWindow::boardsQty;  //number of boards of the current game
int MainWindow::inGameTime; //play time of the current game

int MainWindow::gameType;

//-----------------------------------------------------------------------------------------------------

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->btnStartPow2->setIcon(QIcon("./srs/pow2icon.png"));
    ui->btnStartPow2->setIconSize(QSize(65, 65));

    ui->btnStartPow3->setIcon(QIcon("./srs/pow3icon.png"));
    ui->btnStartPow3->setIconSize(QSize(65, 65));

    ui->btnStartChalenge->setIcon(QIcon("./srs/challenge.jpg"));
    ui->btnStartChalenge->setIconSize(QSize(65, 65));



   // connect (ui->btnBreak, &QPushButton::clicked, this, &MainWindow::breakGame);
    connect (ui->btnPause, &QPushButton::clicked, this, &MainWindow::pauseGame);
    connect (ui->btnResults, &QPushButton::clicked, this, &MainWindow::switchToFullResults);
    ui->btnResults->hide(); // tmp!

    activeElementsSwitcher(IDLE_MODE);


    //ui->lbTimer->hide();
    //ui->btnPause->setDisabled(true);

    QPixmap pixmap("./srs/blackboard.png");
    ui->lblImage->setPixmap(pixmap);

    // loading the records

    if (openRecordsDB())
    {
      loadResultsFromDB();
      saveRecordsToFile();
    }
    else
    {
        qDebug() << db.lastError().text();
        loadResultsFromFile();
        QMessageBox::information(this, "Load records data", "Can't open results from the server, local data from file is loaded");
    }



   // startNewGame(POW2_GAME);

    switchToBriefResults();

    //switchToFullResults();
}
//-----------------------------------------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//-----------------------------------------------------------------------------------------------------

void MainWindow::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);

    QTime qtime = QTime::currentTime();

    int ms = qtime.msecsSinceStartOfDay();
    inGameTime=ms-startTime;
    ui->lbTimer->setText(QString::number(inGameTime/1000));
//---------------------------------------------------------
    if ((gameType==FUN_GAME)||(gameType==CHALENGE_GAME))
    {
    boardsLeft=boardsQty-boardsWin-boardsLost-boardsDraw;

    ui->lbBoardsLeft->setText(QString::number(boardsLeft));
    ui->lbBoardsWin->setText(QString::number(boardsWin));
    ui->lbBoardsDraw->setText(QString::number(boardsDraw));
    ui->lbBoardsLost->setText(QString::number(boardsLost));

    // if all boards completed than calc the score and show result
    if(boardsLeft==0)
    {
        gameScore=(boardsWin*2000+boardsDraw*1000-boardsLost*1000)/(inGameTime/1000);

        QString msg={", \nyour score is : "};

        QMessageBox::information(this, "The game is over", playerName+msg+QString::number(gameScore));

        if((gameScore>0)&&(boardsQty>=16)) // saving results if score is positive and boards qty is enought
        {
            addRecord(gameScore);
        }

        breakGame();  // delete finished game
    }

    }
//-----------------------------------------------------
    if (gameType==POW2_GAME)
    {
        if(pow2Game->gameStatus==WIN_COMP)
        {
        QMessageBox::information(this, "Game over", "You lost the game");
        breakGame();
        return;
        }
        if((pow2Game->gameStatus==WIN_HUMAN)||(pow2Game->gameStatus==GAME_DRAW))
        {
            //rscore=(boardsWin*2000+boardsDraw*1000-boardsLost*1000)/(inGameTime/1000);

            QString msg={", \nyou won this game in sec: "};

            QMessageBox::information(this, "Game over", playerName+msg+QString::number(inGameTime/1000));
            breakGame();
            return;
        }


        for (int i=0; i<boardsQty; i++)
        {
          if ((gameList[i]->gameStatus==WIN_HUMAN)||(gameList[i]->gameStatus==GAME_DRAW))
          {
              //gameList[i]->checkGameEnd();//!!!!!!!!
              gameList[i]->gameStatus=CHECKED;

              if (pow2Game->cellInit(i,-1)==NOT_DEFINED)
              {
                  int tmpcell=pow2Game->compTurn();
                  pow2Game->cellInit(tmpcell,1);
                  gameList[tmpcell]->gameStatus=WIN_COMP;
                  gameList[tmpcell]->checkGameEnd();
              }
              return;
          }

          if (gameList[i]->gameStatus==WIN_COMP)
          {
              gameList[i]->gameStatus=CHECKED;
              pow2Game->cellInit(i,1);

              return;

          }
        }
    }

}
//-----------------------------------------------------------------------------------------------------
void MainWindow::pauseGame()
{
    QTime qtime;

    qtime = QTime::currentTime();
    int beginPause = qtime.msecsSinceStartOfDay();

    killTimer(timerId);
    timerId = 0;

    for(int i=0; i<gameList.size();i++)
    {
        gameList[i]->hide();
    }

    QMessageBox mb;
    mb.setText("Game paused, timer stopped..\nAnd all boards are hided :)\n\nPress Enter to continue...");

    QAbstractButton *breakGameButton = mb.addButton("Break game",QMessageBox::ResetRole);
    //QAbstractButton *continueGameButton = mb.addButton("Continue game",QMessageBox::AcceptRole);

    mb.exec();


    // continue...

    if (mb.clickedButton()==breakGameButton)
    {
       breakGame();
    }
    else
    {

    for(int i=0; i<gameList.size();i++)
        {
            gameList[i]->show();
        }

    qtime = QTime::currentTime();
    int endPause = qtime.msecsSinceStartOfDay();

    startTime=startTime+(endPause-beginPause);

    timerId=startTimer(1000);
    }
}

//-----------------------------------------------------------------------------------------------------
void MainWindow::breakGame()
{

    killTimer(timerId);
    timerId = 0;

    for(int i=0; i<gameList.size();i++)
    {
        gameList[i]->hide();
        delete gameList[i];
    }
    gameList.clear();
    //delete pow2Game;

    QPixmap pixmap("./srs/blackboard.png");
    ui->lblImage->setPixmap(pixmap);

    activeElementsSwitcher(IDLE_MODE);

    boardsWin=0;
    boardsLost=0;
    boardsDraw=0;
    boardsLeft=0;
    gameScore=0;
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::startNewGame(int gameType)
{

     // enterPlayerNameDialog();

     this->gameType=gameType;

     if (gameType==FUN_GAME) boardsQty=ui->sbGamesQty->value();
     if (gameType==CHALENGE_GAME) boardsQty=16;
     if (gameType==POW2_GAME) boardsQty=9;

     ui->lbBoardsLeft->setText(QString::number(boardsQty));


    TicTacToe* newgame;

    int bdCols = qSqrt(boardsQty);;    // number of cols/rows
    if ((bdCols*bdCols)!=boardsQty) bdCols++;

    int bdWide = (BLACKBOARD_WIDTH)/bdCols;



    for (int i=0; i<boardsQty; i++)
    {
        newgame = new TicTacToe (this,bdCols);
        if (i%2==0) newgame->cellInit(i/2%8,1);
        gameList.push_back(newgame);
    }

    //ui->gridMain->setSpacing(0);
    //ui->gridMain->setContentsMargins(10, 10, 10, 10);

    for (int i=0;i<boardsQty; i++)
    {
    gameList[i]->setGeometry(190+(i%bdCols)*bdWide,50+(i/bdCols)*bdWide,bdWide,bdWide);
    gameList[i]->show();
    }

    if (gameType==POW2_GAME)
    {

        QPixmap pixmap("./srs/board9.jpg");
        ui->lblImage->setPixmap(pixmap);
        ui->lbBoardsLeft->setText(QString::number(1));
        pow2Game = new TicTacToe (this,1);
    }

     QTime startTimeC = QTime::currentTime();

     startTime = startTimeC.msecsSinceStartOfDay();

     ui->lbTimer->setText("0");
     ui->lbTimer->show();

     timerId=startTimer(200);
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::switchToFullResults()
{
    //move table to center area location and enlarge to view all field
    ui->tableResult->setGeometry(250,50,480,580);
    //ui->btnCloseResults->show();
    ui->btnResults->show();
    // make visible both headers and vertical scroll bar
    ui->tableResult->verticalHeader()->show();
    ui->tableResult->horizontalHeader()->show();
    ui->tableResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //
    //ui->btnStartChalenge->setDisabled(true);
    //ui->btnStartFun->setDisabled(true);
    ui->tableResult->show();
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::switchToBriefResults()
{
    //ui->tableResult->setGeometry(10,490,140,190);

    ui->tableResult->verticalHeader()->hide();
    ui->tableResult->horizontalHeader()->hide();

    ui->tableResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    ui->btnStartChalenge->setDisabled(false);
    ui->btnStartFun->setDisabled(false);

    //ui->tableResult->hide();

}
//-----------------------------------------------------------------------------------------------------
void MainWindow::loadResultsFromFile()
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
    inputFile.close(); // file closed

    // sorting of table by score
    // ui->tableResult->setSortingEnabled(true);
    // ui->tableResult->sortByColumn(1,Qt::DescendingOrder);

    ui->tableResult->setSortingEnabled(false);

    ui->tableResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::addRecord(int score)
{

    // get the current date
    QDate cDate=QDate::currentDate();
    QString cDateStr=cDate.toString("yyyy-MM-dd");
    int inGameTimeSec=inGameTime/1000;
    // adding to result table
    ui->tableResult->insertRow(ui->tableResult->rowCount());
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,0,new QTableWidgetItem(playerName));                       //player's name
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,1,new QTableWidgetItem(QString::number(score)));           //score
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,2,new QTableWidgetItem(QString::number(inGameTimeSec)));   // game time
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,3,new QTableWidgetItem(QString::number(boardsQty)));       // total boards
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,4,new QTableWidgetItem(QString::number(boardsWin)));
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,5,new QTableWidgetItem(QString::number(boardsDraw)));
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,6,new QTableWidgetItem(QString::number(boardsLost)));
    ui->tableResult->setItem(ui->tableResult->rowCount()-1,7,new QTableWidgetItem(cDateStr));                         // current date

    // add to DB:

    if(db.open())
    {
       QSqlQuery query(db);
       if (query.prepare("INSERT INTO `TicTacToeChallengeResults` (`Player Name`, `Score`, `Time`, `Boards`, `Won`, `Draw`, `Lost`, `Date`)"
                         "VALUES (:playerName, :score, :inGameTimeSec, :boardsQty, :boardsWin, :boardsDraw, :boardsLost, :cDate)"))
    {
       query.bindValue(":playerName", playerName);
       query.bindValue(":score", score);
       query.bindValue(":inGameTimeSec", inGameTimeSec);
       query.bindValue(":boardsQty", boardsQty);
       query.bindValue(":boardsWin", boardsWin);
       query.bindValue(":boardsDraw", boardsDraw);
       query.bindValue(":boardsLost", boardsLost);
       query.bindValue(":cDate", cDate);

       if(query.exec())
       {

           QMessageBox::information(this, "Saved", "Your result is saved successfully");

       } else qDebug() << "Problem with exec. " << query.lastError().text();

    } else qDebug() << "Problem with prepare. " << query.lastError().text();

    } else
        {
        qDebug() << "DB is not opened. " << db.lastError().text();
        QMessageBox::information(this, "Save records data", "Can't save results on the server, save to local file");
        }
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
bool MainWindow::openRecordsDB()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("91.239.234.10");
    db.setDatabaseName("jetpromc_RecordsDB");
    db.setUserName("jetpromc_admin");
    db.setPassword("Admn_2023");

    return db.open();
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::loadResultsFromDB()
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
    QSqlQuery query(db);

    if (query.exec("SELECT * FROM TicTacToeChallengeResults;"))
    {
            while (query.next())
            {
                QSqlRecord rec = query.record();
                ui->tableResult->insertRow(ui->tableResult->rowCount()); // add new row
                for (int col = 0; col < rec.count(); ++col)
                {
                    ui->tableResult->setItem(ui->tableResult->rowCount()-1,col,
                                             new QTableWidgetItem(rec.value(col).toString()));
                }
            }
      }

    //sorting of table by score
    ui->tableResult->setSortingEnabled(true);
    ui->tableResult->sortByColumn(1,Qt::DescendingOrder);
    ui->tableResult->setSortingEnabled(false);
    ui->tableResult->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::on_btnStartPow2_pressed()
{
    activeElementsSwitcher(GAME_MODE);
    startNewGame(POW2_GAME);
}

void MainWindow::on_btnStartFun_pressed()
{
    activeElementsSwitcher(GAME_MODE);
    startNewGame(FUN_GAME);
}

void MainWindow::on_btnStartChalenge_pressed()
{
    activeElementsSwitcher(GAME_MODE);
    startNewGame(CHALENGE_GAME);
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::enterPlayerNameDialog()
{
    if (playerName=="")
    {
    QDialog *enterNameDlg = new QDialog;
    QLineEdit *nameEdit = new QLineEdit("Unknown player", enterNameDlg);
    QPushButton *pbOK = new QPushButton("OK", enterNameDlg);
    QLabel *label = new QLabel ("Please enter you name: ");
    QGridLayout *grid = new QGridLayout(enterNameDlg);

    grid->addWidget(label, 0, 0);
    grid->addWidget(nameEdit, 1, 0);
    grid->addWidget(pbOK, 1, 1);
    //setLayout(grid);
    connect (pbOK, &QPushButton::clicked, enterNameDlg, &QDialog::close);
    enterNameDlg->exec();
    playerName=nameEdit->text();
    }
}
//-----------------------------------------------------------------------------------------------------
void MainWindow::activeElementsSwitcher(int mode)
{
  if(mode==IDLE_MODE)
  {

    ui->btnPause->setDisabled(true);

    ui->btnStartChalenge->setDisabled(false);
    ui->btnStartFun->setDisabled(false);
    ui->btnStartPow2->setDisabled(false);
    ui->btnStartPow3->setDisabled(false);

    ui->btnResults->setDisabled(false);

    ui->lbTimer->hide();
    ui->lbBoardsLeft->setText(QString::number(0));
    ui->lbBoardsWin->setText(QString::number(0));
    ui->lbBoardsDraw->setText(QString::number(0));
    ui->lbBoardsLost->setText(QString::number(0));
  }

  if(mode==GAME_MODE)
  {

    ui->btnPause->setDisabled(false);

    ui->btnStartChalenge->setDisabled(true);
    ui->btnStartFun->setDisabled(true);
    ui->btnStartPow2->setDisabled(true);
    ui->btnStartPow3->setDisabled(true);
    //ui->groupBox_3->setDisabled(true);
    ui->btnResults->setDisabled(false);

    ui->lbTimer->show();
    ui->lbBoardsLeft->setText(QString::number(0));
    ui->lbBoardsWin->setText(QString::number(0));
    ui->lbBoardsDraw->setText(QString::number(0));
    ui->lbBoardsLost->setText(QString::number(0));
  }

}
