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

void OrdersHistory::fillTable(QVector<Order> orders){
    // qDebug() << 2;
    ui->orderTable->setRowCount(orders.size());
    for(int row = 0; row < orders.size(); row++){
        Order order = orders[row];
        // qDebug() << order.dateTime.toString();

        QTableWidgetItem *item1 = new QTableWidgetItem(QString::number(order.id));
        ui->orderTable->setItem(row, 0, item1);
        QTableWidgetItem *item2 = new QTableWidgetItem(mediator->getRecipeName(order.recipe_id));
        // qDebug() << order.dateTime.toString("hh:mm:ss dd.MM.yyyy");
        ui->orderTable->setItem(row, 1, item2);
        QTableWidgetItem *item3 = new QTableWidgetItem(order.dateTime.toString("hh:mm:ss dd.MM.yyyy"));
        ui->orderTable->setItem(row, 2, item3);
        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(order.drinkSize));
        ui->orderTable->setItem(row, 3, item4);
        QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(order.sugarAmount));
        ui->orderTable->setItem(row, 4, item5);
        QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(order.totalPrice));
        ui->orderTable->setItem(row, 5, item6);

        ui->orderTable->resizeColumnsToContents();
    }
}

