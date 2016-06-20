#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include "register.h"
#include "candidatscreen.h"
#include "administrateurscreen.h"
#include "organisateurscreen.h"

namespace Ui {
class Connexion;
}

class Connexion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = 0);
    ~Connexion();

private slots:
 void on_register_link_clicked();

 void on_btn_connexion_clicked();

private:
    Ui::Connexion *ui;
    Register *r = new Register();
    CandidatScreen *cs = new CandidatScreen();
    AdministrateurScreen *adminScreen = new AdministrateurScreen();
   // Administrateur *userAdmin = new Administrateur();
    //Candidat *userCandidat = new Candidat();
    //Organisateur *userOrganis = new Organisateur();
    OrganisateurScreen *orgScreen = new OrganisateurScreen();
};

#endif // CONNEXION_H
