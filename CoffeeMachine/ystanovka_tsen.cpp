#include "ystanovka_tsen.h"
#include "ui_ystanovka_tsen.h"

Ystanovka_tsen::Ystanovka_tsen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ystanovka_tsen)
{
    ui->setupUi(this);
}

Ystanovka_tsen::~Ystanovka_tsen()
{
    delete ui;
}
