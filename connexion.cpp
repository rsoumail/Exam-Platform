#include "connexion.h"
#include "register.h"
#include "ui_connexion.h"


Connexion::Connexion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Connexion)
{
    ui->setupUi(this);

}

Connexion::~Connexion()
{
    delete ui;
}



void Connexion::on_register_link_clicked()
{
    this->close();
    r->show();
}

void Connexion::on_pushButton_clicked()
{
    this-> close();
    cs->show();
}
