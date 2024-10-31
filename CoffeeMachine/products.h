#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "mediator.h"
#include <QWidget>

namespace Ui {
class Products;
}

class Products : public QWidget
{
    Q_OBJECT

public:
    explicit Products(QWidget *parent = nullptr);
    ~Products();
    void setMediator(Mediator* mediator);

private slots:
    void on_backToChoosingServiceWindowButton_clicked();

private:
    Ui::Products *ui;
    Mediator* mediator;
};

#endif // PRODUCTS_H
