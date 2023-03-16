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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QLabel *label;
    QLabel *lbBoardsWin;
    QLabel *label_4;
    QLabel *lbBoardsDraw;
    QLabel *lbBoardsLost;
    QLabel *lbBoardsLeft;
    QLabel *lbBoardsQty;
    QLabel *label_5;
    QFrame *line;
    QGroupBox *groupBox_2;
    QLabel *lbTimer;
    QLabel *label_6;
    QPushButton *btnPause;
    QLabel *lblImage;
    QGroupBox *allGamesGroupBox;
    QGroupBox *groupBox_3;
    QTableWidget *tableResult;
    QPushButton *btnStartChalenge;
    QPushButton *btnStartFun;
    QGroupBox *groupBox_4;
    QTableWidget *tableResultPow2;
    QPushButton *btnStartPow2;
    QGroupBox *groupBox_6;
    QTableWidget *tableResultPow3;
    QPushButton *btnStartPow3;
    QGroupBox *groupBox_7;
    QLabel *lblGameType;
    QLabel *lb2t;
    QPushButton *btnChangeName;
    QPushButton *btnCrazyMode;
    QLabel *lbPlayerName;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1020, 627);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        btnLoadImage = new QAction(MainWindow);
        btnLoadImage->setObjectName(QString::fromUtf8("btnLoadImage"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 280, 141, 101));
        QFont font;
        font.setPointSize(9);
        groupBox->setFont(font);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 51, 20));
        label->setAlignment(Qt::AlignCenter);
        lbBoardsWin = new QLabel(groupBox);
        lbBoardsWin->setObjectName(QString::fromUtf8("lbBoardsWin"));
        lbBoardsWin->setGeometry(QRect(0, 70, 50, 20));
        QFont font1;
        font1.setPointSize(9);
        font1.setBold(true);
        lbBoardsWin->setFont(font1);
        lbBoardsWin->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 50, 141, 20));
        label_4->setAlignment(Qt::AlignCenter);
        lbBoardsDraw = new QLabel(groupBox);
        lbBoardsDraw->setObjectName(QString::fromUtf8("lbBoardsDraw"));
        lbBoardsDraw->setGeometry(QRect(50, 70, 41, 20));
        lbBoardsDraw->setFont(font1);
        lbBoardsDraw->setAlignment(Qt::AlignCenter);
        lbBoardsLost = new QLabel(groupBox);
        lbBoardsLost->setObjectName(QString::fromUtf8("lbBoardsLost"));
        lbBoardsLost->setGeometry(QRect(90, 70, 50, 20));
        lbBoardsLost->setFont(font1);
        lbBoardsLost->setAlignment(Qt::AlignCenter);
        lbBoardsLeft = new QLabel(groupBox);
        lbBoardsLeft->setObjectName(QString::fromUtf8("lbBoardsLeft"));
        lbBoardsLeft->setGeometry(QRect(100, 20, 41, 20));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(false);
        lbBoardsLeft->setFont(font2);
        lbBoardsLeft->setAlignment(Qt::AlignCenter);
        lbBoardsQty = new QLabel(groupBox);
        lbBoardsQty->setObjectName(QString::fromUtf8("lbBoardsQty"));
        lbBoardsQty->setGeometry(QRect(40, 20, 41, 20));
        lbBoardsQty->setFont(font2);
        lbBoardsQty->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 20, 41, 20));
        label_5->setAlignment(Qt::AlignCenter);
        line = new QFrame(groupBox);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 40, 141, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 210, 141, 71));
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
        btnPause = new QPushButton(centralwidget);
        btnPause->setObjectName(QString::fromUtf8("btnPause"));
        btnPause->setGeometry(QRect(10, 390, 141, 41));
        btnPause->setCursor(QCursor(Qt::PointingHandCursor));
        lblImage = new QLabel(centralwidget);
        lblImage->setObjectName(QString::fromUtf8("lblImage"));
        lblImage->setGeometry(QRect(170, 0, 671, 731));
        lblImage->setFrameShape(QFrame::NoFrame);
        lblImage->setScaledContents(true);
        allGamesGroupBox = new QGroupBox(centralwidget);
        allGamesGroupBox->setObjectName(QString::fromUtf8("allGamesGroupBox"));
        allGamesGroupBox->setGeometry(QRect(160, 0, 891, 571));
        allGamesGroupBox->setAutoFillBackground(false);
        allGamesGroupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 237, 255);"));
        groupBox_3 = new QGroupBox(allGamesGroupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 381, 551));
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(224, 255, 210);"));
        groupBox_3->setFlat(false);
        tableResult = new QTableWidget(groupBox_3);
        if (tableResult->columnCount() < 7)
            tableResult->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableResult->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableResult->setObjectName(QString::fromUtf8("tableResult"));
        tableResult->setGeometry(QRect(10, 30, 361, 401));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableResult->sizePolicy().hasHeightForWidth());
        tableResult->setSizePolicy(sizePolicy);
        tableResult->setTabletTracking(false);
        tableResult->setAutoFillBackground(false);
        tableResult->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResult->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableResult->setAutoScroll(true);
        tableResult->setSelectionMode(QAbstractItemView::NoSelection);
        tableResult->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableResult->setTextElideMode(Qt::ElideNone);
        tableResult->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableResult->setShowGrid(true);
        tableResult->setSortingEnabled(true);
        tableResult->horizontalHeader()->setVisible(true);
        tableResult->horizontalHeader()->setCascadingSectionResizes(false);
        tableResult->horizontalHeader()->setHighlightSections(true);
        tableResult->verticalHeader()->setVisible(true);
        tableResult->verticalHeader()->setCascadingSectionResizes(false);
        tableResult->verticalHeader()->setDefaultSectionSize(24);
        tableResult->verticalHeader()->setHighlightSections(true);
        btnStartChalenge = new QPushButton(groupBox_3);
        btnStartChalenge->setObjectName(QString::fromUtf8("btnStartChalenge"));
        btnStartChalenge->setGeometry(QRect(160, 450, 211, 71));
        btnStartChalenge->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        btnStartFun = new QPushButton(groupBox_3);
        btnStartFun->setObjectName(QString::fromUtf8("btnStartFun"));
        btnStartFun->setGeometry(QRect(10, 450, 141, 71));
        btnStartFun->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        groupBox_4 = new QGroupBox(allGamesGroupBox);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(400, 10, 221, 551));
        groupBox_4->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 254, 240);"));
        tableResultPow2 = new QTableWidget(groupBox_4);
        if (tableResultPow2->columnCount() < 3)
            tableResultPow2->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableResultPow2->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableResultPow2->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableResultPow2->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        tableResultPow2->setObjectName(QString::fromUtf8("tableResultPow2"));
        tableResultPow2->setGeometry(QRect(10, 30, 201, 401));
        sizePolicy.setHeightForWidth(tableResultPow2->sizePolicy().hasHeightForWidth());
        tableResultPow2->setSizePolicy(sizePolicy);
        tableResultPow2->setTabletTracking(false);
        tableResultPow2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableResultPow2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResultPow2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResultPow2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableResultPow2->setAutoScroll(false);
        tableResultPow2->setSelectionMode(QAbstractItemView::NoSelection);
        tableResultPow2->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableResultPow2->setTextElideMode(Qt::ElideNone);
        tableResultPow2->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableResultPow2->setShowGrid(true);
        tableResultPow2->setSortingEnabled(true);
        tableResultPow2->horizontalHeader()->setVisible(true);
        tableResultPow2->horizontalHeader()->setCascadingSectionResizes(true);
        tableResultPow2->horizontalHeader()->setHighlightSections(true);
        tableResultPow2->verticalHeader()->setVisible(true);
        tableResultPow2->verticalHeader()->setCascadingSectionResizes(true);
        tableResultPow2->verticalHeader()->setDefaultSectionSize(24);
        tableResultPow2->verticalHeader()->setHighlightSections(true);
        btnStartPow2 = new QPushButton(groupBox_4);
        btnStartPow2->setObjectName(QString::fromUtf8("btnStartPow2"));
        btnStartPow2->setGeometry(QRect(10, 450, 201, 71));
        btnStartPow2->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        groupBox_6 = new QGroupBox(allGamesGroupBox);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(630, 10, 221, 551));
        groupBox_6->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 213, 219);"));
        tableResultPow3 = new QTableWidget(groupBox_6);
        if (tableResultPow3->columnCount() < 3)
            tableResultPow3->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableResultPow3->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableResultPow3->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableResultPow3->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        tableResultPow3->setObjectName(QString::fromUtf8("tableResultPow3"));
        tableResultPow3->setGeometry(QRect(10, 30, 201, 401));
        sizePolicy.setHeightForWidth(tableResultPow3->sizePolicy().hasHeightForWidth());
        tableResultPow3->setSizePolicy(sizePolicy);
        tableResultPow3->setTabletTracking(false);
        tableResultPow3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        tableResultPow3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResultPow3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableResultPow3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        tableResultPow3->setAutoScroll(false);
        tableResultPow3->setSelectionMode(QAbstractItemView::NoSelection);
        tableResultPow3->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableResultPow3->setTextElideMode(Qt::ElideNone);
        tableResultPow3->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        tableResultPow3->setShowGrid(true);
        tableResultPow3->setSortingEnabled(true);
        tableResultPow3->horizontalHeader()->setVisible(true);
        tableResultPow3->horizontalHeader()->setCascadingSectionResizes(true);
        tableResultPow3->horizontalHeader()->setHighlightSections(true);
        tableResultPow3->verticalHeader()->setVisible(true);
        tableResultPow3->verticalHeader()->setCascadingSectionResizes(true);
        tableResultPow3->verticalHeader()->setDefaultSectionSize(24);
        tableResultPow3->verticalHeader()->setHighlightSections(true);
        btnStartPow3 = new QPushButton(groupBox_6);
        btnStartPow3->setObjectName(QString::fromUtf8("btnStartPow3"));
        btnStartPow3->setGeometry(QRect(10, 450, 201, 71));
        btnStartPow3->setStyleSheet(QString::fromUtf8("background-color: rgb(240, 240, 240);"));
        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 160, 141, 51));
        lblGameType = new QLabel(groupBox_7);
        lblGameType->setObjectName(QString::fromUtf8("lblGameType"));
        lblGameType->setGeometry(QRect(10, 20, 121, 30));
        lblGameType->setFont(font1);
        lb2t = new QLabel(centralwidget);
        lb2t->setObjectName(QString::fromUtf8("lb2t"));
        lb2t->setGeometry(QRect(10, 10, 131, 111));
        lb2t->setPixmap(QPixmap(QString::fromUtf8("srs/3t.png")));
        lb2t->setScaledContents(true);
        btnChangeName = new QPushButton(centralwidget);
        btnChangeName->setObjectName(QString::fromUtf8("btnChangeName"));
        btnChangeName->setGeometry(QRect(120, 130, 30, 30));
        btnCrazyMode = new QPushButton(centralwidget);
        btnCrazyMode->setObjectName(QString::fromUtf8("btnCrazyMode"));
        btnCrazyMode->setGeometry(QRect(10, 460, 141, 70));
        lbPlayerName = new QLabel(centralwidget);
        lbPlayerName->setObjectName(QString::fromUtf8("lbPlayerName"));
        lbPlayerName->setGeometry(QRect(10, 130, 101, 30));
        lbPlayerName->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        lblImage->raise();
        groupBox->raise();
        groupBox_2->raise();
        btnPause->raise();
        allGamesGroupBox->raise();
        groupBox_7->raise();
        lb2t->raise();
        btnChangeName->raise();
        btnCrazyMode->raise();
        lbPlayerName->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1020, 21));
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
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Boards Progress", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Total:", nullptr));
        lbBoardsWin->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Won      Draw      Lost", nullptr));
        lbBoardsDraw->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lbBoardsLost->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lbBoardsLeft->setText(QCoreApplication::translate("MainWindow", "121", nullptr));
        lbBoardsQty->setText(QCoreApplication::translate("MainWindow", "121", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Left:", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Timer", nullptr));
        lbTimer->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "sec.", nullptr));
        btnPause->setText(QCoreApplication::translate("MainWindow", "Pause / Break", nullptr));
        lblImage->setText(QString());
        allGamesGroupBox->setTitle(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "TicTacToe Competition", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableResult->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableResult->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableResult->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableResult->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Brds.", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableResult->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "W", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableResult->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "D", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableResult->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        btnStartChalenge->setText(QCoreApplication::translate("MainWindow", "     Play Competition", nullptr));
        btnStartFun->setText(QCoreApplication::translate("MainWindow", "Training", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Ultimate TicTacToe", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableResultPow2->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableResultPow2->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableResultPow2->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        btnStartPow2->setText(QCoreApplication::translate("MainWindow", "     Play Ultimate TTT", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Extereme TicTacToe", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableResultPow3->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Player", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableResultPow3->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableResultPow3->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Time", nullptr));
        btnStartPow3->setText(QCoreApplication::translate("MainWindow", "     Play Exterme TTT", nullptr));
        groupBox_7->setTitle(QCoreApplication::translate("MainWindow", "Game Type", nullptr));
        lblGameType->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lb2t->setText(QString());
        btnChangeName->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        btnCrazyMode->setText(QString());
        lbPlayerName->setText(QCoreApplication::translate("MainWindow", "unknown player", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
