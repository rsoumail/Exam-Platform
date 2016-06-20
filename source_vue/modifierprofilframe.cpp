#include "include_vue/modifierprofilframe.h"
#include "ui_modifierprofilframe.h"
#include <QMessageBox>

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

Utilisateur ModifierProfilFrame::getUser() const
{
    return user;
}

void ModifierProfilFrame::setUser(const Utilisateur &value)
{
    user = value;
}

void ModifierProfilFrame::update()
{
    Utilisateur user = getUser();
    ui->champ_nom->setText(user.nom());
    ui->champ_prenom->setText(user.prenom());
    if(user.sexe() == "m")
        ui->sexe->setCurrentIndex(0);
    if(user.sexe() == "f")
        ui->sexe->setCurrentIndex(1);
    ui->date_naissance->setDate(QDate::fromString(user.date_naissance(), "dd/MM/yyyy"));
    if(user.civilite() == "Monsieur")
        ui->etat_civile->setCurrentIndex(0);
    if(user.civilite() == "Madame")
        ui->etat_civile->setCurrentIndex(1);
    if(user.civilite() == "Mademoiselle")
        ui->etat_civile->setCurrentIndex(2);
    ui->champ_natonalite->setText(user.nationalite());
    ui->champ_adresse->setText(user.adresse());
    ui->champ_telephone->setText(user.telephone());
    ui->champ_email->setText(user.telephone());
    ui->champ_pseudo->setText(user.pseudo());
    ui->champ_password->setText(user.password());
    ui->champ_confirm_password->setText(user.password());

}

void ModifierProfilFrame::on_btn_inscription_clicked()
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
            Utilisateur user = getUser();
            user.setNom(nom);
            user.setPrenom(prenom);
            user.setSexe(sexe);
            user.setDate_naissance(date_naissance);
            user.setCivilite(civilite);
            user.setNationalite(nationalite);
            user.setAdresse(adresse);
            user.setTelephone(telephone);
            user.setEmail(email);
            user.setPseudo(pseudo);
            user.setPassword(password);
            Groupe groupe = getUser().groupe();
            if(groupe.id() == 1)
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
                    AdministrateurManager administrateurManager;
                    Administrateur utilisateur;
                    utilisateur.setId(user.id());
                    utilisateur.setNom(user.nom());
                    utilisateur.setPrenom(user.prenom());
                    utilisateur.setSexe(user.sexe());
                    utilisateur.setDate_naissance(user.date_naissance());
                    utilisateur.setCivilite(user.civilite());
                    utilisateur.setNationalite(user.nationalite());
                    utilisateur.setAdresse(user.adresse());
                    utilisateur.setTelephone(user.telephone());
                    utilisateur.setEmail(user.email());
                    utilisateur.setPseudo(user.pseudo());
                    utilisateur.setPassword(user.password());
                    utilisateur.setGroupe(user.groupe());
                    int etat_req = administrateurManager.update(utilisateur);
                    if(etat_req == 1)
                    {
                       QMessageBox::information(this, "Notification", "Votre Compte à été bien modifié");
                    }
                }
            }
            else if(groupe.id() == 2)
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
                    CandidatManager candidatManager;
                    Candidat utilisateur;
                    utilisateur.setId(user.id());
                    utilisateur.setNom(user.nom());
                    utilisateur.setPrenom(user.prenom());
                    utilisateur.setSexe(user.sexe());
                    utilisateur.setDate_naissance(user.date_naissance());
                    utilisateur.setCivilite(user.civilite());
                    utilisateur.setNationalite(user.nationalite());
                    utilisateur.setAdresse(user.adresse());
                    utilisateur.setTelephone(user.telephone());
                    utilisateur.setEmail(user.email());
                    utilisateur.setPseudo(user.pseudo());
                    utilisateur.setPassword(user.password());
                    utilisateur.setGroupe(user.groupe());
                    int etat_req = candidatManager.update(utilisateur);
                    if(etat_req == 1)
                    {
                       QMessageBox::information(this, "Notification", "Votre Compte à été bien modifié");
                    }
                }
            }
            else if(groupe.id() == 3)
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
                    OrganisateurManager organisateurManager;
                    Organisateur utilisateur;
                    utilisateur.setId(user.id());
                    utilisateur.setNom(user.nom());
                    utilisateur.setPrenom(user.prenom());
                    utilisateur.setSexe(user.sexe());
                    utilisateur.setDate_naissance(user.date_naissance());
                    utilisateur.setCivilite(user.civilite());
                    utilisateur.setNationalite(user.nationalite());
                    utilisateur.setAdresse(user.adresse());
                    utilisateur.setTelephone(user.telephone());
                    utilisateur.setEmail(user.email());
                    utilisateur.setPseudo(user.pseudo());
                    utilisateur.setPassword(user.password());
                    utilisateur.setGroupe(user.groupe());
                    int etat_req = organisateurManager.update(utilisateur);
                    if(etat_req == 1)
                    {
                       QMessageBox::information(this, "Notification", "Votre Compte à été bien modifié");
                    }
                }
            }


        }
    }
}
