#ifndef IZBOR_SJEDISTA_H
#define IZBOR_SJEDISTA_H

#include <QDialog>

namespace Ui {
class Izbor_Sjedista;
}

class Izbor_Sjedista : public QDialog
{
    Q_OBJECT

public:
    explicit Izbor_Sjedista(QWidget *parent = nullptr);
    ~Izbor_Sjedista();

private:
    Ui::Izbor_Sjedista *ui;
};

#endif // IZBOR_SJEDISTA_H
