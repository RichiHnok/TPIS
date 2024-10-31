#ifndef ORDERSHISTORY_H
#define ORDERSHISTORY_H

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

private:
    Ui::OrdersHistory *ui;
};

#endif // ORDERSHISTORY_H
