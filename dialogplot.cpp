#include "dialogplot.h"
#include "ui_dialogplot.h"
#include <QLayout>

DialogPlot::DialogPlot(QVBoxLayout *par,QStringList &a,QList<QStringList>data,QSplitter *splitter,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPlot),
    testLabel(a)
{

    ui->setupUi(this);
    this->data = data;
    parentVLayout = par;
    this->splitter = splitter;

    //wypisanie etykiet do pierwszej listy
    for (int i = 0; i < testLabel.size(); ++i){

        QListWidgetItem *item = new QListWidgetItem;
        item->setText(testLabel.at(i));
        item->setCheckState(Qt::Unchecked);
        ui->listWidgetX->addItem(item);
    }

    //wypisanie etykiet do drugiej listy
    for (int i = 0; i < testLabel.size(); ++i){

        QListWidgetItem *item = new QListWidgetItem;
        item->setText(testLabel.at(i));
        item->setCheckState(Qt::Unchecked);
        ui->listWidgetY->addItem(item);
    }
    testLabel.clear();
}

DialogPlot::~DialogPlot()
{
    delete ui;
}

void DialogPlot::on_listWidgetX_itemClicked(QListWidgetItem *item)
{
    if(item->checkState() == Qt::Checked){
        //gdy wybrano zawartiosc osi X

        labelX = item->text();

        for(int i = 0; i < data.at(0).count(); i++)
        {
            if(data.at(0).at(i) == item->text())
            {


                for(int j=0; j < data.count(); j++)
                {

                    seriaX.append(data.at(j).at(i).toDouble());

                }
            }
        }
    }
}

void DialogPlot::on_listWidgetY_itemClicked(QListWidgetItem *item)
{
    //gdy wybrano zawartiosc osi Y

    labelY = item->text();

    for(int i = 0; i < data.at(0).count(); i++)
    {
        if(data.at(0).at(i) == item->text())
        {
            for(int j=0; j < data.count(); j++)
            {

                seriaY.append(data.at(j).at(i).toDouble());

            }
        }
    }

}

void DialogPlot::on_buttonBox_accepted()
{
    QLineSeries *series = new QLineSeries();

    for(int i = 0; i < seriaX.count(); i++)
    {
        series->append(seriaX.at(i),seriaY.at(i));
    }

    QChart * chart = new QChart();

    chart->addSeries(series);
    chart->setTitle(labelX+" / "+labelY);
    chart->createDefaultAxes();
    chart->axisX()->setTitleText(labelX);
    chart->axisY()->setTitleText(labelY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    splitter->addWidget(chartView);

}

void DialogPlot::on_buttonBox_rejected()
{

}
