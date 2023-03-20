#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mWindow;

    mWindow.setWindowTitle("TicTacToe Fun :)");

    mWindow.show();

    return a.exec();
}
