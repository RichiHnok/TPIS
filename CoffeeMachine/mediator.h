#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "roli.h"
#include "choosingservice.h"
#include "products.h"
#include "ystanovka_tsen.h"
#include <iostream>

#include <QWidget>

class Roli;
class ChoosingService;
class Products;
class Ystanovka_tsen;

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

signals:

private:
    Roli *roliW;
    ChoosingService *choosingServiceW;
    Products *productsW;
    Ystanovka_tsen *priceSettingW;
};

#endif // MEDIATOR_H
