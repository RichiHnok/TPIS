#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "roli.h"
#include "choosingservice.h"
#include "products.h"
#include "ystanovka_tsen.h"
#include "recipeseditor.h"
#include "ordershistory.h"
#include "form.h"
#include <iostream>

#include <QWidget>

class Roli;
class ChoosingService;
class Products;
class Ystanovka_tsen;
class RecipesEditor;
class OrdersHistory;
class Form;

class Mediator
{
public:
    explicit Mediator();
    void printSmth();
    void setRoli(Roli* roli);
    void openWindowRoli();
    void closeWindowRoli();
    void setChoosingService(ChoosingService* choosingService);
    void openWindowChoosingService();
    void closeWindowChoosingService();
    void setProducts(Products* products);
    void openWindowProducts();
    void closeWindowProducts();
    void setPriceSetting(Ystanovka_tsen* priceSetting);
    void openWindowPriceSetting();
    void closeWindowPriceSetting();
    void setRecipesEditor(RecipesEditor* recipesEditor);
    void openWindowRecipesEditor();
    void closeWindowRecipesEditor();
    void setOrdersHistory(OrdersHistory* ordersHistory);
    void openWindowOrdersHistory();
    void closeWindowOrdersHistory();
    void setForm(Form* form);
    void openWindowCoffee();
    void closeWindowCoffee();

signals:

private:
    Roli *roliW;
    ChoosingService *choosingServiceW;
    Products *productsW;
    Ystanovka_tsen *priceSettingW;
    RecipesEditor *recipesEditorW;
    OrdersHistory *ordersHistoryW;
    Form *formW;
};

#endif // MEDIATOR_H
