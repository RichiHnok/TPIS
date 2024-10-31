#include "form.h"
#include "ui_form.h"
#include "mediator.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
    , mediator(nullptr)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::setMediator(Mediator* mediator){
    this->mediator=mediator;
}

void Form::on_backToChoosingRoleButton_clicked()
{
    mediator->openWindowRoli();
}

