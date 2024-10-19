#include "newform.h"
#include "ui_newform.h"

newForm::newForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newForm)
{
    ui->setupUi(this);
}

newForm::~newForm()
{
    delete ui;
}
