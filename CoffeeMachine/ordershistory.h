#ifndef ORDERSHISTORY_H
#define ORDERSHISTORY_H

#include "mediator.h"
#include "order.h"
#include <QWidget>
#include <QVector>
#include <QTableWidgetItem>

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
    void fillTable(QVector<Order> orders);

private slots:
    void on_backToChoosingServiceButton_clicked();


private:
    Ui::OrdersHistory *ui;
    Mediator* mediator;
};

#endif // ORDERSHISTORY_H
