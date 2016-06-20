#ifndef ORGANISATEURSCREEN_H
#define ORGANISATEURSCREEN_H

#include <QMainWindow>
#include "organisteurvalidationframe.h"

namespace Ui {
class OrganisateurScreen;
}

class OrganisateurScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrganisateurScreen(QWidget *parent = 0);
    ~OrganisateurScreen();

    Organisateur getUser() const;
    void setUser(const Organisateur &value);

    OrganisateurInscriptionFrame *getOrgInsFrame() const;
    void setOrgInsFrame(OrganisateurInscriptionFrame *value);

private slots:
    void deconnexion();

    void on_actionFiche_notes_triggered();

    void on_actionImporter_Notes_triggered();

    void on_actionNon_Valides_triggered();

    void on_actionAccptes_triggered();

    void on_actionRejetes_triggered();

    void on_actionVoir_triggered();

    void on_actionModifier_triggered();

    void on_actionAfficher_triggered();

    void on_actionVoir_les_admis_triggered();

    void on_actionVoir_les_recal_s_triggered();

private:
    Ui::OrganisateurScreen *ui;
    QWidget *widgetCourant;
    Organisateur user;
    OrganisateurInscriptionFrame *orgInsFrame = new OrganisateurInscriptionFrame();
    OrganisateurAfficherNotesFrame *orgAffFrame = new OrganisateurAfficherNotesFrame();
    OrganisteurValidationFrame *orgValidationFrame = new OrganisteurValidationFrame();
    DossierAccepteFrame *dossierAccepteFrame = new DossierAccepteFrame();
    Dossierrejeteframe *dossierrejeteframe = new Dossierrejeteframe();
    LIsteAdmisFrame *listeAdmisFrame = new LIsteAdmisFrame();
    ListeEchouesFrame *listeEchouesFrame = new ListeEchouesFrame();
    VoirProfilFrame *voirProfilFrame = new VoirProfilFrame();
    ModifierProfilFrame *modifierProfilFrame = new ModifierProfilFrame();
    void createActions();
    QSignalMapper *pSignalMapper;
};

#endif // ORGANISATEURSCREEN_H
