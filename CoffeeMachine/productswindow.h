#ifndef PRODUCTSWINDOW_H
#define PRODUCTSWINDOW_H

#include <QWidget>

namespace Ui {
class ProductsWindow;
}

class ProductsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProductsWindow(QWidget *parent = nullptr);
    ~ProductsWindow();

private:
    Ui::ProductsWindow *ui;
};

#endif // PRODUCTSWINDOW_H
