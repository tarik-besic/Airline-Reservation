#ifndef WIDGETT_H
#define WIDGETT_H

#include <QWidget>
#include <QEvent>
#include <QDebug>

namespace Ui {
class widgett;
}

class widgett : public QWidget
{
    Q_OBJECT

public:
    explicit widgett(QWidget *parent = nullptr);
    ~widgett();
    bool event(QEvent* ev) override
        {
            if (ev->) {
                // overwrite handling of PolishRequest if any
                doThings();
                return true;
            } else  if (ev->type() == QEvent::Show) {
                // complement handling of Show if any
                doThings2();
                QWidget::event(ev);
                return true;
            }
            // Make sure the rest of events are handled
            return QWidget::event(ev);
        }

private:
    Ui::widgett *ui;
    void key
};

#endif // WIDGETT_H
