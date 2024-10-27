#include "roli.h"
#include "ui_roli.h"

Roli::Roli(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Roli)
{
    ui->setupUi(this);
}

Roli::~Roli()
{
    delete ui;
}
