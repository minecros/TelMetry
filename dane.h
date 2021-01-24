#ifndef DANE_H
#define DANE_H
#include <QtSql>
#include <QSqlQuery>
#include <QFile>
#include <QString>
#include <QVector>

class Dane
{
public:
    Dane(QString fileName);
    ~Dane();
    QStringList getLabel();
    QStringList getRow();
    QList <QStringList>allData;

private:

    QStringList label;
    QStringList row;
    QFile file;

    QString text;


    bool isFileOpen = false;
    bool isLabelSet = false;



    void setLabel();
    void setRow();
    void readAll();





};

#endif // DANE_H
