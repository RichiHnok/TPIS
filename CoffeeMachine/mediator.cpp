#include "mainwindow.h"
#include "recipeseditor.h"
#include "roli.h"
#include "mediator.h"

#include <iostream>

using namespace std;
// Замечания
// Все поля объекта при его создании нужно инициализировать в конструкторе
// При удалении объекта, удалять его насовсем
// При создании объекта присваивать в медиаторе соответствующему полю указатель на него, а тому объекту - указатель на медиатор

Mediator::Mediator() :
    roliW(nullptr),
    choosingServiceW(nullptr)
{
    cout<<"Mediator's constructor launched"<<endl;
    openWindowRoli();
}

void Mediator::setRoli(Roli* roliW){
    this->roliW=roliW;
}

void Mediator::setChoosingService(ChoosingService *choosingService){
    this->choosingServiceW=choosingService;
}

void Mediator::openWindowRoli(){
    if(choosingServiceW != nullptr){
        closeWindowChoosingService();
    }
    setRoli(new Roli);
    roliW->setMediator(this);
    roliW->show();
}

void Mediator::closeWindowRoli(){
    roliW->setAttribute(Qt::WA_DeleteOnClose, true);
    roliW->close();
    roliW = nullptr;
}

void Mediator::openWindowChoosingService(){
    if(roliW != nullptr){
        closeWindowRoli();
    }
    setChoosingService(new ChoosingService);
    choosingServiceW->setMediator(this);
    choosingServiceW->show();
}

void Mediator::closeWindowChoosingService(){
    choosingServiceW->setAttribute(Qt::WA_DeleteOnClose, true);
    choosingServiceW->close();
    choosingServiceW = nullptr;
}

void Mediator::printSmth(){
    std::cout<<"test"<<std::endl;
}

