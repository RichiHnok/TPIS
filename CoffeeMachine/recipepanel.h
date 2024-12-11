#ifndef RECIPEPANEL_H
#define RECIPEPANEL_H

#include <QWidget>
#include <QString>
#include "recipe.h"

namespace Ui {
class RecipePanel;
}

class RecipePanel : public QWidget
{
    Q_OBJECT

public:
    explicit RecipePanel(QWidget *parent = nullptr);
    explicit RecipePanel();
    ~RecipePanel();

    void setRecipe(Recipe recipe);

    void setId(int id);
    void setDrinkName(QString drinkName);
    void setWaterAmountTextField(double waterAmount);
    void setCoffeeAmountTextField(double coffeeAmount);
    void setMilkAmountTextField(double milkAmount);
    void setCreamAmountTextField(double creamAmount);

    int panelNumber;

private:
    Ui::RecipePanel *ui;

signals:
    void deleteThisRecipe(int);
private slots:
    void on_deleteRecipeButton_clicked();
    void on_saveRecipeButton_clicked();
};

#endif // RECIPEPANEL_H
