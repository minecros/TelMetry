#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QListWidgetItem>
#include "dialogchoose.h"
#include <QList>
#include "dane.h"
#include <QVector>
#include <QLCDNumber>
#include "dialogplot.h"
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include "about.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     double czas[10000];


private slots:

    void on_horizontalScrollBar_valueChanged(int value);
    void on_actionOpen_triggered();
    void on_pushButton_clicked();
    void on_pushButton_6_clicked();
    void on_playbutton_clicked();
    void changeData();
    void on_stopButton_clicked();
    void on_slowerButton_clicked();
    void on_fasterButton_clicked();
    void on_actionClose_triggered();
    void on_actionAbout_triggered();

private:


    Ui::MainWindow *ui;
    QString fileName;
    QStringList label;
    QStringList labelTab2;
    QStringList labelTab3;

    QList <QStringList>allData;
    QList <QStringList*>tab2Data;

    QList <QLCDNumber> lcd;
    QVector <QLCDNumber*>LCDvector;
    QSplitter *splitter = new QSplitter(Qt::Vertical);

    QTimer *timer = new QTimer();
    int time;
    int scrValue;

    bool ster = false;


};
#endif // MAINWINDOW_H
