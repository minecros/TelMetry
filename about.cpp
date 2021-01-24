#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    description = "Telemetry - A simple application for visualizing data logged from sensors for cars and other machinery. "
                  "Using this application you can see the state of selected components during each stage of operation. "
                  "Telemetry is constantly being updated, and is produced on open source licensing.";

    ui->setupUi(this);
    ui->text->setText(description);

}

About::~About()
{
    delete ui;
}
