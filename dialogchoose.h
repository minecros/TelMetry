#ifndef DIALOGCHOOSE_H
#define DIALOGCHOOSE_H

#include <QDialog>
#include <QWidget>
#include "mainwindow.h"
#include <QStringList>
#include <QString>
#include <QLCDNumber>
#include <QLayout>
#include <QVector>
#include "digit.h"
#include "form.h"
#include <QScrollArea>

namespace Ui {
class DialogChoose;
}

class DialogChoose : public QDialog
{
    Q_OBJECT

public:
    explicit DialogChoose(QScrollBar *scrollBar,QStringList &a,QVBoxLayout *par,QVector <QLCDNumber*>*vector,QList<QStringList>data,QList<QStringList*>*readyData, QWidget *parent = nullptr);
    ~DialogChoose();



private slots:
    void on_buttonBox_accepted();

    void on_listWidget_itemClicked(QListWidgetItem *item);
    void on_buttonBox_rejected();


private:
    Ui::DialogChoose *ui;
    QPushButton *pb;

    QStringList b;
    QString chList;
    QStringList &testLabel;
    QVBoxLayout *parentVLayout;
    QScrollArea *scr;
    QLCDNumber lcd;
    QVector <QLCDNumber*>*LCDvector;
    QVector <QLabel*>Labels;

    QList<QStringList>data;
    QList<QStringList*>*tempData;

    QScrollBar *scrollBar;



};

#endif // DIALOGCHOOSE_H
