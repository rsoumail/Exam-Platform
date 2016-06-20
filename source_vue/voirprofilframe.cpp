#include "include_vue/voirprofilframe.h"
#include "ui_voirprofilframe.h"

VoirProfilFrame::VoirProfilFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VoirProfilFrame)
{
    ui->setupUi(this);

}

VoirProfilFrame::~VoirProfilFrame()
{
    delete ui;
}

Utilisateur VoirProfilFrame::getUser() const
{
    return user;
}

void VoirProfilFrame::setUser(const Utilisateur &value)
{
    user = value;
}

void VoirProfilFrame::update()
{
    ui->valeur_pseudo->setText(user.pseudo());
    ui->valeur_nom->setText(user.nom());
    ui->valeur_prenom->setText(user.prenom());
    if(user.sexe() == "f")
        ui->valeur_sexe->setText("Féminin");
    else
        ui->valeur_sexe->setText("Masculin");
    ui->valeur_civilite->setText(user.civilite());
    ui->valeur_nationalite->setText(user.nationalite());
    ui->valeur_adresse->setText(user.adresse());
    ui->valeur_email->setText(user.email());
}

