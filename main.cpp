#include "mainwindow.h"
#include <menu.h>
#include <QApplication>
#include <QDebug>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // QFile styleSheetFile("C:\\Users\tarik\\Documents\\FinalniProjekat\\SyNet.qss");
  //  styleSheetFile.open(QFile::ReadOnly);
  //  QString styleSheet=QLatin1String(styleSheetFile.readAll());
 //   a.setStyleSheet(styleSheet);
    MainWindow w;
    w.show();

    return a.exec();


}
