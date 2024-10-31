#include "mediator.h"

#include <iostream>

using namespace std;
// Замечания
// Все поля объекта при его создании нужно инициализировать в конструкторе
// При удалении объекта, удалять его насовсем
// При создании объекта присваивать в медиаторе соответствующему полю указатель на него, а тому объекту - указатель на медиатор

Mediator::Mediator() :
    roliW(nullptr),
    choosingServiceW(nullptr),
    productsW(nullptr),
    priceSettingW(nullptr),
    recipesEditorW(nullptr),
    ordersHistoryW(nullptr)
{
    cout<<"Mediator's constructor launched"<<endl;
    openWindowRoli();
}

void Mediator::setRoli(Roli* roliW){
    this->roliW=roliW;
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

void Mediator::setChoosingService(ChoosingService *choosingService){
    this->choosingServiceW=choosingService;
}

void Mediator::openWindowChoosingService(){
    if(roliW != nullptr){
        closeWindowRoli();
    }
    if(productsW != nullptr){
        closeWindowProducts();
    }
    if(priceSettingW != nullptr){
        closeWindowPriceSetting();
    }
    if(recipesEditorW != nullptr){
        closeWindowRecipesEditor();
    }
    if(ordersHistoryW != nullptr){
        closeWindowOrdersHistory();
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

void Mediator::setProducts(Products *products){
    this->productsW = products;
}

void Mediator::openWindowProducts(){
    closeWindowChoosingService();
    setProducts(new Products);
    productsW->setMediator(this);
    productsW->show();
}

void Mediator::closeWindowProducts(){
    productsW->setAttribute(Qt::WA_DeleteOnClose, true);
    productsW->close();
    productsW = nullptr;
}

void Mediator::setPriceSetting(Ystanovka_tsen *priceSetting){
    this->priceSettingW = priceSetting;
}

void Mediator::openWindowPriceSetting(){
    closeWindowChoosingService();
    setPriceSetting(new Ystanovka_tsen);
    priceSettingW->setMediator(this);
    priceSettingW->show();
}

void Mediator::closeWindowPriceSetting(){
    priceSettingW->setAttribute(Qt::WA_DeleteOnClose, true);
    priceSettingW->close();
    priceSettingW = nullptr;
}

void Mediator::setRecipesEditor(RecipesEditor *recipesEditor){
    this->recipesEditorW = recipesEditor;
}

void Mediator::openWindowRecipesEditor(){
    closeWindowChoosingService();
    setRecipesEditor(new RecipesEditor);
    recipesEditorW->setMediator(this);
    recipesEditorW->show();
}

void Mediator::closeWindowRecipesEditor(){
    recipesEditorW->setAttribute(Qt::WA_DeleteOnClose, true);
    recipesEditorW->close();
    recipesEditorW = nullptr;
}

void Mediator::setOrdersHistory(OrdersHistory *ordersHistory){
    this->ordersHistoryW = ordersHistory;
}

void Mediator::openWindowOrdersHistory(){
    closeWindowChoosingService();
    setOrdersHistory(new OrdersHistory);
    ordersHistoryW->setMediator(this);
    ordersHistoryW->show();
}

void Mediator::closeWindowOrdersHistory(){
    ordersHistoryW->setAttribute(Qt::WA_DeleteOnClose, true);
    ordersHistoryW->close();
    ordersHistoryW = nullptr;
}

void Mediator::printSmth(){
    std::cout<<"test"<<std::endl;
}

