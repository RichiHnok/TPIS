#include "mainwindow.h"
#include "recipeseditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RecipesEditor w;
    w.show();
    return a.exec();
}
