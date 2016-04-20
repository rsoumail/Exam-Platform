#ifndef CANDIDATSCREEN_H
#define CANDIDATSCREEN_H

#include <QMainWindow>
#include <QSignalMapper>
#include "register.h"
#include "mondossierframe.h"
#include "dossieraccepteframe.h"


namespace Ui {
class CandidatScreen;
}

class CandidatScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit CandidatScreen(QWidget *parent = 0);
    ~CandidatScreen();

private slots:
    void on_actionCandidats_Authoris_s_triggered();
    void mon_dossier();
    void deconnexion();

private:
    Ui::CandidatScreen *ui;
    Register *r = new Register();
    MonDossierFrame *mdf = new MonDossierFrame();
    QWidget * widgetCourant;
    DossierAccepteFrame *dossierAccepteFrame = new DossierAccepteFrame();
    void createActions();
    QSignalMapper *pSignalMapper;
};

#endif // CANDIDATSCREEN_H
