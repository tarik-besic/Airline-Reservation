#ifndef KONK_H
#define KONK_H

#include <QDebug>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
static void konekcija()
{


  QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName("D:/projects/FinalniProjekat/fprojekat.db");
    db.open();

}




int nekaFunk(QString name)
{
    QString im; //zelim samo broj u im
       int id;
       if(name.size()==7) //ako je jednocifren broj
        im= name.right(1); // uzimam 1 slovo sa desne strane
       else  im= name.right(2);  //ako je dvocifren broj uzimam 2 slova

        id=im.toInt();
        return id;
}

#endif // KONK_H
