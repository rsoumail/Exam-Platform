#ifndef CANDIDATSCREEN_H
#define CANDIDATSCREEN_H

#include <QMainWindow>
#include <QSignalMapper>
#include "monresultatframe.h"



namespace Ui {
class CandidatScreen;
}

class CandidatScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit CandidatScreen(QWidget *parent = 0);
    ~CandidatScreen();

    void setUser(const Candidat &value);

    Candidat getUser() const;

    MonDossierFrame *getMdf() const;
    void setMdf(MonDossierFrame *value);

private slots:
    void on_actionCandidats_Authoris_s_triggered();
    void mon_dossier();
    void deconnexion();

    void on_actionDossiers_Rej_t_s_triggered();

    void on_actionListe_des_admis_triggered();

    void on_actionVoir_les_rejets_triggered();

    void on_actionMon_resultat_triggered();

    void on_actionVoir_triggered();

    void on_actionModifier_triggered();

private:
    Ui::CandidatScreen *ui;
    Candidat user;
    MonDossierFrame *mdf = new MonDossierFrame();
    QWidget * widgetCourant;
    DossierAccepteFrame *dossierAccepteFrame = new DossierAccepteFrame();
    Dossierrejeteframe *dossierRejeFrame = new Dossierrejeteframe();
    ListeEchouesFrame *listeEchouesFrame = new ListeEchouesFrame();
    LIsteAdmisFrame *listeAdmisFrame = new LIsteAdmisFrame();
    VoirProfilFrame *voirProfilFrame = new VoirProfilFrame();
    ModifierProfilFrame *modifierProfilFrame = new ModifierProfilFrame();
    MonResultatFrame *monResultatFrame = new MonResultatFrame();
    void createActions();
    QSignalMapper *pSignalMapper;
};

#endif // CANDIDATSCREEN_H
