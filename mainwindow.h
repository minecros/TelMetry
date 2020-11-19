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
#include "database.h"
#include "dialogchoose.h"
#include <QList>


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

private:
    Ui::MainWindow *ui;
    QString currentFile = "";
    QString fileName = "";
    QStringList label;
    QList <QStringList>all;

    bool isLabelSet = false;

    void openFile();
    void setLabel(QString text);
    void setRow(QString text, int i);

};
#endif // MAINWINDOW_H
