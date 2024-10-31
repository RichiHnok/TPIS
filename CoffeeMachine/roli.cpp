#include "roli.h"
#include "ui_roli.h"
#include "mediator.h"

Roli::Roli(QWidget *parent):
    QWidget(parent),
    ui(new Ui::Roli),
    mediator(nullptr)
    // choosingService(new ChoosingService)
{
    ui->setupUi(this);
}

Roli::~Roli()
{
    delete ui;
    // delete choosingService;
}

void Roli::setMediator(Mediator* mediator){
    this->mediator=mediator;
}


void Roli::on_pushButton_3_clicked()
{
    mediator->closeWindowRoli();
}


void Roli::on_openServiceButton_clicked()
{
    mediator->openWindowChoosingService();
}


void Roli::on_openClientButton_clicked()
{
    mediator->openWindowCoffee();
}

