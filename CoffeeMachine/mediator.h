#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "roli.h"
#include "choosingservice.h"
#include "products.h"
#include "ystanovka_tsen.h"
#include "recipeseditor.h"
#include "ordershistory.h"
#include "form.h"
#include "databasemanager.h"
#include "order.h"
#include "recipe.h"
#include "recipepanel.h"
#include <iostream>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QString>
#include <QWidget>
#include <QVector>
#include <QByteArray>
#include <QBuffer>
#include <QIODevice>

class Roli;
class ChoosingService;
class Products;
class Ystanovka_tsen;
class RecipesEditor;
class OrdersHistory;
class Form;
class DatabaseManager;

class Mediator
{
public:
    explicit Mediator();
    void createDatabaseConnection();
    void closeDatabaseConnection();
    void putOrder(Order order); // TODO
    void getOrder(); // TODO
    QVector<Order> getAllOrders(); //TODO
    Recipe getRecipe(int recipeId); // TODO
    QString getRecipeName(int recipeId);
    QVector<Recipe> getAllRecipes(); // TODO
    void putRecipe(Recipe recipe); // TODO
    void removeRecipe(); // TODO

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

    void setCurrentWaterAmount(double newWaterAmount);
    void setCurrentCoffeeAmount(double newCoffeeAmount);
    void setCurrentSugarAmount(double newSugarAmount);
    void setCurrentMilkAmount(double newMilkAmount);
    void setCurrentSlivkiAmount(double newSlivkiAmount);

    double currentWaterAmount;
    double currentCofeAmount;
    double currentSugarAmount;
    double currentMilkAmount;
    double currentSlivkiAmount;

    double maxWaterAmount = 10;
    double maxCofeAmount=2;
    double maxSugarAmount=2;
    double maxMilkAmount=5;
    double maxSlivkiAmount=1;

    QVector<Recipe> recipesList;
signals:

private:
    Roli *roliW;
    ChoosingService *choosingServiceW;
    Products *productsW;
    Ystanovka_tsen *priceSettingW;
    RecipesEditor *recipesEditorW;
    OrdersHistory *ordersHistoryW;
    Form *formW;
    DatabaseManager *dbManager;
};

#endif // MEDIATOR_H
