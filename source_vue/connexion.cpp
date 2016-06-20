#include "connexion.h"
#include "register.h"
#include "candidatscreen.h"
#include "ui_connexion.h"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDebug>



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


void Connexion::on_btn_connexion_clicked()
{
    QString pseudo = ui->champ_pseudo->text();
    QString password = ui->champ_password->text();
    QString groupe = ui->groupe->currentText();
    if(groupe == "Candidat")
    {
        CandidatManager candidatManager;
        Candidat user = candidatManager.uniqueByPseudoAndPassword(pseudo, password);
        if(user.nom() != "")
        {
            cs->setUser(user);
            cs->getMdf()->setUser(user);
            cs->getMdf()->update();
            this->close();
            cs->show();
        }
        else
        {
            QMessageBox::warning(this,"Attention","Le pseudo ou le mot de passe est incorrecte !");
        }
    }
    else if(groupe == "Organisateur")
    {
        OrganisateurManager organisateurManager;
        Organisateur user = organisateurManager.uniqueByPseudoAndPassword(pseudo, password);
        if(user.nom() != "")
        {

            orgScreen->setUser(user);
            //orgScreen->getOrgInsFrame()->setU
            this->close();
            orgScreen->show();
        }
        else
        {
            QMessageBox::warning(this,"Attention","Le pseudo ou le mot de passe est incorrecte !");
        }
    }
    else
    {
        AdministrateurManager administrateurManager;
        Administrateur user = administrateurManager.uniqueByPseudoAndPassword(pseudo, password);
        if(user.nom() != "")
        {
            adminScreen->setUser(user);
            adminScreen->getCreeCompteFrame()->setUser(user);
            this->close();
            adminScreen->show();
        }
        else
        {
            QMessageBox::warning(this,"Attention","Le pseudo ou le mot de passe est incorrecte !");
        }
    }
}
