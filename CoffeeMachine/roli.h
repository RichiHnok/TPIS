#ifndef ROLI_H
#define ROLI_H

#include <QWidget>

namespace Ui {
class Roli;
}

class Roli : public QWidget
{
    Q_OBJECT

public:
    explicit Roli(QWidget *parent = nullptr);
    ~Roli();

private:
    Ui::Roli *ui;
};

#endif // ROLI_H
