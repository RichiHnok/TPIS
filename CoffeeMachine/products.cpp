// products.cpp
#include "products.h"
#include "ui_products.h"

Products::Products(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Products)
    , mediator(nullptr)
{
    ui->setupUi(this);
}

Products::~Products()
{
    delete ui;
}

void Products::setMediator(Mediator* mediator){
    this->mediator = mediator;
}

void Products::on_backToChoosingServiceWindowButton_clicked()
{
    mediator->openWindowChoosingService();
}

void Products::set_water_current_label(double waterAmount)
{
    ui->water_current_litr_label->setText(QString::number(waterAmount));
    ui->water_current_amound_persent->setText(QString::number(waterAmount/mediator->maxWaterAmount*100));
}

void Products::set_cofe_current_label(double cofeAmount)
{
    ui->cofe_current_litr_label->setText(QString::number(cofeAmount));
    ui->cofe_current_amound_persent->setText(QString::number(cofeAmount/mediator->maxCofeAmount*100));
}

void Products::set_sugar_current_label(double sugarAmount)
{
    ui->sugar_current_litr_label->setText(QString::number(sugarAmount));
    ui->sugar_current_amound_persent->setText(QString::number(sugarAmount/mediator->maxSugarAmount*100));
}

void Products::set_milk_current_label(double milkAmount)
{
    ui->milk_current_litr_label->setText(QString::number(milkAmount));
    ui->milk_current_amound_persent->setText(QString::number(milkAmount/mediator->maxMilkAmount*100));
}

void Products::set_slivki_current_label(double slivkiAmount)
{
    ui->slivki_current_litr_label->setText(QString::number(slivkiAmount));
    ui->slivki_current_amound_persent->setText(QString::number(slivkiAmount/mediator->maxSlivkiAmount*100));
}

// void Products::on_buttonFillCoffee_clicked()
// {
//     coffee = maxCoffee;
//     ui->coffeeSpinBox->setValue(coffee);
// }

// void Products::on_buttonFillSugar_clicked()
// {
//     sugar = maxSugar;
//     ui->sugarSpinBox->setValue(sugar);
// }

// void Products::on_buttonFillMilk_clicked()
// {
//     milk = maxMilk;
//     ui->milkSpinBox->setValue(milk);
// }

// void Products::on_buttonFillSyrup_clicked()
// {
//     syrup = maxSyrup;
//     ui->syrupSpinBox->setValue(syrup);
// }

void Products::on_refillWaterButton_clicked()
{
    set_water_current_label(mediator->maxWaterAmount);
}


void Products::on_refillCofeButton_clicked()
{
    set_cofe_current_label(mediator->maxCofeAmount);
}


void Products::on_refillSugarButton_clicked()
{
    set_sugar_current_label(mediator->maxSugarAmount);
}


void Products::on_refillMilkButton_clicked()
{
    set_milk_current_label(mediator->maxMilkAmount);
}


void Products::on_refillSlivkiButton_clicked()
{
    set_slivki_current_label(mediator->maxSlivkiAmount);
}

