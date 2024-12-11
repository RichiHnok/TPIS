#include "mediator.h"

#include "order.h"
#include <iostream>
#include <QString>
#include <QVariant>

using namespace std;
// Замечания
// Все поля объекта при его создании нужно инициализировать в конструкторе
// При удалении объекта, удалять его насовсем
// При создании объекта присваивать в медиаторе соответствующему полю указатель на него, а тому объекту - указатель на медиатор /////

Mediator::Mediator() :
    roliW(nullptr),
    choosingServiceW(nullptr),
    productsW(nullptr),
    priceSettingW(nullptr),
    recipesEditorW(nullptr),
    ordersHistoryW(nullptr),
    formW(nullptr),
    dbManager(nullptr)
{
    cout<<"Mediator's constructor launched"<<endl;
    createDatabaseConnection();
    openWindowRoli();
    currentWaterAmount=0;
    currentCofeAmount=0;
    currentSugarAmount=0;
    currentMilkAmount=0;
    currentSlivkiAmount=0;

    qDebug() << 1;
    recipesList = getAllRecipes();
    qDebug() << 2;
    for(int i = 0, n = recipesList.size(); i < n; i++){
        qDebug() << recipesList[i].toString();
    }
}

void Mediator::createDatabaseConnection(){
    this->dbManager = new DatabaseManager;
    dbManager->openDatabase();
}

void Mediator::closeDatabaseConnection(){
    dbManager->closeDatabase();
    dbManager = (nullptr);
}

void Mediator::putOrder(Order order){
    //TODO Можно исправить испульзуя у query мутоды prepare и bindValues
    QString queryText = QString("insert into orders (recipe_id, date, size, sugar_amount, total_price) values (%1, %2, %3, %4, %5)")
                            .arg(order.recipe_id)
                            .arg(order.dateTime.toString("hh:mm:ss dd.MM.yyyy"))
                            .arg(order.drinkSize)
                            .arg(order.sugarAmount)
                            .arg(order.totalPrice);
    QSqlQuery query;
    if (!query.exec(queryText)) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

}

void Mediator::getOrder(){

}

QVector<Order> Mediator::getAllOrders(){
    QString timeFormat = "hh:mm:ss dd.MM.yyyy";
    QString queryText = "SELECT * FROM orders";
    QSqlQuery query;
    if (!query.exec(queryText)) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        throw std::invalid_argument( "something went wrong");
    }
    QVector<Order> ordersList;

    //TODO Сделать создание рецептов и запихивание их в список
    while (query.next()) {
        int id = query.value(0).toInt();
        int recipe_id = query.value(1).toInt(); //TODO Сделать подстановку названия напитка
        // qDebug() << query.value(2);
        // qDebug() << query.value(2).toString();
        // qDebug() << QDateTime::fromString(query.value(2).toString(), timeFormat);
        // QDateTime dateTime = query.value(2).to;
        QDateTime dateTime = QDateTime::fromString(query.value(2).toString(), timeFormat);
        int drinkSize = query.value(3).toInt();
        int sugarAmount = query.value(4).toInt();
        double totalPrice = query.value(5).toDouble();

        Order tempOrder;
        tempOrder.id = id;
        tempOrder.recipe_id = recipe_id;
        tempOrder.dateTime = dateTime;
        // qDebug() << tempOrder.dateTime;
        // qDebug() << tempOrder.dateTime.toString();
        tempOrder.drinkSize = drinkSize;
        tempOrder.sugarAmount = sugarAmount;
        tempOrder.totalPrice = totalPrice;

        ordersList.append(tempOrder);
    }
    // qDebug() << 1;
    return ordersList;
}

Recipe Mediator::getRecipe(int recipeId){
    // QString queryText = QString("SELECT * FROM recipes where id = %1").arg(recipeId);
    // QSqlQuery query;
    // if (!query.exec(queryText)) {
    //     qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
    //     throw std::invalid_argument( "something went wrong");
    // }
    Recipe res;
    // res.id = query.value(0);
    return res;
}

QString Mediator::getRecipeName(int recipeId){
    QString queryText = QString("SELECT name FROM recipes where id = %1").arg(recipeId);
    QSqlQuery query;
    if (!query.exec(queryText)) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        throw std::invalid_argument( "something went wrong");
    }
    // qDebug() << qu;
    query.next();
    return query.value(0).toString();
}

