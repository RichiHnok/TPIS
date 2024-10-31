#ifndef ORDERSHISTORY_H
#define ORDERSHISTORY_H

#include "mediator.h"
#include <QWidget>

namespace Ui {
class OrdersHistory;
}

class OrdersHistory : public QWidget
{
    Q_OBJECT

public:
    explicit OrdersHistory(QWidget *parent = nullptr);
    ~OrdersHistory();
    void setMediator(Mediator* mediator);

private slots:
    void on_backToChoosingServiceButton_clicked();

private:
    Ui::OrdersHistory *ui;
    Mediator* mediator;
};

#endif // ORDERSHISTORY_H
