#include "izbor_sjedista.h"
#include "ui_izbor_sjedista.h"

Izbor_Sjedista::Izbor_Sjedista(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Izbor_Sjedista)
{
    ui->setupUi(this);
}

Izbor_Sjedista::~Izbor_Sjedista()
{
    delete ui;
}
