#ifndef RECIPEPANEL_H
#define RECIPEPANEL_H

#include <QWidget>
#include <QString>

namespace Ui {
class RecipePanel;
}

class RecipePanel : public QWidget
{
    Q_OBJECT

public:
    explicit RecipePanel(QWidget *parent = nullptr);
    ~RecipePanel();
    int panelNumber;

private:
    Ui::RecipePanel *ui;
};

#endif // RECIPEPANEL_H
