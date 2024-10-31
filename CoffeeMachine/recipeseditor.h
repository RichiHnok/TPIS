#ifndef RECIPESEDITOR_H
#define RECIPESEDITOR_H

#include <QWidget>
#include <QVector>
#include "recipepanel.h"
#include "mediator.h"

namespace Ui {
class RecipesEditor;
}

class RecipesEditor : public QWidget
{
    Q_OBJECT

public:
    explicit RecipesEditor(QWidget *parent = nullptr);
    ~RecipesEditor();
    int recipesNumberTotal;
    // QVector<RecipePanel *> allRecipesPtr;
    void setMediator(Mediator* mediator);

private slots:
    void on_addNewRecipeButton_clicked();
    void addNewRecipe();

    void on_backToChoosingServiceButton_clicked();

private:
    Ui::RecipesEditor *ui;
    Mediator* mediator;
};

#endif // RECIPESEDITOR_H
