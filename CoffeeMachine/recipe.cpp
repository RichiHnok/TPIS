#include "recipe.h"

Recipe::Recipe() {}

QString Recipe::toString(){
    QString info = QString("recipe: "
                                "[%0, %1, %2, %3, %4]").
                        arg(drinkName).
                        arg(coffeeAmount).
                        arg(waterAmount).
                        arg(milkAmount).
                        arg(creamAmount);
    return info;
}
