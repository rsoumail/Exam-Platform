#ifndef MONDOSSIERFRAME_H
#define MONDOSSIERFRAME_H

#include <QFrame>
#include "modifierprofilframe.h"
namespace Ui {
class MonDossierFrame;
}

class MonDossierFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MonDossierFrame(QWidget *parent = 0);
    ~MonDossierFrame();

    Candidat getUser() const;
    void setUser(const Candidat &value);

    int getUpdate_or_save() const;
    void setUpdate_or_save(int value);
    void update();

private slots:
    void on_btn_acte_naissance_clicked();

    void on_btn_cv_clicked();


    void on_btn_photo_clicked();

    void on_btn_diplome_clicked();

    void on_btn_modifier_dossier_clicked();


    void on_btn_valider_clicked();

    void on_btn_annuler_clicked();

private:
    Ui::MonDossierFrame *ui;
    Candidat user;
    QString nom_acte_naissance, nom_cv, nom_diplome, nom_photo,photo,acte_naissance,cv,diplome, extention_diplome , extention_acte, extention_cv, extention_photo;
    int update_or_save;
};

#endif // MONDOSSIERFRAME_H
