#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QEvent>

class my_label : public QLabel
{
    Q_OBJECT
public:
    explicit  my_label(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *ev );

signals:
   void Mouse_Pressed();

};

#endif // MY_LABEL_H
