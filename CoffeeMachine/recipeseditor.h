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
    void setMediator(Mediator* mediator);
    void addNewRecipe();
    void showRecipes(QVector<Recipe> recipesList);

    QVector<RecipePanel*> allRecipes;

private slots:
    void on_addNewRecipeButton_clicked();


    void on_backToChoosingServiceButton_clicked();

public slots:
    void closeRecipe(int);

private:
    Ui::RecipesEditor *ui;
    Mediator* mediator;
};

#endif // RECIPESEDITOR_H
