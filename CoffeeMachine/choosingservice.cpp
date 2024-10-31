#include "choosingservice.h"
#include "ui_choosingservice.h"
#include "mediator.h"

ChoosingService::ChoosingService(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoosingService)
    , mediator(nullptr)
{
    ui->setupUi(this);
}

ChoosingService::~ChoosingService()
{
    delete ui;
}

void ChoosingService::setMediator(Mediator* mediator){
    this->mediator=mediator;
}

void ChoosingService::on_backToChoosingRoleButton_clicked()
{
    mediator->openWindowRoli();
}


void ChoosingService::on_goToRefillingProductsButton_clicked()
{
    mediator->openWindowProducts();
}


void ChoosingService::on_goToSettingPricesButton_clicked()
{
    mediator->openWindowPriceSetting();
}

