/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
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
    QTableWidget *tableResult;
    QPushButton *btnResults;
    QLabel *lblImage;
    QPushButton *btnStartPow2;
    QPushButton *btnStartPow3;
    QPushButton *btnStartChalenge;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(850, 763);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        btnLoadImage = new QAction(MainWindow);
        btnLoadImage->setObjectName(QString::fromUtf8("btnLoadImage"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 141, 121));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        lbBoardsLeft = new QLabel(groupBox);
        lbBoardsLeft->setObjectName(QString::fromUtf8("lbBoardsLeft"));
        lbBoardsLeft->setGeometry(QRect(90, 30, 41, 20));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        lbBoardsLeft->setFont(font1);
        lbBoardsLeft->setAlignment(Qt::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 30, 81, 20));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 50, 81, 20));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(false);
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignCenter);
        lbBoardsWin = new QLabel(groupBox);
        lbBoardsWin->setObjectName(QString::fromUtf8("lbBoardsWin"));
        lbBoardsWin->setGeometry(QRect(90, 50, 41, 20));
        lbBoardsWin->setFont(font1);
        lbBoardsWin->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 70, 91, 20));
        label_4->setAlignment(Qt::AlignCenter);
        lbBoardsDraw = new QLabel(groupBox);
        lbBoardsDraw->setObjectName(QString::fromUtf8("lbBoardsDraw"));
        lbBoardsDraw->setGeometry(QRect(90, 70, 41, 20));
        lbBoardsDraw->setFont(font1);
        lbBoardsDraw->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 90, 91, 20));
        label_5->setAlignment(Qt::AlignCenter);
        lbBoardsLost = new QLabel(groupBox);
        lbBoardsLost->setObjectName(QString::fromUtf8("lbBoardsLost"));
        lbBoardsLost->setGeometry(QRect(90, 90, 41, 20));
        lbBoardsLost->setFont(font1);
        lbBoardsLost->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 120, 141, 71));
        lbTimer = new QLabel(groupBox_2);
        lbTimer->setObjectName(QString::fromUtf8("lbTimer"));
        lbTimer->setGeometry(QRect(8, 27, 81, 35));
        QFont font3;
        font3.setPointSize(19);
        lbTimer->setFont(font3);
        lbTimer->setFrameShape(QFrame::Box);
        lbTimer->setFrameShadow(QFrame::Raised);
        lbTimer->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 33, 31, 21));
        QFont font4;
        font4.setPointSize(11);
        label_6->setFont(font4);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 141, 121));
        sbGamesQty = new QSpinBox(groupBox_3);
        sbGamesQty->setObjectName(QString::fromUtf8("sbGamesQty"));
        sbGamesQty->setGeometry(QRect(80, 30, 51, 31));
        QFont font5;
        font5.setPointSize(12);
        font5.setBold(true);
        sbGamesQty->setFont(font5);
        sbGamesQty->setCursor(QCursor(Qt::ArrowCursor));
        sbGamesQty->setAlignment(Qt::AlignCenter);
        sbGamesQty->setMinimum(1);
        sbGamesQty->setMaximum(121);
        btnStartFun = new QPushButton(groupBox_3);
        btnStartFun->setObjectName(QString::fromUtf8("btnStartFun"));
        btnStartFun->setGeometry(QRect(10, 70, 121, 41));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 71, 31));
        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setGeometry(QRect(10, 200, 141, 31));
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));
        tableResult = new QTableWidget(centralwidget);
        tableResult->setObjectName(QString::fromUtf8("tableResult"));
        tableResult->setGeometry(QRect(10, 610, 141, 41));
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
        tableResult->verticalHeader()->setDefaultSectionSize(24);
        tableResult->verticalHeader()->setHighlightSections(true);
        btnResults = new QPushButton(centralwidget);
        btnResults->setObjectName(QString::fromUtf8("btnResults"));
        btnResults->setGeometry(QRect(10, 660, 141, 51));
        lblImage = new QLabel(centralwidget);
        lblImage->setObjectName(QString::fromUtf8("lblImage"));
        lblImage->setGeometry(QRect(160, 0, 681, 731));
        lblImage->setFrameShape(QFrame::NoFrame);
        lblImage->setPixmap(QPixmap(QString::fromUtf8("blackboard.png")));
        lblImage->setScaledContents(true);
        btnStartPow2 = new QPushButton(centralwidget);
        btnStartPow2->setObjectName(QString::fromUtf8("btnStartPow2"));
        btnStartPow2->setGeometry(QRect(10, 470, 141, 61));
        btnStartPow3 = new QPushButton(centralwidget);
        btnStartPow3->setObjectName(QString::fromUtf8("btnStartPow3"));
        btnStartPow3->setGeometry(QRect(10, 540, 141, 61));
        btnStartChalenge = new QPushButton(centralwidget);
        btnStartChalenge->setObjectName(QString::fromUtf8("btnStartChalenge"));
        btnStartChalenge->setGeometry(QRect(10, 400, 141, 61));
        MainWindow->setCentralWidget(centralwidget);
        lblImage->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        btnPause->raise();
        btnResults->raise();
        btnStartPow2->raise();
        tableResult->raise();
        btnStartPow3->raise();
        btnStartChalenge->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
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
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause / Break", nullptr));
        btnResults->setText(QCoreApplication::translate("MainWindow", "TOP Players", nullptr));
        lblImage->setText(QString());
        btnStartPow2->setText(QCoreApplication::translate("MainWindow", "Square Power", nullptr));
        btnStartPow3->setText(QCoreApplication::translate("MainWindow", "Cube Power", nullptr));
        btnStartChalenge->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
