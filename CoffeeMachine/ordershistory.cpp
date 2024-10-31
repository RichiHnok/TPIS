#include "ordershistory.h"
#include "ui_ordershistory.h"

OrdersHistory::OrdersHistory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrdersHistory)
{
    ui->setupUi(this);
}

OrdersHistory::~OrdersHistory()
{
    delete ui;
}
