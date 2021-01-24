#include "dialogchoose.h"
#include "ui_dialogchoose.h"
#include <QCheckBox>
#include <QPushButton>


DialogChoose::DialogChoose(QScrollBar *scrollBar, QStringList &a,QVBoxLayout *par,QVector <QLCDNumber*>*vector,QList<QStringList>data,QList<QStringList*>*readyData,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogChoose),
    testLabel(a)
{

    ui->setupUi(this);

    parentVLayout = par;
    LCDvector = vector;
    this->data = data;
    this->scrollBar = scrollBar;
    tempData = readyData;

    for (int i = 0; i < testLabel.size(); ++i)
    {

        QListWidgetItem *item = new QListWidgetItem;
        item->setText(testLabel.at(i));
        item->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(item);
    }

    testLabel.clear();
}

DialogChoose::~DialogChoose()
{
    delete ui;
}

void DialogChoose::on_buttonBox_accepted()
{



    //wyswietlenie etykiet i wyswietlaczy
    for(int i=0; i < LCDvector->count(); i++)
    {
        parentVLayout->addWidget(Labels.at(i));
        parentVLayout->addWidget(LCDvector->at(i));

    }

    scrollBar->setMinimum(1);
    scrollBar->setMaximum((tempData->at(0)->count())-1);

}

void DialogChoose::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if(item->checkState() == Qt::Checked){

        ui->textEdit->clear();
        chList.append(item->text()+"\n");
        testLabel = chList.split("\n");
        testLabel.removeDuplicates();


        QStringList *tmp = new QStringList;

        for(int i = 0; i < data.at(0).count(); i++)
        {
            if(data.at(0).at(i) == item->text())
            {
                for(int j=0; j < data.count(); j++)
                {

                    tmp->append(data.at(j).at(i));

                }
            }
        }

        tempData->append(tmp);

        ui->textEdit->setText(chList);

        Labels.append(new QLabel);
        Labels.last()->setText(item->text());

        LCDvector->append(new QLCDNumber);
        LCDvector->last()->setDigitCount(10);

    }
}

void DialogChoose::on_buttonBox_rejected()
{

}
