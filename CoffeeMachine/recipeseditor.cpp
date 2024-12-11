#include "recipeseditor.h"
#include "ui_recipeseditor.h"
#include <iostream>

#include <QScrollArea>
#include <QLabel>

RecipesEditor::RecipesEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecipesEditor)
    , mediator(nullptr)
{
    ui->setupUi(this);

    // recipesNumberTotal = 0;
}

RecipesEditor::~RecipesEditor()
{
    delete ui;
}

void RecipesEditor::setMediator(Mediator *mediator){
    this->mediator=mediator;
}


void RecipesEditor::on_addNewRecipeButton_clicked()
{
    addNewRecipe();
}

void RecipesEditor::addNewRecipe()
{
    // std::cout<<"Test"<<std::endl;
    RecipePanel *newPanel = new RecipePanel(this);

    ui->verticalLayout->addWidget(newPanel);

    // ui->scrollAreaWidgetContents->
    // newPanel->setAttribute(Qt::WA_DeleteOnClose,true);
    // newPanel->panelNumber = recipesNumberTotal;
    // recipesNumberTotal++;
    // allRecipesPtr.append(newPanel);
}

void RecipesEditor::showRecipes(QVector<Recipe> recipesList){
    qDebug() << recipesList.size();
    for(int i = 0, n = recipesList.size(); i < n; i++){
        RecipePanel *newPanel = new RecipePanel(this);
        connect(newPanel, SIGNAL(deleteThisRecipe(int)), this, SLOT(closeRecipe(int)));
        newPanel->setRecipe(recipesList[i]);
        allRecipes.append(newPanel);
        ui->verticalLayout->addWidget(newPanel, i, 0);
        // ui->verticalLayout->addWidget(allRecipes[i], recipesNumberTotal, 0);
    }
}

void RecipesEditor::closeRecipe(int recipeNumber){
    // Ended here
    for(int i = 0, n = allRecipes.size(); i < n; i++){
        if(allRecipes[i]->panelNumber == recipeNumber){
            allRecipes[i]->close();
            allRecipes.remove(i);
        }
    }
}

void RecipesEditor::on_backToChoosingServiceButton_clicked()
{
    mediator->openWindowChoosingService();
}

