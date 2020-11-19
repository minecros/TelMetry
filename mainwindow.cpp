#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include "dane.h"


MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("TelMetry");
    isLabelSet = false;


}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionOpen_triggered()
{

    openFile();

}

void MainWindow::on_horizontalScrollBar_valueChanged(int value)
{
    ui -> lcdNumber -> display(value);
}

void MainWindow::openFile(){


    fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);

     if(!file.open(QIODevice::ReadOnly | QFile::Text)){
         QMessageBox::warning(this,"Warning","Cannot open file: ");
     }


     QTextStream in(&file);
     QString text = in.readLine();

     if(!isLabelSet){
         setLabel(text);
     }

     QStringList dane;

     ui -> tableAll -> setColumnCount(label.length());
     ui -> tableAll -> setHorizontalHeaderLabels(label);


     for(int i =0; !in.atEnd(); i++){

         text = in.readLine(0);
         setRow(text,i);

     }



     file.close();


}


void MainWindow::setLabel(QString aa){

    label = aa.split(',');
    isLabelSet = true;
}


void MainWindow::setRow(QString aa, int i){

    QStringList row = aa.split(',');

    //dodanie zmiennych do timerow
    czas[i] = row[0].toDouble();


    ui -> tableAll -> insertRow(ui -> tableAll -> rowCount());

    all.append(row);

    for(int j = 0; j < row.length(); j++){


        ui -> tableAll -> setItem(i,j,new QTableWidgetItem(row[j]));




    }
}


void MainWindow::on_pushButton_clicked()
{
    DialogChoose *chDialog;
    chDialog = new DialogChoose(label,this);
    chDialog->setWindowTitle("Choose valiables to visualisation");
    chDialog->show();
}
