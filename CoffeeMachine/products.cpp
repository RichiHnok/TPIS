#include "products.h"
#include "ui_products.h"

Products::Products(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Products)
{
    ui->setupUi(this);
}

Products::~Products()
{
    delete ui;
}

void Products::setMediator(Mediator* mediator){
    this->mediator=mediator;
}

void Products::on_backToChoosingServiceWindowButton_clicked()
{
    mediator->openWindowChoosingService();
}

