/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *btnLoadImage;
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *lbBoardsLeft;
    QLabel *label;
    QLabel *label_3;
    QLabel *lbBoardsWin;
    QLabel *label_4;
    QLabel *lbBoardsDraw;
    QLabel *label_5;
    QLabel *lbBoardsLost;
    QGroupBox *groupBox_2;
    QLabel *lbTimer;
    QLabel *label_6;
    QGroupBox *groupBox_3;
    QSpinBox *sbGamesQty;
    QPushButton *btnStartFun;
    QLabel *label_2;
    QPushButton *btnPause;
    QGroupBox *groupBox_4;
    QPushButton *btnStartChalenge;
    QPushButton *btnBreak;
    QTableWidget *tableResult;
    QPushButton *btnResults;
    QPushButton *btnCloseResults;
    QLabel *lblImage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(843, 739);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        btnLoadImage = new QAction(MainWindow);
        btnLoadImage->setObjectName("btnLoadImage");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 0, 141, 121));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        lbBoardsLeft = new QLabel(groupBox);
        lbBoardsLeft->setObjectName("lbBoardsLeft");
        lbBoardsLeft->setGeometry(QRect(90, 30, 41, 20));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        lbBoardsLeft->setFont(font1);
        lbBoardsLeft->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 81, 20));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 50, 81, 20));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        lbBoardsWin = new QLabel(groupBox);
        lbBoardsWin->setObjectName("lbBoardsWin");
        lbBoardsWin->setGeometry(QRect(90, 50, 41, 20));
        lbBoardsWin->setFont(font1);
        lbBoardsWin->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 70, 91, 20));
        label_4->setAlignment(Qt::AlignCenter);
        lbBoardsDraw = new QLabel(groupBox);
        lbBoardsDraw->setObjectName("lbBoardsDraw");
        lbBoardsDraw->setGeometry(QRect(90, 70, 41, 20));
        lbBoardsDraw->setFont(font1);
        lbBoardsDraw->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 90, 91, 20));
        label_5->setAlignment(Qt::AlignCenter);
        lbBoardsLost = new QLabel(groupBox);
        lbBoardsLost->setObjectName("lbBoardsLost");
        lbBoardsLost->setGeometry(QRect(90, 90, 41, 20));
        lbBoardsLost->setFont(font1);
        lbBoardsLost->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 120, 141, 71));
        lbTimer = new QLabel(groupBox_2);
        lbTimer->setObjectName("lbTimer");
        lbTimer->setGeometry(QRect(8, 27, 81, 35));
        QFont font3;
        font3.setPointSize(19);
        lbTimer->setFont(font3);
        lbTimer->setFrameShape(QFrame::Box);
        lbTimer->setFrameShadow(QFrame::Raised);
        lbTimer->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(100, 33, 31, 21));
        QFont font4;
        font4.setPointSize(11);
        label_6->setFont(font4);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 230, 141, 121));
        sbGamesQty = new QSpinBox(groupBox_3);
        sbGamesQty->setObjectName("sbGamesQty");
        sbGamesQty->setGeometry(QRect(80, 30, 51, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        sbGamesQty->setFont(font5);
        sbGamesQty->setCursor(QCursor(Qt::ArrowCursor));
        sbGamesQty->setAlignment(Qt::AlignCenter);
        sbGamesQty->setMinimum(2);
        sbGamesQty->setMaximum(121);
        btnStartFun = new QPushButton(groupBox_3);
        btnStartFun->setObjectName("btnStartFun");
        btnStartFun->setGeometry(QRect(10, 70, 121, 41));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 30, 71, 31));
        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName("btnPause");
        btnPause->setGeometry(QRect(10, 200, 91, 31));
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 350, 141, 80));
        btnStartChalenge = new QPushButton(groupBox_4);
        btnStartChalenge->setObjectName("btnStartChalenge");
        btnStartChalenge->setGeometry(QRect(10, 30, 121, 41));
        btnBreak = new QPushButton(centralwidget);
        btnBreak->setObjectName("btnBreak");
        btnBreak->setGeometry(QRect(110, 200, 41, 31));
        tableResult = new QTableWidget(centralwidget);
        tableResult->setObjectName("tableResult");
        tableResult->setGeometry(QRect(10, 430, 141, 241));
        tableResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResult->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableResult->setAutoScroll(false);
        tableResult->setSelectionMode(QAbstractItemView::NoSelection);
        tableResult->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableResult->setTextElideMode(Qt::ElideNone);
        tableResult->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableResult->setShowGrid(true);
        tableResult->setSortingEnabled(true);
        tableResult->horizontalHeader()->setVisible(false);
        tableResult->horizontalHeader()->setCascadingSectionResizes(true);
        tableResult->horizontalHeader()->setHighlightSections(true);
        tableResult->verticalHeader()->setVisible(false);
        tableResult->verticalHeader()->setCascadingSectionResizes(true);
        tableResult->verticalHeader()->setDefaultSectionSize(20);
        tableResult->verticalHeader()->setHighlightSections(true);
        btnResults = new QPushButton(centralwidget);
        btnResults->setObjectName("btnResults");
        btnResults->setGeometry(QRect(20, 680, 121, 31));
        btnCloseResults = new QPushButton(centralwidget);
        btnCloseResults->setObjectName("btnCloseResults");
        btnCloseResults->setGeometry(QRect(400, 640, 181, 24));
        lblImage = new QLabel(centralwidget);
        lblImage->setObjectName("lblImage");
        lblImage->setGeometry(QRect(150, 0, 681, 711));
        lblImage->setFrameShape(QFrame::NoFrame);
        lblImage->setPixmap(QPixmap(QString::fromUtf8("release/tttn1.png")));
        lblImage->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        lblImage->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        btnPause->raise();
        groupBox_4->raise();
        btnBreak->raise();
        tableResult->raise();
        btnResults->raise();
        btnCloseResults->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 843, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setEnabled(false);
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnLoadImage->setText(QCoreApplication::translate("MainWindow", "Load Img", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Progress", nullptr));
        lbBoardsLeft->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Boards Left", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Win", nullptr));
        lbBoardsWin->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Draw", nullptr));
        lbBoardsDraw->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Lost", nullptr));
        lbBoardsLost->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        lbTimer->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "sec.", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Fun Mode :)", nullptr));
        btnStartFun->setText(QCoreApplication::translate("MainWindow", "Start Fun :)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Boards Qty:", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Chalenge on 16 boards ", nullptr));
        btnStartChalenge->setText(QCoreApplication::translate("MainWindow", "Start chalenge", nullptr));
        btnBreak->setText(QCoreApplication::translate("MainWindow", "Break", nullptr));
        btnResults->setText(QCoreApplication::translate("MainWindow", "Detailed results ...", nullptr));
        btnCloseResults->setText(QCoreApplication::translate("MainWindow", "Close results", nullptr));
        lblImage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H