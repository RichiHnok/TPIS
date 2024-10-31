#ifndef FORM_H
#define FORM_H

#include "mediator.h"
#include <QWidget>

namespace Ui {
class Form;
}

class Mediator;

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void setMediator(Mediator* mediator);

private slots:
    void on_backToChoosingRoleButton_clicked();

private:
    Ui::Form *ui;
    Mediator* mediator;
};

#endif // FORM_H
