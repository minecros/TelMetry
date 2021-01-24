#ifndef DIALOGPLOT_H
#define DIALOGPLOT_H

#include <QDialog>
#include <QWidget>
#include <QListWidget>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>



namespace Ui {
class DialogPlot;
}

class DialogPlot : public QDialog
{
    Q_OBJECT

public:
    explicit DialogPlot(QVBoxLayout *par,QStringList &a,QList<QStringList>data,QSplitter *splitter,QWidget *parent = nullptr);
    ~DialogPlot();

private slots:

    void on_listWidgetX_itemClicked(QListWidgetItem *item);
    void on_listWidgetY_itemClicked(QListWidgetItem *item);
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DialogPlot *ui;

    QStringList b;
    QString chList;
    QStringList &testLabel;
    QList<QStringList>data;
    QList<QStringList>tempData;
    QList<QStringList>tempDataX;
    QList<QStringList>tempDataY;
    QVBoxLayout *parentVLayout;
    QSplitter *splitter;

    QString labelX;
    QString labelY;

    QList <double> seriaX;
    QList <double> seriaY;
};

#endif // DIALOGPLOT_H
