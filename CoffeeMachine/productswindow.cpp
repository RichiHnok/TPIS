#include "productswindow.h"
#include "ui_productswindow.h"

ProductsWindow::ProductsWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProductsWindow)
{
    ui->setupUi(this);
}

ProductsWindow::~ProductsWindow()
{
    delete ui;
}
