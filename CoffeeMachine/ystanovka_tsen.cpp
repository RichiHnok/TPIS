#include "ystanovka_tsen.h"
#include "ui_ystanovka_tsen.h"

Ystanovka_tsen::Ystanovka_tsen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ystanovka_tsen)
    , mediator(nullptr)
{
    ui->setupUi(this);
}

Ystanovka_tsen::~Ystanovka_tsen()
{
    delete ui;
}

void Ystanovka_tsen::setMediator(Mediator *mediator){
    this->mediator = mediator;
}
void Ystanovka_tsen::on_backToChoosingServiceButton_clicked()
{
    mediator->openWindowChoosingService();
}

