#ifndef COFFEE_H
#define COFFEE_H

#include <QWidget>

namespace Ui {
class coffee;
}

class coffee : public QWidget
{
    Q_OBJECT

public:
    explicit coffee(QWidget *parent = nullptr);
    ~coffee();

private:
    Ui::coffee *ui;
};

#endif // COFFEE_H
