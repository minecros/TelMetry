#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

#ifndef FILELOAD_H
#define FILELOAD_H


class FileLoad
{
public:
    FileLoad();
    FileLoad(int a);
    FileLoad(MainWindow userMainWindow);

};

#endif // FILELOAD_H
