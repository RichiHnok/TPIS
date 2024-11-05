#ifndef YSTANOVKA_TSEN_H
#define YSTANOVKA_TSEN_H

#include <QWidget>
#include "ui_Ystanovka_tsen.h"  // Подключаем автоматически сгенерированный файл

class Ystanovka_tsen : public QWidget
{
    Q_OBJECT

public:
    Ystanovka_tsen(QWidget* parent = nullptr) : QWidget(parent), ui(new Ui::Ystanovka_tsen) {
        ui->setupUi(this);
    }

    ~Ystanovka_tsen() {
        delete ui;
    }

    Ui::Ystanovka_tsen* ui;

private slots:
    void on_pushButton_clicked();   // Установка цен
    void on_pushButton_2_clicked(); // Вернуться к обслуживанию
};

#endif // YSTANOVKA_TSEN_H
