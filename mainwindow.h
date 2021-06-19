#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QDebug>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlTableModel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();



private slots:
    void Mouse_Pressed( );
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();






    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_comboBox_activated(int index);





private:
    Ui::MainWindow *ui;
    QSqlQueryModel *var;
    QSqlTableModel *model;

    void postaviLabele();

};
#endif // MAINWINDOW_H
