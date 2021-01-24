#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>



MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TelMetry");
    ui->vLayoutTab3->addWidget(splitter);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this,SLOT(changeData()));
    time = 1000;
    scrValue = 0;

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionOpen_triggered()
{

    fileName = QFileDialog::getOpenFileName(this,"Open the file");

    Dane dane(fileName);

    label = dane.getLabel();
    allData = dane.allData;

    ui -> tableAll -> setColumnCount(label.length());

    for(int i = 0; i < allData.size();i++){

         ui -> tableAll -> insertRow(ui -> tableAll -> rowCount());

         for(int j = 0; j < allData.at(i).size(); j++){

             ui -> tableAll -> setItem(i,j, new QTableWidgetItem(allData.at(i)[j]));

         }
     }

}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{

    for(int i = 0; i < LCDvector.count(); i++){

        LCDvector.at(i)->display(tab2Data.at(i)->at(value));

    }

}

void MainWindow::on_pushButton_clicked()
{
    DialogChoose *chDialog;
    labelTab2 = label;

    chDialog = new DialogChoose(ui->horizontalScrollBar,labelTab2,ui->vLayout,&LCDvector,allData,&tab2Data,this);

    chDialog->setWindowTitle("Choose variables to visualisation");
    chDialog->show();

    //ui->horizontalScrollBar->setMaximum(tab2Data.at(0)->count()-1);
}

void MainWindow::on_pushButton_6_clicked()
{
    DialogPlot *dialogPlot;
    labelTab3 = label;

    dialogPlot = new DialogPlot(ui->vLayoutTab3,labelTab3,allData,splitter,this);
    dialogPlot->setWindowTitle("Chosse variables to draw chart");

    dialogPlot->show();
}


void MainWindow::changeData()
{
    if(scrValue < tab2Data.at(0)->count()){

        scrValue++;

    }else
    {

        scrValue = 0;

    }

    for(int i = 0; i < LCDvector.count(); i++){

        LCDvector.at(i)->display(tab2Data.at(i)->at(scrValue));
    }
}
void MainWindow::on_playbutton_clicked()
{
    timer->start(time);
}
void MainWindow::on_stopButton_clicked()
{
    timer->stop();
}

void MainWindow::on_slowerButton_clicked()
{
    if(time < 3000)
    {
        time+=50;
    }

    timer->start(time);
}

void MainWindow::on_fasterButton_clicked()
{
    if(time > 50)
    {
        time-=50;
    }
    timer->start(time);
}

void MainWindow::on_actionClose_triggered()
{
    //close application
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    //open about window
    About *about;
    about = new About(this);
    about->setWindowTitle("Telmetry - about");
    about->show();

}
