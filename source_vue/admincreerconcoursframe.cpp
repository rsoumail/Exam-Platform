#include "include_vue/admincreerconcoursframe.h"
#include "ui_admincreerconcoursframe.h"
#include <QMessageBox>
#include <QDebug>
#include "algorithm"
AdminCreerConcoursFrame::AdminCreerConcoursFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AdminCreerConcoursFrame)
{
    ui->setupUi(this);
    if(getSave_or_update() == 1)
    {
        ui->champ_annee->setText(concours.annee());
        ui->champ_age_limite->setText((QString)concours.age_limite());
        int jour, mois, annee;
        jour = concours.date_limite().mid(0,2).toInt();
        mois = concours.date_limite().mid(3,2).toInt();
        annee = concours.date_limite().mid(6,4).toInt();
        QDate date_limite(jour,mois,annee);
        ui->champ_date_limite->setSelectedDate(date_limite);
        jour = concours.date_resultats().mid(0,2).toInt();
        mois = concours.date_resultats().mid(3,2).toInt();
        annee = concours.date_resultats().mid(6,4).toInt();
        QDate date_resultats(jour,mois,annee);
        ui->champ_date_resultat->setSelectedDate(date_resultats);
    }

}

AdminCreerConcoursFrame::~AdminCreerConcoursFrame()
{
    delete ui;
}

Administrateur AdminCreerConcoursFrame::getUser() const
{
    return user;
}

void AdminCreerConcoursFrame::setUser(const Administrateur &value)
{
    user = value;
}

void AdminCreerConcoursFrame::on_btn_enregistrer_clicked()
{
    if(ui->champ_annee->text().isEmpty() || ui->champ_age_limite->text().isEmpty())
    {
         QMessageBox::warning(this,"Attention","Veuillez remplir tous les champs.");
    }
    else
    {
        if(ui->champ_date_limite->selectedDate().year() < ui->champ_annee->text().toInt() || ui->champ_date_resultat->selectedDate().year() < ui->champ_annee->text().toInt())
        {
             QMessageBox::warning(this,"Attention","Veuillez bien vérifier les dates limite et de resultats.");
        }
        else
        {

            int notification;
            concours.setAge_limite(ui->champ_age_limite->text().toInt());
            concours.setAnnee(ui->champ_annee->text());
            concours.setDate_limite(ui->champ_date_limite->selectedDate().toString("dd-MM-yyyy"));
            concours.setDate_resultats(ui->champ_date_resultat->selectedDate().toString("dd-MM-yyyy"));
            concoursManager.all_old_to_inactif();
            if(getSave_or_update() == 0)
            {
                notification = concoursManager.save(concours);
                if(notification == 1)
                {
                    QMessageBox::about(this,"Notification","Le concours a bien été enregistré.");
                }
                else
                {
                    QMessageBox::warning(this,"Attention","Une erreur s'est produite lors de la création du concours.");
                }
            }
            else
            {
                notification = concoursManager.update(concours);
                if(notification == 1)
                {
                    QMessageBox::about(this,"Notification","Le concours a bien été modifié.");
                }
                else
                {
                    QMessageBox::warning(this,"Attention","Une erreur s'est produite lors de la modification du concours.");
                }
            }
        }
    }
}

int AdminCreerConcoursFrame::getSave_or_update() const
{
    return save_or_update;
}

void AdminCreerConcoursFrame::setSave_or_update(int value)
{
    save_or_update = value;
}
