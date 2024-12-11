#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QImage>

class Recipe
{
public:
    //TODO конструктор
    Recipe();

    QString toString();

    int id;
    QString drinkName;
    double coffeeAmount;
    double waterAmount;
    double milkAmount;
    double creamAmount;
    QImage *drinkImageData;
    QString recipeStatus;
};

#endif // RECIPE_H
