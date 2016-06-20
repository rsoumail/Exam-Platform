#ifndef ADMINISTRATEURSCREEN_H
#define ADMINISTRATEURSCREEN_H

#include <QMainWindow>
#include "administrateurscreen.h"
#include "adminlisteconcoursframe.h"

namespace Ui {
class AdministrateurScreen;
}

class AdministrateurScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministrateurScreen(QWidget *parent = 0);
    ~AdministrateurScreen();

    Administrateur getUser() const;
    void setUser(const Administrateur &value);

    CreeCompteFrame *getCreeCompteFrame() const;
    void setCreeCompteFrame(CreeCompteFrame *value);

private slots:
    void deconnexion();


    void on_creer_compte_triggered();

    void on_lister_compte_triggered();

    void on_creer_concours_triggered();

    void on_lister_concours_triggered();

    void on_voir_profil_triggered();

    void on_modifier_profil_triggered();

private:
    Ui::AdministrateurScreen *ui;
    QWidget *widgetCourant;
    Administrateur user;
    CreeCompteFrame *creeCompteFrame = new CreeCompteFrame();
    AdminListeCompteFrame *adminListeCompteFrame = new AdminListeCompteFrame();
    AdminCreerConcoursFrame *adminCreerConcoursFrame = new AdminCreerConcoursFrame();
    AdminListeConcoursFrame *adminListeConcoursFrame = new AdminListeConcoursFrame();
    VoirProfilFrame *voirProfilFrame = new VoirProfilFrame();
    ModifierProfilFrame *modifierProfilFrame = new ModifierProfilFrame();
    void createActions();
    QSignalMapper *pSignalMapper;
};

#endif // ADMINISTRATEURSCREEN_H
