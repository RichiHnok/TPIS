#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QString>

class DatabaseManager
{
public:
    DatabaseManager();
    bool openDatabase();
    void closeDatabase();
    void executeSelect();
    QSqlDatabase db;
};

#endif // DATABASEMANAGER_H
