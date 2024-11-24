#ifndef ORDER_H
#define ORDER_H

#include <QDateTime>

class Order
{
public:
    Order();

    int id;
    int recipe_id;
    QDateTime dateTime;
    int drinkSize;
    int sugarAmount;
    double totalPrice;

};

#endif // ORDER_H
