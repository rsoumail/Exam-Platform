#include "candidatscreen.h"
#include "ui_candidatscreen.h"
#include "register.h"
#include "mondossierframe.h"
#include <QDebug>

CandidatScreen::CandidatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CandidatScreen)
{
    ui->setupUi(this);
    createActions();
    widgetCourant = mdf ;
    ui->horizontalLayout->addWidget(widgetCourant);
    this->windowTitleChanged("Mon Dossier");


}

CandidatScreen::~CandidatScreen()
{
    delete ui;
}

void CandidatScreen::on_actionCandidats_Authoris_s_triggered()
{
    if(widgetCourant != dossierAccepteFrame)
    {
        widgetCourant->deleteLater();
        DossierAccepteFrame *dossierAccepteFrame = new DossierAccepteFrame();
        widgetCourant = dossierAccepteFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Dossiers Acceptés");
    }

}


void CandidatScreen::createActions()
{
    pSignalMapper = new QSignalMapper(this);
    connect(ui->menuMon_Dossier, SIGNAL(aboutToShow()), this, SLOT(mon_dossier()));
    connect(ui->menuDeconnexion, SIGNAL(aboutToShow()), this, SLOT(deconnexion()));

}


void CandidatScreen::mon_dossier()
{

    if(widgetCourant != mdf)
    {
        widgetCourant->deleteLater();
        MonDossierFrame *mdf = new MonDossierFrame();
        widgetCourant = mdf;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Mon Dossier");
    }
}

void CandidatScreen::deconnexion()
{

}

