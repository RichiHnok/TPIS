#include "recipepanel.h"
#include "ui_recipepanel.h"

RecipePanel::RecipePanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecipePanel)
{
    ui->setupUi(this);
}

RecipePanel::~RecipePanel()
{
    delete ui;
}
