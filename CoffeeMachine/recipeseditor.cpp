#include "recipeseditor.h"
#include "ui_recipeseditor.h"
#include <iostream>

#include <QScrollArea>
#include <QLabel>

RecipesEditor::RecipesEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RecipesEditor)
{
    ui->setupUi(this);
    recipesNumberTotal = 0;
}

RecipesEditor::~RecipesEditor()
{
    delete ui;
}


void RecipesEditor::on_addNewRecipeButton_clicked()
{
    addNewRecipe();
}

void RecipesEditor::addNewRecipe()
{
    // std::cout<<"Test"<<std::endl;
    RecipePanel *newPanel = new RecipePanel(this);

    ui->verticalLayout->addWidget(newPanel, recipesNumberTotal, 0);

    // ui->scrollAreaWidgetContents->
    // newPanel->setAttribute(Qt::WA_DeleteOnClose,true);
    // newPanel->panelNumber = recipesNumberTotal;
    // recipesNumberTotal++;
    // allRecipesPtr.append(newPanel);
}



