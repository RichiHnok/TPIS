#ifndef CHOOSINGSERVICE_H
#define CHOOSINGSERVICE_H

#include <QWidget>

namespace Ui {
class ChoosingService;
}

class ChoosingService : public QWidget
{
    Q_OBJECT

public:
    explicit ChoosingService(QWidget *parent = nullptr);
    ~ChoosingService();

private:
    Ui::ChoosingService *ui;
};

#endif // CHOOSINGSERVICE_H
