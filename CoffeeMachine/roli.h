#ifndef ROLI_H
#define ROLI_H

#include "mediator.h"
#include <QWidget>

namespace Ui {
class Roli;
}

class Mediator;

class Roli : public QWidget
{
    Q_OBJECT

public:
    explicit Roli(QWidget *parent = nullptr);
    void setMediator(Mediator* mediator);
    ~Roli();

private slots:

    void on_pushButton_3_clicked();
    void on_openServiceButton_clicked();

private:
    Ui::Roli *ui;
    Mediator* mediator;
};

#endif // ROLI_H
