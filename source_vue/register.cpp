#include "register.h"
#include "connexion.h"
#include "ui_register.h"
#include <QDesktopWidget>
#include <QMessageBox>
#include <QDebug>


Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->champ_nom->setFocus();


}

Register::~Register()
{
    delete ui;
}


void Register::on_btn_connexion_clicked()
{
    Connexion *connexion = new Connexion();
    this->close();
    connexion->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            connexion->size(),
            qApp->desktop()->availableGeometry()
        )
    );


    connexion->setFixedSize(connexion->width(), connexion->height());

    connexion->setWindowFlags(Qt::WindowCloseButtonHint);
    connexion->show();
}

void Register::on_btn_inscription_clicked()
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
                   QMessageBox::StandardButton reponse;
                   reponse = QMessageBox::question(this, "Notification", "Votre Compte à été bien crée ! voulez être redirigé vers la page d'authentication?",
                                         QMessageBox::Yes | QMessageBox::No);
                   if(reponse == QMessageBox::Yes)
                   {
                       on_btn_connexion_clicked();
                   }
                }
            }

        }
    }
}
