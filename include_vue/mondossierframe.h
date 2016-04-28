#ifndef MONDOSSIERFRAME_H
#define MONDOSSIERFRAME_H

#include <QFrame>
#include "dossieraccepteframe.h"
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

private slots:
    void on_btn_acte_naissance_clicked();

    void on_btn_cv_clicked();


    void on_btn_photo_clicked();

    void on_btn_diplome_clicked();

    void on_btn_modifier_dossier_clicked();


private:
    Ui::MonDossierFrame *ui;
    Candidat user;
};

#endif // MONDOSSIERFRAME_H
