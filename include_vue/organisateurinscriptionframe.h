#ifndef ORGANISATEURINSCRIPTIONFRAME_H
#define ORGANISATEURINSCRIPTIONFRAME_H

#include <QFrame>
#include "modifierprofilframe.h"
#include "filedownloader.h"

namespace Ui {
class OrganisateurInscriptionFrame;
}

class OrganisateurInscriptionFrame : public QFrame
{
    Q_OBJECT

public:
    explicit OrganisateurInscriptionFrame(QWidget *parent = 0);
    ~OrganisateurInscriptionFrame();

private slots:
    void onTableCellClicked(const QModelIndex&);

    void on_btn_retour_2_clicked();

    void on_bnt_voir_photo_clicked();

    void on_btn_voir_acte_naissance_3_clicked();

    void on_btn_voir_cv_3_clicked();

    void on_btn_voir_diplome_3_clicked();

    void on_btn_accepte_2_clicked();

    void on_btn_rejete_2_clicked();

 void loadImage();

private:
    Ui::OrganisateurInscriptionFrame *ui;
    Dossier dossier_a_modidfier;
    void lister();
    FileDownloader *m_pImgCtrl;
};

#endif // ORGANISATEURINSCRIPTIONFRAME_H
