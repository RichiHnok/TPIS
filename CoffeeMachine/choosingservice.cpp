#include "choosingservice.h"
#include "ui_choosingservice.h"

ChoosingService::ChoosingService(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ChoosingService)
{
    ui->setupUi(this);
}

ChoosingService::~ChoosingService()
{
    delete ui;
}
