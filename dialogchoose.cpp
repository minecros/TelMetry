#include "dialogchoose.h"
#include "ui_dialogchoose.h"


DialogChoose::DialogChoose(QStringList a, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChoose)
{
    ui->setupUi(this);
    //ui ->listWidget

    for (int i = 0; i < a.size(); ++i){

    ui->listWidget->addItem(a.at(i));
    }

}

DialogChoose::~DialogChoose()
{
    delete ui;
}
