#include "mondossierframe.h"
#include "ui_mondossierframe.h"
#include <QFileDialog>
#include <QMessageBox>
#include "uploadmanager.h"

MonDossierFrame::MonDossierFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MonDossierFrame)
{
    ui->setupUi(this);

}

MonDossierFrame::~MonDossierFrame()
{
    delete ui;
}

void MonDossierFrame::on_btn_acte_naissance_clicked()
{
    acte_naissance =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg)");
    QStringList tableau = acte_naissance.split(".");
    extention_acte = tableau.at(tableau.size() - 1);
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString("hh_mm_ss_yyyy_MM_dd");
    nom_acte_naissance = "acte_naissance_" + dateTimeString + "." + extention_acte;
    ui->champ_acte_naissance->setText(acte_naissance);

}


void MonDossierFrame::on_btn_cv_clicked()
{
   cv =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg)");
    QStringList tableau = cv.split(".");
    extention_cv = tableau.at(tableau.size() - 1);
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString("hh_mm_ss_yyyy_MM_dd");
    nom_cv = "cv_" + dateTimeString + "." + extention_cv;

    ui->champ_cv->setText(cv);
}


void MonDossierFrame::on_btn_photo_clicked()
{
    photo =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg)");
    QStringList tableau = photo.split(".");
    extention_photo = tableau.at(tableau.size() - 1);
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString("hh_mm_ss_yyyy_MM_dd");
    nom_photo = "photo_" + dateTimeString + "." + extention_photo;
    ui->champ_photo->setText(photo);
}

void MonDossierFrame::on_btn_diplome_clicked()
{
    diplome =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg)");
    QStringList tableau = diplome.split(".");
    extention_diplome = tableau.at(tableau.size() - 1);
    QDateTime dateTime = QDateTime::currentDateTime();
    QString dateTimeString = dateTime.toString("hh_mm_ss_yyyy_MM_dd");
    nom_diplome = "diplome_" + dateTimeString + "." + extention_diplome;
    ui->champ_diplome->setText(diplome);
}

Candidat MonDossierFrame::getUser() const
{
    return user;
}

void MonDossierFrame::setUser(const Candidat &value)
{
    user = value;
}


void MonDossierFrame::on_btn_modifier_dossier_clicked()
{
    ui->groupBox_formulaire_dossier->show();
    setUpdate_or_save(1);
}



void MonDossierFrame::on_btn_valider_clicked()
{
    if(ui->champ_acte_naissance->text().isEmpty() || ui->champ_cv->text().isEmpty() || ui->champ_diplome->text().isEmpty() || ui->champ_photo->text().isEmpty()){
        QMessageBox::warning(this,"Attention","Veuillez indiquez toute les informations !");
    }
    else
    {
        ConcoursManager concoursManager;
        Concours concours_actif = concoursManager.actif();
        QStringList datetab = getUser().date_naissance().split("/");
        QString annee = datetab.at(datetab.size()-1);
        int a = concours_actif.annee().toInt() - annee.toInt();
        if(a > concours_actif.age_limite())
        {
            QMessageBox::warning(this,"Attention","Vous n'êtes pas autorisez à vous inscrire paur cause de limite d'age !");
        }
        else if(update_or_save == 0)
        {
            ConcoursManager concoursManager;
            Concours concours_actif = concoursManager.actif();
            CandidatureManager candidatureManager;
            candidatureManager.all_old_to_inactif(getUser().id());
            Candidat candidat = getUser();
            Candidature candidature(candidat,concours_actif);
            int id_candidature = candidatureManager.save(candidature);
            Candidature candidature_new = candidatureManager.unique(id_candidature);
            Dossier dossier(candidature_new);
            dossier.setCv(nom_cv);
            dossier.setPhoto(nom_photo);
            dossier.setActe_naissance(nom_acte_naissance);
            dossier.setDiplome(nom_diplome);
            DossierManager dossierManager;
            int id_dossier = dossierManager.save(dossier);
            candidature_new.setId_dossier(id_dossier);
            CandidatureManager candidatureManager2;
            int notification = candidatureManager2.update(candidature_new);
            if(notification == 1)
            {
                UploadManager manager;
                manager.execute(diplome, DIPLOME_FILE, nom_diplome, extention_diplome);
                manager.execute(photo, PHOTO_FILE, nom_photo, extention_photo);
                manager.execute(acte_naissance, ACTE_NAISSANCE_FILE, nom_acte_naissance, extention_acte);
                manager.execute(cv, CV_FILE, nom_cv, extention_cv);
                QMessageBox::information(this,"Succès","Votre demande de candidature à été bien enrégistrée !");
                ui->groupBox_formulaire_dossier->hide();
            }
            else
            {
                QMessageBox::warning(this,"Erreur","Une erreur est survenue lors de l'enrégistrement de votre candidature !");
            }
        }
        else if(update_or_save == 1)
        {
            CandidatureManager candidatureManager;
            Candidature candidature = candidatureManager.actif(getUser().id());
            DossierManager dossierManager;
            Dossier dossier = dossierManager.unique(candidature.id_dossier());
            dossier.setCv(nom_cv);
            dossier.setPhoto(nom_photo);
            dossier.setActe_naissance(nom_acte_naissance);
            dossier.setDiplome(nom_diplome);
            int notification = dossierManager.save(dossier);
            if(notification == 1)
            {
                UploadManager manager;
                manager.execute(diplome, DIPLOME_FILE, nom_diplome, extention_diplome);
                manager.execute(photo, PHOTO_FILE, nom_photo, extention_photo);
                manager.execute(acte_naissance, ACTE_NAISSANCE_FILE, nom_acte_naissance, extention_acte);
                manager.execute(cv, CV_FILE, nom_cv, extention_cv);
                QMessageBox::information(this,"Succès","La modification de votre dossier à été pris en compte !");
                ui->groupBox_formulaire_dossier->hide();
            }
            else
            {
                QMessageBox::warning(this,"Erreur","Une erreur est survenue lors de la modifiation de votre dossier !");
            }
        }

    }
}

void MonDossierFrame::on_btn_annuler_clicked()
{
    ui->champ_acte_naissance->setText("");
    ui->champ_cv->setText("");
    ui->champ_diplome->setText("");
    ui->champ_photo->setText("");
}

int MonDossierFrame::getUpdate_or_save() const
{
    return update_or_save;
}

void MonDossierFrame::setUpdate_or_save(int value)
{
    update_or_save = value;
}

void MonDossierFrame::update()
{
    CandidatureManager candidatureManager;
    Candidature candidature = candidatureManager.actif(getUser().id());
    ConcoursManager concoursManager;
    Concours concours_actif = concoursManager.actif();
    DossierManager dossierManager;
    Dossier dossier = dossierManager.unique(candidature.id_dossier());
    if(dossier.statut() == 1)
        ui->label_statut_dossier->setText("Accepté");
    else if(dossier.statut() == 0)
        ui->label_statut_dossier->setText("Rejeté");
    if(candidature.concours().annee() != concours_actif.annee())
    {
        ui->btn_modifier_dossier->hide();
        setUpdate_or_save(0);
    }
    else if((candidature.concours().annee() == concours_actif.annee() && dossier.statut() == 0 && dossier.a_traiter() == 0))
    {
        ui->groupBox_formulaire_dossier->hide();
        ui->label_statut_dossier->setText("Rejeté");
    }
    else
    {
        ui->groupBox_formulaire_dossier->hide();
        ui->btn_modifier_dossier->hide();
        if(dossier.a_traiter() == 1)
            ui->label_statut_dossier->setText("En attente");
    }
}
