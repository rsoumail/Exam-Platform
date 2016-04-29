#include "administrateurscreen.h"
#include "ui_administrateurscreen.h"

AdministrateurScreen::AdministrateurScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministrateurScreen)
{
    ui->setupUi(this);
}

AdministrateurScreen::~AdministrateurScreen()
{
    delete ui;
}
