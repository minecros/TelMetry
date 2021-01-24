include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);

}

Form::~Form()
{
    delete ui;
}
void Form::setLabel(QString label){
    ui->label->setText(label);
}
void Form::setVal(float value){
    ui->lcdNumber->display(value);
}
