#ifndef NEWFORM_H
#define NEWFORM_H

#include <QWidget>

namespace Ui {
class newForm;
}

class newForm : public QWidget
{
    Q_OBJECT

public:
    explicit newForm(QWidget *parent = nullptr);
    ~newForm();

private:
    Ui::newForm *ui;
};

#endif // NEWFORM_H
