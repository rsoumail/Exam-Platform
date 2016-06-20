#include "creecompteframe.h"
#include "ui_creecompteframe.h"
#include <QMessageBox>

CreeCompteFrame::CreeCompteFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreeCompteFrame)
{
    ui->setupUi(this);
}

CreeCompteFrame::~CreeCompteFrame()
{
    delete ui;
}

Administrateur CreeCompteFrame::getUser() const
{
    return user;
}

void CreeCompteFrame::setUser(const Administrateur &value)
{
    user = value;
}

void CreeCompteFrame::on_btn_inscription_clicked()
{
    if(ui->champ_nom->text().isEmpty() || ui->champ_prenom->text().isEmpty()
                        || ui->champ_pseudo->text().isEmpty() || ui->champ_password->text().isEmpty() || ui->champ_confirm_password->text().isEmpty())
    {
        QMessageBox::warning(this,"Attention","Veuillez remplir tous les champs précédés de (*).");
    }
    else
    {
        QString nom = ui->champ_nom->text();
        QString prenom = ui->champ_prenom->text();
        QString sexe = (ui->sexe->currentText() == "Masculin" ? "m": "f");
        QString date_naissance = ui->date_naissance->text();
        QString civilite = ui->etat_civile->currentText();
        QString nationalite = ui->champ_natonalite->text();
        QString adresse = ui->champ_adresse->text();
        QString telephone = ui->champ_telephone->text();
        QString email = ui->champ_email->text();
        QString groupe = ui->groupe->currentText();
        QString pseudo = ui->champ_pseudo->text();
        QString password = ui->champ_password->text();
        QString confirm_password = ui->champ_confirm_password->text();

        if(password.length() < 6)
        {
            QMessageBox::warning(this,"Attention","Le mot de passe doit contenir au moins 6 caractères.");
            ui->champ_password->setFocus();
        }
        if(password != confirm_password)
        {
            QMessageBox::warning(this,"Attention","Les deux mots de passe ne sont pas identiques.");
            ui->champ_confirm_password->setFocus();
        }
        else
        {
           if(groupe == "Candidat")
           {
               CandidatManager candidatManager;
               int pseudo_utilise = candidatManager.countByPseudo(pseudo);
               if(pseudo_utilise == 1)
               {
                   QMessageBox::warning(this,"Attention","Le pseudo que vous avez choisi est déjà utilisé.");
                   ui->champ_pseudo->setFocus();
               }
               else if(pseudo_utilise == 0)
               {
                   GroupeManager groupeManager;
                   Groupe groupe = groupeManager.unique(2);
                   CandidatManager candidatManager;
                   Candidat candidat(0, nom, prenom, sexe, civilite, nationalite, adresse,  date_naissance, telephone, email, pseudo, password, groupe);
                   int etat_req = candidatManager.save(candidat);
                   if(etat_req == 1)
                   {
                     QMessageBox::information(this, "Notification", "Le Compte à été bien crée ! voulez être redirigé vers la page d'authentication?");

                   }
               }
           }
           else if(groupe == "Administrateur")
           {
               AdministrateurManager administrateurManager;
               int pseudo_utilise = administrateurManager.countByPseudo(pseudo);
               if(pseudo_utilise == 1)
               {
                   QMessageBox::warning(this,"Attention","Le pseudo que vous avez choisi est déjà utilisé.");
                   ui->champ_pseudo->setFocus();
               }
               else if(pseudo_utilise == 0)
               {
                   GroupeManager groupeManager;
                   Groupe groupe = groupeManager.unique(1);
                   AdministrateurManager administrateurManager;
                   Administrateur administrateur(0, nom, prenom, sexe, civilite, nationalite, adresse,  date_naissance, telephone, email, pseudo, password, groupe);
                   int etat_req = administrateurManager.save(administrateur);
                   if(etat_req == 1)
                   {
                      QMessageBox::information(this, "Notification", "Le Compte à été bien crée ! voulez être redirigé vers la page d'authentication?");

                   }
               }
           }
           else
           {
               OrganisateurManager organisateurManager;
               int pseudo_utilise = organisateurManager.countByPseudo(pseudo);
               if(pseudo_utilise == 1)
               {
                   QMessageBox::warning(this,"Attention","Le pseudo que vous avez choisi est déjà utilisé.");
                   ui->champ_pseudo->setFocus();
               }
               else if(pseudo_utilise == 0)
               {
                   GroupeManager groupeManager;
                   Groupe groupe = groupeManager.unique(3);
                   OrganisateurManager organisateurManager;
                   Organisateur oraganisateur(0, nom, prenom, sexe, civilite, nationalite, adresse,  date_naissance, telephone, email, pseudo, password, groupe);
                   int etat_req = organisateurManager.save(oraganisateur);
                   if(etat_req == 1)
                   {
                      QMessageBox::information(this, "Notification", "Le Compte à été bien crée ! voulez être redirigé vers la page d'authentication?");

                   }
               }
           }

        }
    }
}
