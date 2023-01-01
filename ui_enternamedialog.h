/********************************************************************************
** Form generated from reading UI file 'enternamedialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENTERNAMEDIALOG_H
#define UI_ENTERNAMEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_EnterNameDialog
{
public:
    QPushButton *pbOK;
    QGroupBox *gbNameEnter;
    QLineEdit *nameLine;
    QLabel *label;
    QGroupBox *groupBox_2;
    QLabel *label_4;
    QLabel *lbBoards;
    QLabel *label_5;
    QLabel *lbTotalScore;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *lbTimeMin;
    QLabel *lbTimeSec;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *lbWin;
    QLabel *label_9;
    QLabel *lbWinScore;
    QLabel *label_11;
    QLabel *lbDraw;
    QLabel *label_13;
    QLabel *lbDrawScore;
    QLabel *lbLostScore;
    QLabel *lbLost;
    QLabel *label_17;
    QLabel *label_18;
    QTextBrowser *tbNoRecord;

    void setupUi(QDialog *EnterNameDialog)
    {
        if (EnterNameDialog->objectName().isEmpty())
            EnterNameDialog->setObjectName("EnterNameDialog");
        EnterNameDialog->resize(290, 449);
        pbOK = new QPushButton(EnterNameDialog);
        pbOK->setObjectName("pbOK");
        pbOK->setGeometry(QRect(40, 410, 201, 31));
        gbNameEnter = new QGroupBox(EnterNameDialog);
        gbNameEnter->setObjectName("gbNameEnter");
        gbNameEnter->setGeometry(QRect(40, 240, 201, 71));
        nameLine = new QLineEdit(gbNameEnter);
        nameLine->setObjectName("nameLine");
        nameLine->setGeometry(QRect(10, 33, 181, 24));
        label = new QLabel(EnterNameDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 261, 21));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        groupBox_2 = new QGroupBox(EnterNameDialog);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(40, 130, 201, 101));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 30, 41, 16));
        lbBoards = new QLabel(groupBox_2);
        lbBoards->setObjectName("lbBoards");
        lbBoards->setGeometry(QRect(50, 30, 31, 21));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        lbBoards->setFont(font1);
        lbBoards->setFrameShape(QFrame::Box);
        lbBoards->setFrameShadow(QFrame::Raised);
        lbBoards->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 30, 41, 16));
        lbTotalScore = new QLabel(groupBox_2);
        lbTotalScore->setObjectName("lbTotalScore");
        lbTotalScore->setGeometry(QRect(130, 30, 49, 16));
        lbTotalScore->setFont(font);
        lbTotalScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_19 = new QLabel(groupBox_2);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 70, 31, 16));
        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(140, 70, 21, 16));
        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(80, 70, 31, 16));
        lbTimeMin = new QLabel(groupBox_2);
        lbTimeMin->setObjectName("lbTimeMin");
        lbTimeMin->setGeometry(QRect(40, 70, 31, 20));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        lbTimeMin->setFont(font2);
        lbTimeMin->setAlignment(Qt::AlignCenter);
        lbTimeSec = new QLabel(groupBox_2);
        lbTimeSec->setObjectName("lbTimeSec");
        lbTimeSec->setGeometry(QRect(110, 70, 31, 20));
        lbTimeSec->setFont(font2);
        lbTimeSec->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(EnterNameDialog);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(40, 30, 201, 101));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 30, 41, 16));
        lbWin = new QLabel(groupBox_3);
        lbWin->setObjectName("lbWin");
        lbWin->setGeometry(QRect(50, 30, 31, 21));
        QFont font3;
        font3.setPointSize(8);
        font3.setBold(false);
        lbWin->setFont(font3);
        lbWin->setFrameShape(QFrame::Box);
        lbWin->setFrameShadow(QFrame::Raised);
        lbWin->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(90, 30, 41, 16));
        lbWinScore = new QLabel(groupBox_3);
        lbWinScore->setObjectName("lbWinScore");
        lbWinScore->setGeometry(QRect(130, 30, 49, 16));
        lbWinScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 50, 41, 16));
        lbDraw = new QLabel(groupBox_3);
        lbDraw->setObjectName("lbDraw");
        lbDraw->setGeometry(QRect(50, 50, 31, 21));
        lbDraw->setFont(font3);
        lbDraw->setFrameShape(QFrame::Box);
        lbDraw->setFrameShadow(QFrame::Raised);
        lbDraw->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(90, 50, 41, 16));
        lbDrawScore = new QLabel(groupBox_3);
        lbDrawScore->setObjectName("lbDrawScore");
        lbDrawScore->setGeometry(QRect(130, 50, 49, 16));
        lbDrawScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbLostScore = new QLabel(groupBox_3);
        lbLostScore->setObjectName("lbLostScore");
        lbLostScore->setGeometry(QRect(130, 70, 49, 16));
        lbLostScore->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lbLost = new QLabel(groupBox_3);
        lbLost->setObjectName("lbLost");
        lbLost->setGeometry(QRect(50, 70, 31, 21));
        lbLost->setFont(font3);
        lbLost->setFrameShape(QFrame::Box);
        lbLost->setFrameShadow(QFrame::Raised);
        lbLost->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(10, 70, 41, 16));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(90, 70, 41, 16));
        tbNoRecord = new QTextBrowser(EnterNameDialog);
        tbNoRecord->setObjectName("tbNoRecord");
        tbNoRecord->setGeometry(QRect(40, 320, 201, 81));

        retranslateUi(EnterNameDialog);

        QMetaObject::connectSlotsByName(EnterNameDialog);
    } // setupUi

    void retranslateUi(QDialog *EnterNameDialog)
    {
        EnterNameDialog->setWindowTitle(QCoreApplication::translate("EnterNameDialog", "TicTacToe Fun )", nullptr));
        pbOK->setText(QCoreApplication::translate("EnterNameDialog", "OK", nullptr));
        gbNameEnter->setTitle(QCoreApplication::translate("EnterNameDialog", "Please enter your name:", nullptr));
        label->setText(QCoreApplication::translate("EnterNameDialog", "The game is completed!", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("EnterNameDialog", "Total", nullptr));
        label_4->setText(QCoreApplication::translate("EnterNameDialog", "Boards", nullptr));
        lbBoards->setText(QCoreApplication::translate("EnterNameDialog", "66", nullptr));
        label_5->setText(QCoreApplication::translate("EnterNameDialog", "Points", nullptr));
        lbTotalScore->setText(QCoreApplication::translate("EnterNameDialog", "15000", nullptr));
        label_19->setText(QCoreApplication::translate("EnterNameDialog", "TIME", nullptr));
        label_20->setText(QCoreApplication::translate("EnterNameDialog", "sec.", nullptr));
        label_21->setText(QCoreApplication::translate("EnterNameDialog", "min.", nullptr));
        lbTimeMin->setText(QCoreApplication::translate("EnterNameDialog", "99", nullptr));
        lbTimeSec->setText(QCoreApplication::translate("EnterNameDialog", "99", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("EnterNameDialog", "Details", nullptr));
        label_7->setText(QCoreApplication::translate("EnterNameDialog", "Win", nullptr));
        lbWin->setText(QCoreApplication::translate("EnterNameDialog", "66", nullptr));
        label_9->setText(QCoreApplication::translate("EnterNameDialog", "Points", nullptr));
        lbWinScore->setText(QCoreApplication::translate("EnterNameDialog", "15000", nullptr));
        label_11->setText(QCoreApplication::translate("EnterNameDialog", "Draw", nullptr));
        lbDraw->setText(QCoreApplication::translate("EnterNameDialog", "66", nullptr));
        label_13->setText(QCoreApplication::translate("EnterNameDialog", "Points", nullptr));
        lbDrawScore->setText(QCoreApplication::translate("EnterNameDialog", "15000", nullptr));
        lbLostScore->setText(QCoreApplication::translate("EnterNameDialog", "15000", nullptr));
        lbLost->setText(QCoreApplication::translate("EnterNameDialog", "66", nullptr));
        label_17->setText(QCoreApplication::translate("EnterNameDialog", "Lost", nullptr));
        label_18->setText(QCoreApplication::translate("EnterNameDialog", "Points", nullptr));
        tbNoRecord->setHtml(QCoreApplication::translate("EnterNameDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Your score will not be added to the records. Records are avaliable for the games with at least 16 boards and results over 0.</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EnterNameDialog: public Ui_EnterNameDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENTERNAMEDIALOG_H
