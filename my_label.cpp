#include "my_label.h"
#include <mainwindow.h>

my_label::my_label(QWidget *parent):QLabel(parent)
{

}

void my_label::mousePressEvent(QMouseEvent *ev )
{

    emit Mouse_Pressed();


}
