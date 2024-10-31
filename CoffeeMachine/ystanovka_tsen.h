#ifndef YSTANOVKA_TSEN_H
#define YSTANOVKA_TSEN_H

#include "mediator.h"
#include <QWidget>

namespace Ui {
class Ystanovka_tsen;
}

class Mediator;

class Ystanovka_tsen : public QWidget
{
    Q_OBJECT

public:
    explicit Ystanovka_tsen(QWidget *parent = nullptr);
    ~Ystanovka_tsen();
    void setMediator(Mediator* mediator);

private slots:
    void on_backToChoosingServiceButton_clicked();

private:
    Ui::Ystanovka_tsen *ui;
    Mediator* mediator;
};

#endif // YSTANOVKA_TSEN_H
