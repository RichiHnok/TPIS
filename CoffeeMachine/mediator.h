#ifndef MEDIATOR_H
#define MEDIATOR_H

#include "roli.h"
#include "choosingservice.h"
#include <iostream>

#include <QWidget>

class Roli;
class ChoosingService;

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
    // void set

signals:

private:
    Roli *roliW;
    ChoosingService *choosingServiceW;
    // ChoosingService *choosingserviceW;
};

#endif // MEDIATOR_H
