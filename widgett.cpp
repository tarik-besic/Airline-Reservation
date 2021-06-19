#include "widgett.h"
#include "ui_widgett.h"

widgett::widgett(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgett)
{
    ui->setupUi(this);
}

widgett::~widgett()
{
    delete ui;
}
