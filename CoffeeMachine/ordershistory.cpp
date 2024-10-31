#include "ordershistory.h"
#include "ui_ordershistory.h"

OrdersHistory::OrdersHistory(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::OrdersHistory)
    , mediator(nullptr)
{
    ui->setupUi(this);
}

OrdersHistory::~OrdersHistory()
{
    delete ui;
}

void OrdersHistory::setMediator(Mediator *mediator){
    this->mediator=mediator;
}

void OrdersHistory::on_backToChoosingServiceButton_clicked()
{
    mediator->openWindowChoosingService();
}

