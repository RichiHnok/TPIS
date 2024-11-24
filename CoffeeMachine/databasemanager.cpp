#include "databasemanager.h"

#include <QDir>

DatabaseManager::DatabaseManager() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    // qDebug() << "Текущий рабочий каталог:" << QDir::currentPath();
    // qDebug() << "Текущий рабочий каталог:" << QDir::currentPath() + "/../../data/coffee_machine.db";
    db.setDatabaseName(QDir::currentPath() + "/../../data/coffee_machine.db");
}

void DatabaseManager::executeSelect(){
    // QSqlDatabase db;
    if (!openDatabase()) {
        return;
    }

    QSqlQuery query;
    if (!query.exec("SELECT id, name FROM recipes")) {
        qDebug() << "Ошибка выполнения запроса:" << query.lastError().text();
        return;
    }

    while (query.next()) {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        qDebug() << "ID:" << id << ", Name:" << name;
    }

    db.close();
}

bool DatabaseManager::openDatabase() {
    if (!db.open()) {
        qDebug() << "Ошибка открытия базы данных:" << db.lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::closeDatabase() {
    db.close();
}
