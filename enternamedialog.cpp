#include "enternamedialog.h"
#include "ui_enternamedialog.h"

#include <QMessageBox>

EnterNameDialog::EnterNameDialog(QWidget *parent, MainWindow *mW) :
    QDialog(parent),
    ui(new Ui::EnterNameDialog)
{

    ui->setupUi(this);



    int winsScore = (mW->boardsWin * 2000) / (mW->inGameTime/1000);
    int drawScore = (mW->boardsDraw *1000) / (mW->inGameTime/1000);
    int lostScore = (mW->boardsLost *(-1000)) / (mW->inGameTime/1000);
    int totalScore=(winsScore+drawScore+lostScore);

    ui->nameLine->setText(mW->playerName);

    ui->tbNoRecord->hide();

    if ((totalScore<0)||(mW->boardsQty<16))
    {
        ui->gbNameEnter->hide();//setDisabled(true);
        ui->tbNoRecord->show();
    }
    ui->lbWin->setText(QString::number(mW->boardsWin));
    ui->lbWinScore->setText(QString::number(winsScore));

    ui->lbDraw->setText(QString::number(mW->boardsDraw));
    ui->lbDrawScore->setText(QString::number(drawScore));

    ui->lbLost->setText(QString::number(mW->boardsLost));
    ui->lbLostScore->setText(QString::number(lostScore));

    ui->lbBoards->setText(QString::number(mW->boardsQty));
    ui->lbTotalScore->setText(QString::number(totalScore));

    ui->lbTimeMin->setText(QString::number(mW->inGameTime/1000/60));
    ui->lbTimeSec->setText(QString::number(mW->inGameTime/1000%60));

    connect (ui->pbOK, &QPushButton::clicked, this, &EnterNameDialog::close);

}

EnterNameDialog::~EnterNameDialog()
{
    delete ui;
}


void EnterNameDialog::closeEvent(QCloseEvent *event)
{

    Q_UNUSED(event);

    QString plName=ui->nameLine->text();

    if (plName!="") this->playerName=plName;
    else
    {
      this->playerName="Unknown player";
    }

}
QString EnterNameDialog::getName()
{
  return playerName;
}
