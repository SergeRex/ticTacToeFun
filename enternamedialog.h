#ifndef ENTERNAMEDIALOG_H
#define ENTERNAMEDIALOG_H

#include "mainwindow.h"

#include <QDialog>

namespace Ui {
class EnterNameDialog;
}

class EnterNameDialog : public QDialog
{
    Q_OBJECT

public: // = nullptr
    explicit EnterNameDialog(QWidget *parent,MainWindow *mWindow);
    ~EnterNameDialog();
    QString getName();

private:
    Ui::EnterNameDialog *ui;
    QString playerName;

    void closeEvent(QCloseEvent *event);
};

#endif // ENTERNAMEDIALOG_H
