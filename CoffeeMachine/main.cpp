#include <QApplication>
#include <QMainWindow>
#include <QSplitter>

#include "ystanovka_tsen.h"
#include "roli.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow mainWindow;

    // Создание разделителя для размещения окон
    QSplitter *splitter = new QSplitter(&mainWindow);
    splitter->setOrientation(Qt::Horizontal);

    Ystanovka_tsen *window1 = new Ystanovka_tsen();
    Roli *window2 = new Roli();

    splitter->addWidget(window1);
    splitter->addWidget(window2);

    mainWindow.setCentralWidget(splitter);
    mainWindow.resize(800, 600);
    mainWindow.show();
    return app.exec();
}
