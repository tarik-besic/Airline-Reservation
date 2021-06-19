#ifndef MENU_H
#define MENU_H
#include <QDialog>
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlQuery>
namespace Ui {
class Menu;
}
class Menu : public QDialog
{
    Q_OBJECT
public:
    explicit Menu(QString name,QWidget *parent = nullptr);
    ~Menu();
private slots:
    void on_pushButton_3_clicked();
private:
    Ui::Menu *ui;
    QSqlQueryModel *var;
    QSqlQueryModel *var2;
    QSqlTableModel *model;
};
#endif // MENU_H
