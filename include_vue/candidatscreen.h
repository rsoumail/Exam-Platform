#ifndef CANDIDATSCREEN_H
#define CANDIDATSCREEN_H

#include <QMainWindow>
#include <QSignalMapper>
#include "mondossierframe.h"



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

private slots:
    void on_actionCandidats_Authoris_s_triggered();
    void mon_dossier();
    void deconnexion();

private:
    Ui::CandidatScreen *ui;
    Candidat user;
    MonDossierFrame *mdf = new MonDossierFrame();
    QWidget * widgetCourant;
    DossierAccepteFrame *dossierAccepteFrame = new DossierAccepteFrame();
    void createActions();
    QSignalMapper *pSignalMapper;
};

#endif // CANDIDATSCREEN_H
