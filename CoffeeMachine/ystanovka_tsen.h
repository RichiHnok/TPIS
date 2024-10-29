#ifndef YSTANOVKA_TSEN_H
#define YSTANOVKA_TSEN_H

#include <QWidget>

namespace Ui {
class Ystanovka_tsen;
}

class Ystanovka_tsen : public QWidget
{
    Q_OBJECT

public:
    explicit Ystanovka_tsen(QWidget *parent = nullptr);
    ~Ystanovka_tsen();

private:
    Ui::Ystanovka_tsen *ui;
};

#endif // YSTANOVKA_TSEN_H
