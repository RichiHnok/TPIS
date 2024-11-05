#include "roli.h"
#include <QDebug>

void Roli::on_pushButton_clicked() {
    qDebug() << "Кнопка 'Обслужевание кофемашины' нажата";
}

void Roli::on_pushButton_2_clicked() {
    qDebug() << "Кнопка 'Клиент' нажата";
}

void Roli::on_pushButton_3_clicked() {
    qDebug() << "Кнопка 'Индикатор' нажата";
}

void Roli::on_pushButton_4_clicked() {
    qDebug() << "Кнопка 'Окно выбора роли' нажата";
}
