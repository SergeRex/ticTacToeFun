#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mWindow;


    //mWindow.resize(250, 150);
    mWindow.setWindowTitle("TicTacToe Fun :)");
    //mWindow.setFixedSize(860,735);
    mWindow.show();
    return a.exec();
}