QVector<Recipe> Mediator::getAllRecipes(){

    QString queryText = "SELECT * FROM recipes";
    QSqlQuery query;
    if (!query.exec(queryText)) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        throw std::invalid_argument( "something went wrong");
    }
    QVector<Recipe> recipesList;
    //TODO Сделать создание рецептов и запихивание их в список
    while (query.next()) {
    //     QString recipeStatus = query.value(7).toString();
    //     if(recipeStatus == "removed"){
    //         continue;
    //     }
        int id = query.value(0).toInt();
        QString drinkName = query.value(1).toString();
        double coffeeAmount = query.value(2).toDouble();
        double waterAmount = query.value(3).toDouble();
        double milkAmount = query.value(4).toDouble();
        double creamAmount = query.value(5).toDouble();
    //     QByteArray byteArray = query.value(6).toByteArray();
    //     QImage *drinkImage;
    //     drinkImage->loadFromData(byteArray);

        Recipe tempRecipe;
        tempRecipe.id = id;
        tempRecipe.drinkName = drinkName;
        tempRecipe.coffeeAmount = coffeeAmount;
        tempRecipe.waterAmount = waterAmount;
        tempRecipe.milkAmount = milkAmount;
        tempRecipe.creamAmount = creamAmount;
        // tempRecipe.drinkImageData = drinkImage;
    //     tempRecipe.recipeStatus = recipeStatus;

        recipesList.append(tempRecipe);
    //     // int id = query.value(0).toInt();
        qDebug() << "ID:" << id << ", Name:" << drinkName;
    }
    return recipesList;
}

void Mediator::putRecipe(Recipe recipe){
    QString queryText = QString("insert into recipes"
                        "(name, coffee_amount, water_amount, milk_amount, cream_amount, drink_image, recipe_status) values"
                        "(%0, %1, %2, %3, %4, :bytes, %5)").
                        arg(recipe.drinkName).
                        arg(recipe.coffeeAmount).
                        arg(recipe.waterAmount).
                        arg(recipe.milkAmount).
                        arg(recipe.creamAmount).
                        arg(recipe.recipeStatus);

    // queryText.arg(recipe.drinkName).arg(recipe.coffeeAmount).arg(recipe.waterAmount).arg(recipe.milkAmount).arg(recipe.creamAmount);

    QSqlQuery query(dbManager->db);
    query.prepare(queryText);
    QByteArray byteArrayOfImage;
    QBuffer buffer(&byteArrayOfImage);
    buffer.open(QIODevice::WriteOnly);
    recipe.drinkImageData->save(&buffer, "PNG");
    query.bindValue(":bytes", byteArrayOfImage);

    // query.prepare("insert into recipes (name, coffee_amount, water_amount, milk_amount, cream_amount, drink_image, recipe_status) values (:name, :coffee_amount, :water_amount, :milk_amount, :cream_amount, :drink_image, :recipe_status)");

    // query.bindValue(":name", recipe.drinkName);
    // query.bindValue(":coffee_amount", recipe.coffeeAmount);
    // query.bindValue(":water_amount", recipe.waterAmount);
    // query.bindValue(":milk_amount", recipe.milkAmount);
    // query.bindValue(":cream_amount", recipe.creamAmount);



    query.exec(queryText);
    return;
    // query.bindValue(":drink_image", byteArrayOfImage);

    // query.bindValue(":recipe_status", recipe.recipeStatus);
}

void Mediator::removeRecipe(){

}

void Mediator::setRoli(Roli* roliW){
    this->roliW=roliW;
}

void Mediator::openWindowRoli(){
    if(choosingServiceW != nullptr){
        closeWindowChoosingService();
    }
    if(formW != nullptr){
        closeWindowCoffee();
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
    cout<<"opening choosing service"<<endl;
    if(roliW != nullptr){
        closeWindowRoli();
    }
    if(productsW != nullptr){
        cout<<"launching closing of products"<<endl;
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

    productsW->set_water_current_label(currentWaterAmount);
    productsW->set_cofe_current_label(currentCofeAmount);
    productsW->set_sugar_current_label(currentSugarAmount);
    productsW->set_milk_current_label(currentMilkAmount);
    productsW->set_slivki_current_label(currentSlivkiAmount);
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

    recipesEditorW->showRecipes(recipesList);
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
    ordersHistoryW->OrdersHistory::fillTable(Mediator::getAllOrders());
}

void Mediator::closeWindowOrdersHistory(){
    ordersHistoryW->setAttribute(Qt::WA_DeleteOnClose, true);
    ordersHistoryW->close();
    ordersHistoryW = nullptr;
}

void Mediator::setForm(Form* form){
    this->formW = form;
}

void Mediator::openWindowCoffee(){
    closeWindowRoli();
    setForm(new Form);
    formW->setMediator(this);
    formW->show();
}

void Mediator::closeWindowCoffee(){
    formW->setAttribute(Qt::WA_DeleteOnClose, true);
    formW->close();
    formW = nullptr;
}

void Mediator::setCurrentWaterAmount(double newWaterAmount){
    currentWaterAmount = newWaterAmount;
}

void Mediator::setCurrentCoffeeAmount(double newCoffeeAmount){
    currentCofeAmount = newCoffeeAmount;
}

void Mediator::setCurrentSugarAmount(double newSugarAmount){
    currentSugarAmount = newSugarAmount;
}

void Mediator::setCurrentMilkAmount(double newMilkAmount){
    currentMilkAmount = newMilkAmount;
}

void Mediator::setCurrentSlivkiAmount(double newSlivkiAmount){
    currentSlivkiAmount = newSlivkiAmount;
}
