#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include <QDebug>

Menu::Menu(QString name,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{

    ui->setupUi(this);
  // this->setWindowState(Qt::WindowMaximized);

    QString im; //zelim samo broj u im
       int id;
       if(name.size()==7)
        im= name.right(1);
       else  im= name.right(2);
       id=im.toInt();

QString ime;
       if(id<7){this->setStyleSheet("background-color:rgb(245, 244, 225)");ime=":/new/prefix1/papa2.png";
       ui->pushButton_3->setStyleSheet("background-color:#ffea00;    border-style: outset;    border-width: 2px;    border-radius: 10px;    border-color:#c36f09;    font: bold 11px;    min-width: 10em; padding: 6px;");
       } else
   if(id<13){this->setStyleSheet("background-color:rgb(234, 250, 228)");ime=":/new/prefix1/papa3.png";
        ui->pushButton_3->setStyleSheet("background-color:#b7e4c7;    border-style: outset;    border-width: 2px;    border-radius: 10px;    border-color:#40916c;    font: bold 11px;    min-width: 10em; padding: 6px;");
   }
   else {this->setStyleSheet("background-color:rgb(236, 235, 255)");ime=":/new/prefix1/papa.png";
       ui->pushButton_3->setStyleSheet("background-color:#90e0ef;    border-style: outset;    border-width: 2px;    border-radius: 10px;    border-color:#219ebc;    font: bold 11px;    min-width: 10em; padding: 6px;");
   }
QPixmap nesto(ime);ui->labelSlika->setPixmap(nesto);
ui->lineID->setText(QString::number(id));
model =new QSqlTableModel(this);
model->setTable("izaberi_sjediste");
model->setEditStrategy(QSqlTableModel::OnManualSubmit);
model->select();

}

Menu::~Menu()
{
    delete ui;
}



void Menu::on_pushButton_3_clicked()
{
    QSqlRecord record=model->record();
    QString Ime;
    QString Prezime;
    QString godine;
    QString brPasosa;

    QString id=ui->lineID->text();

    Ime=ui->lineIme->text();
    Prezime=ui->linePrezime->text();
    godine=ui->lineGodine->text();
    brPasosa=ui->linePasos->text();
    record.setValue("ime",Ime);
    record.setValue("prezime",Prezime);
    record.setValue("godine",godine);
    record.setValue("broj_pasosa",brPasosa);
    record.setValue("id_sjedista",id);

    if(model->insertRecord(-1,record))
     {  QMessageBox::information(this,tr("Rezervisano"),tr("Rezervisali ste sjediste"));
        QSqlQuery updateMjesto;
          updateMjesto.prepare("UPDATE broj_sjedista set slobodno=2 WHERE id_sjedista=:val");
          updateMjesto.bindValue(":val", id);
          updateMjesto.exec();

    }
    else
        model->revertAll();
      model->submitAll();
      this->done(1);  // Gasim Prozor i saljem programu TRUE VALUE



}
