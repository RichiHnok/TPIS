#include "recipepanel.h"
#include "ui_recipepanel.h"

RecipePanel::RecipePanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecipePanel)
{
    ui->setupUi(this);
    panelNumber = 0;
}

RecipePanel::RecipePanel(){

}

RecipePanel::~RecipePanel()
{
    delete ui;
}

void RecipePanel::setRecipe(Recipe recipe){
    setId(recipe.id);
    setDrinkName(recipe.drinkName);
    setWaterAmountTextField(recipe.waterAmount);
    setCoffeeAmountTextField(recipe.coffeeAmount);
    setMilkAmountTextField(recipe.milkAmount);
    setCreamAmountTextField(recipe.creamAmount);
}

void RecipePanel::setId(int id){
    panelNumber = id;
}

void RecipePanel::setDrinkName(QString drinkName){
    ui->drinkNameTextField->setText(drinkName);
}

void RecipePanel::setWaterAmountTextField(double waterAmount){
    ui->waterAmountTextField->setText(QString::number(waterAmount));
}

void RecipePanel::setCoffeeAmountTextField(double coffeeAmount){
    ui->coffeeAmountTextField->setText(QString::number(coffeeAmount));
}

void RecipePanel::setMilkAmountTextField(double milkAmount){
    ui->milkAmountTextField->setText(QString::number(milkAmount));
}

void RecipePanel::setCreamAmountTextField(double creamAmount){
    ui->creamAmountTextField->setText(QString::number(creamAmount));
}

void RecipePanel::on_deleteRecipeButton_clicked()
{
    emit deleteThisRecipe(panelNumber);
    this->close();
}


void RecipePanel::on_saveRecipeButton_clicked()
{

}

