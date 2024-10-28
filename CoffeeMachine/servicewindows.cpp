#include "servicewindows.h"
#include "ui_servicewindows.h"

ServiceWindows::ServiceWindows(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServiceWindows)
{
    ui->setupUi(this);
}

ServiceWindows::~ServiceWindows()
{
    delete ui;
}
