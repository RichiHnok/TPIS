#include "coffee.h"
#include "ui_coffee.h"

coffee::coffee(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::coffee)
{
    ui->setupUi(this);
}

coffee::~coffee()
{
    delete ui;
}
