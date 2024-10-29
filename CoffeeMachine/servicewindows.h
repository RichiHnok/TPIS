#ifndef SERVICEWINDOWS_H
#define SERVICEWINDOWS_H

#include <QWidget>

namespace Ui {
class ServiceWindows;
}

class ServiceWindows : public QWidget
{
    Q_OBJECT

public:
    explicit ServiceWindows(QWidget *parent = nullptr);
    ~ServiceWindows();

private:
    Ui::ServiceWindows *ui;
};

#endif // SERVICEWINDOWS_H
