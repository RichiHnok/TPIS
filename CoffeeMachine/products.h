// products.h
#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "mediator.h"
#include <QWidget>
#include <iostream>

using namespace std;

namespace Ui {
class Products;
}

class Products : public QWidget
{
    Q_OBJECT

public:
    explicit Products(QWidget *parent = nullptr);
    ~Products();
    void setMediator(Mediator* mediator);

    // Добавляем переменные для хранения значений продуктов и их максимумов
    int water = 0, maxWater = 10;
    int coffee = 0, maxCoffee = 2;
    int sugar = 0, maxSugar = 2;
    int milk = 0, maxMilk = 5;
    int syrup = 0, maxSyrup = 1;

    // Добавляем слоты для обработки нажатия на кнопки "Пополнить"
    void set_water_current_label(double waterAmount);
    void set_cofe_current_label(double cofeAmount);
    void set_sugar_current_label(double sugarAmount);
    void set_milk_current_label(double milkAmount);
    void set_slivki_current_label(double slivkiAmount);

    void on_buttonFillWater_clicked();
    //void on_buttonFillCoffee_clicked();
    // void on_buttonFillSugar_clicked();
    // void on_buttonFillMilk_clicked();
    // void on_buttonFillSyrup_clicked();

private slots:
    void on_refillWaterButton_clicked();

    void on_refillCofeButton_clicked();

    void on_refillSugarButton_clicked();

    void on_refillMilkButton_clicked();

    void on_refillSlivkiButton_clicked();

    void on_backToChoosingServiceWindowButton_clicked();

private:
    Ui::Products *ui;
    Mediator* mediator;
};

#endif // PRODUCTS_H
