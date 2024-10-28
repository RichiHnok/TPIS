#ifndef RECIPESEDITOR_H
#define RECIPESEDITOR_H

#include <QWidget>
#include <QVector>
#include "recipepanel.h"

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

private slots:
    void on_addNewRecipeButton_clicked();
    void addNewRecipe();

private:
    Ui::RecipesEditor *ui;
};

#endif // RECIPESEDITOR_H
