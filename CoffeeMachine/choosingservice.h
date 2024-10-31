#ifndef CHOOSINGSERVICE_H
#define CHOOSINGSERVICE_H

#include "mediator.h"
#include <QWidget>

namespace Ui {
class ChoosingService;
}

class Mediator;

class ChoosingService : public QWidget
{
    Q_OBJECT

public:
    explicit ChoosingService(QWidget *parent = nullptr);
    void setMediator(Mediator* mediator);
    ~ChoosingService();

private slots:
    void on_backToChoosingRoleButton_clicked();

    void on_goToRefillingProductsButton_clicked();

private:
    Ui::ChoosingService *ui;
    Mediator* mediator;
};

#endif // CHOOSINGSERVICE_H
