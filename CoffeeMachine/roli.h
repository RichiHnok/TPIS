#ifndef ROLI_H
#define ROLI_H

#include <QWidget>
#include "ui_Roli.h"  // Подключаем автоматически сгенерированный файл

class Roli : public QWidget
{
    Q_OBJECT

public:
    Roli(QWidget* parent = nullptr) : QWidget(parent), ui(new Ui::Roli) {
        ui->setupUi(this);
    }

    ~Roli() {
        delete ui;
    }

    Ui::Roli* ui;

private slots:
    void on_pushButton_clicked();   // Обслужевание кофемашины
    void on_pushButton_2_clicked(); // Клиент
    void on_pushButton_3_clicked(); // Индикатор
    void on_pushButton_4_clicked(); // Окно выбора роли
};

#endif // ROLI_H
