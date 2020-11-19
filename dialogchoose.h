#ifndef DIALOGCHOOSE_H
#define DIALOGCHOOSE_H

#include <QDialog>
#include <QWidget>
#include "mainwindow.h"
#include <QStringList>


namespace Ui {
class DialogChoose;
}

class DialogChoose : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChoose(QStringList a, QWidget *parent = nullptr);
    ~DialogChoose();

private:
    Ui::DialogChoose *ui;
};

#endif // DIALOGCHOOSE_H
