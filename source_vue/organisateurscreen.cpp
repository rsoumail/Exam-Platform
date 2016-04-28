#include "organisateurscreen.h"
#include "ui_organisateurscreen.h"

OrganisateurScreen::OrganisateurScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganisateurScreen)
{
    ui->setupUi(this);
}

OrganisateurScreen::~OrganisateurScreen()
{
    delete ui;
}
