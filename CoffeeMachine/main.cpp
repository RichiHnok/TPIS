#include "mainwindow.h"
#include "mediator.h"

#include <QApplication>

#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    cout<<"Program started"<<endl;
    Mediator mediator;
    return a.exec();
}
