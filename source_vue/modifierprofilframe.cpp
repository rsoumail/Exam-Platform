#include "include_vue/modifierprofilframe.h"
#include "ui_modifierprofilframe.h"

ModifierProfilFrame::ModifierProfilFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ModifierProfilFrame)
{
    ui->setupUi(this);
}

ModifierProfilFrame::~ModifierProfilFrame()
{
    delete ui;
}
