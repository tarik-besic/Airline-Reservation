#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <menu.h>
#include "konk.h"
#include <my_label.h>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(700,550);
    konekcija();
   connect(ui->label_1,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));

   var=new QSqlQueryModel;
   var->setQuery("select * from ispisi_Zauzeta_Sjedista");
   ui->tableView->setModel(var);
   ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   ui->tableView->hide();

    connect(ui->label_2,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->label_3,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->label_4,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
    connect(ui->label_5,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
      connect(ui->label_6,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
       connect(ui->label_7,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
       connect(ui->label_8,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
        connect(ui->label_9,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
        connect(ui->label_10,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
         connect(ui->label_11,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
         connect(ui->label_12,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
          connect(ui->label_13,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
          connect(ui->label_14,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
           connect(ui->label_15,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
           connect(ui->label_16,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
            connect(ui->label_17,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
            connect(ui->label_18,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
             connect(ui->label_19,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
             connect(ui->label_20,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
              connect(ui->label_21,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
              connect(ui->label_22,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
               connect(ui->label_23,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
               connect(ui->label_24,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));
               connect(ui->label_25,SIGNAL(Mouse_Pressed()),this,SLOT(Mouse_Pressed()));

    QString ime="label_";
    int t;
    for(int i=1;i<=25;i++)
    {

         t=i;
         ime.append(QString::number(t));
         QLabel *ptr=this->findChild<QLabel*>(ime);
         ime="label_";
          ptr->hide();
    }

    ui->pushButton_2->hide();

    QSqlQuery query;
    query.prepare("SELECT naziv_klase FROM ispisi_Zauzeta_Sjedista");
    query.exec();
    int i=0;

    while(query.next()){i++;}

    ui->lcdNumber->display(25-i);

}
MainWindow::~MainWindow()
{
    delete ui;
}

int id;
void MainWindow::Mouse_Pressed( )
{
    QString name;
    if(QObject* pObject = sender())   //DOBIJEMO NAZIV LABELE OVDJE
       {  name = pObject->objectName();
    }
     id=nekaFunk(name);
    bool otvori=true;
 QSqlQuery query;  //Pomocu querya gledam da li je zauzeto sjediste u bazi podataka
  query.exec("SELECT id_sjedista,naziv FROM ispisi_Zauzeta_Sjedista");
  while(query.next())
  {
  if(id==query.value(0).toInt())otvori=false;
  }
Menu nesto(name);
 bool res; //Varijabla da vidim da li je korisnik rezervisao sjediste kad je otvorio prozor.
if(otvori){
  nesto.setModal(true);
  res=nesto.exec();  //2 u 1 :)))   otvori prozor normalno i vrati mi rezultat jel korisnik unio podatke i rezervisao ili slucajno otvorio
}
else {
    QMessageBox::critical(nullptr, QObject::tr("Eror!!!!"),
    QObject::tr("ZAUZETO SJEDISTE.\n"
    "Kliknite na Cancel za izlaz."), QMessageBox::Cancel);

}
QString ime2="label_";
if(res){  //Ako je rezervisano sjediste promjeni IKONICU SJEDISTA NA ZAUZETO SJEDISTE!
    int w2 = ui->label_23->width();
    int h2 = ui->label_23->height();
    QPixmap nesto5(":/new/prefix1/papa4.png");
    ime2.append(QString::number(id));
     QLabel *ptr=this->findChild<QLabel*>(ime2);
      ptr->setPixmap(nesto5.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));

}

var=new QSqlQueryModel; //QUERY SAMO DA MI UPDATE TABELU
var->setQuery("SELECT ime,prezime,id_sjedista,naziv_klase FROM ispisi_Zauzeta_Sjedista");
ui->tableView->setModel(var);
var=new QSqlQueryModel;
var->setQuery("select naziv from ispisi_Zauzeta_Sjedista");
}



void MainWindow::postaviLabele()  //postavlja slike labelama
{
    QPixmap nesto("C:/Users/admir/Desktop/FinalniProjekat/slikica.png");
    QPixmap nesto2(":/new/prefix1/papa.png");
    QPixmap nesto3(":/new/prefix1/papa2.png");
    QPixmap nesto4(":/new/prefix1/papa3.png");

    int w = ui->label1->width();
    int h = ui->label1->height();
    int w2 = ui->label_23->width();
    int h2 = ui->label_23->height();

    ui->label1->setPixmap(nesto.scaled(w,h,Qt::KeepAspectRatioByExpanding));

    int t;
     ui->label_23->setPixmap(nesto2.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));
     ui->label_25->setPixmap(nesto3.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));
     QString ime="label_";
     //For looop za prvu klasu stavaljanje slika u labele
     for(int i=1;i<7;i++)
     {
          t=i;
          ime.append(QString::number(t));
          QLabel *ptr=this->findChild<QLabel*>(ime);
          ptr->setPixmap(nesto3.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));
          ime="label_";
               ptr->show();

     }
     //For looop za Biznis klasu stavaljanje slika u labele
     for(int i=7;i<=12;i++)
     {
          t=i;
          ime.append(QString::number(t));
          QLabel *ptr=this->findChild<QLabel*>(ime);
          ptr->setPixmap(nesto4.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));
          ime="label_";
          ptr->show();
     }

     for(int i=13;i<=25;i++)
     {
          t=i;
          ime.append(QString::number(t));
          QLabel *ptr=this->findChild<QLabel*>(ime);
          ptr->setPixmap(nesto2.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));
          ime="label_";
          ptr->show();
     }
}


void MainWindow::on_pushButton_clicked()
{
   this->setWindowState(Qt::WindowMaximized);
   postaviLabele();
   ui->poctnaLabela->hide();
   ui->pushButton->hide();

on_pushButton_2_clicked();



}
void MainWindow::on_pushButton_2_clicked() //ovdje provjeravam iz VIEW-a koja su sjedista zauzeta i stavljam im slike crne
{
    QString ime="label_";

    var=new QSqlQueryModel;
    var->setQuery("select naziv from ispisi_Zauzeta_Sjedista");

    int w2 = ui->label_23->width();
    int h2 = ui->label_23->height();
    QPixmap nesto5(":/new/prefix1/papa4.png");
    QSqlQuery query("SELECT naziv,id_sjedista FROM ispisi_Zauzeta_Sjedista");
        while (query.next()) {
            QString naziv = query.value(0).toString();
            int broj=query.value(1).toInt();
            ime.append(QString::number(broj));

              QLabel *ptr=this->findChild<QLabel*>(ime);
             ptr->setPixmap(nesto5.scaled(w2,h2,Qt::KeepAspectRatioByExpanding));
              ime="label_";}
        var=new QSqlQueryModel;
        var->setQuery("SELECT ime,prezime,id_sjedista,naziv_klase FROM ispisi_Zauzeta_Sjedista");

        ui->tableView->setModel(var);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
        ui->tableView->show();
        }



void MainWindow::on_radioButton_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT naziv_klase FROM ispisi_Zauzeta_Sjedista");
    query.exec();
    int i=0;
    while(query.next()){QString name=query.value(0).toString(); if(name=="Prva klasa")i++;}

    ui->lcdNumber->display(6-i);

}

void MainWindow::on_radioButton_2_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT naziv_klase FROM ispisi_Zauzeta_Sjedista");
    query.exec();
    int i=0;
    while(query.next()){QString name=query.value(0).toString(); if(name=="Biznis klasa")i++;}

    ui->lcdNumber->display(6-i);

}

void MainWindow::on_radioButton_3_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT naziv_klase FROM ispisi_Zauzeta_Sjedista");
    query.exec();
    int i=0; //brojac da vidim koliko je zauzetih sjedista
    while(query.next()){QString name=query.value(0).toString(); if(name=="Ekonomska klasa")i++;}

    ui->lcdNumber->display(13-i);

}



void MainWindow::on_comboBox_activated(int index)
{
    QString naziv,nazivQ;

    naziv=ui->comboBox->currentText();

    var=new QSqlQueryModel;

    //FILTRIRANJE U COMBOBOX
    //FILTRIRANJE U COMBOBOX

    if(naziv=="BIZNIS KLASA"){nazivQ="SELECT ime,prezime,id_sjedista,naziv_klase FROM ispisi_Zauzeta_Sjedista where naziv_klase='Biznis klasa'";}
    else if (naziv=="PRVA KLASA")

    {nazivQ="SELECT ime,prezime,id_sjedista,naziv_klase FROM ispisi_Zauzeta_Sjedista where naziv_klase='Prva klasa'";}
    else
        if(naziv=="EKONOMSKA KLASA")
        {nazivQ="SELECT ime,prezime,id_sjedista,naziv_klase FROM ispisi_Zauzeta_Sjedista where naziv_klase='Ekonomska klasa'";
    }
    else {nazivQ="SELECT ime,prezime,id_sjedista,naziv_klase FROM ispisi_Zauzeta_Sjedista";}

    var->setQuery(nazivQ);
        ui->tableView->setModel(var);
        ui->tableView->resizeRowsToContents();
}


