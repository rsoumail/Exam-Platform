#include "candidatscreen.h"
#include "ui_candidatscreen.h"
#include "register.h"
#include "mondossierframe.h"
#include "connexion.h"
#include <QDebug>
#include <QFileDialog>
#include <QDesktopWidget>

CandidatScreen::CandidatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CandidatScreen)
{
    ui->setupUi(this);
    createActions();
    widgetCourant = mdf;
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
        mdf->setUser(getUser());
        mdf->update();
        widgetCourant = mdf;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Mon Dossier");
    }
}

void CandidatScreen::deconnexion()
{
    Connexion *connexion = new Connexion();
    this->close();
    connexion->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            connexion->size(),
            qApp->desktop()->availableGeometry()
        )
    );


    connexion->setFixedSize(connexion->width(), connexion->height());

    connexion->setWindowFlags(Qt::WindowCloseButtonHint);
    connexion->show();
}

void CandidatScreen::setUser(const Candidat &value)
{
    user = value;
}


void CandidatScreen::on_actionDossiers_Rej_t_s_triggered()
{
    if(widgetCourant != dossierRejeFrame)
    {
        widgetCourant->deleteLater();
        Dossierrejeteframe *dossierRejeFrame = new Dossierrejeteframe();
        widgetCourant = dossierRejeFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Dossiers Rejetés");
    }
}

MonDossierFrame *CandidatScreen::getMdf() const
{
    return mdf;
}

void CandidatScreen::setMdf(MonDossierFrame *value)
{
    mdf = value;
}

Candidat CandidatScreen::getUser() const
{
    return user;
}

void CandidatScreen::on_actionListe_des_admis_triggered()
{
    if(widgetCourant != listeAdmisFrame)
    {
        widgetCourant->deleteLater();
        LIsteAdmisFrame *listeAdmisFrame = new LIsteAdmisFrame();
        widgetCourant = listeAdmisFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Liste des Admis");
    }
}

void CandidatScreen::on_actionVoir_les_rejets_triggered()
{
    if(widgetCourant != listeEchouesFrame)
    {
        widgetCourant->deleteLater();
        ListeEchouesFrame *listeEchouesFrame = new ListeEchouesFrame();
        widgetCourant = listeEchouesFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Liste des Echoués");
    }
}

void CandidatScreen::on_actionMon_resultat_triggered()
{
    if(widgetCourant != monResultatFrame)
    {
        widgetCourant->deleteLater();
        MonResultatFrame *monResultatFrame = new MonResultatFrame();
        monResultatFrame->setUser(user);
        monResultatFrame->update();
        widgetCourant = monResultatFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Mon Resultat");
    }
}

void CandidatScreen::on_actionVoir_triggered()
{
    if(widgetCourant != voirProfilFrame)
    {
        widgetCourant->deleteLater();
        VoirProfilFrame *voirProfilFrame = new VoirProfilFrame();
        voirProfilFrame->setUser(user);
        voirProfilFrame->update();
        widgetCourant = voirProfilFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Mon profil");
    }
}

void CandidatScreen::on_actionModifier_triggered()
{
    if(widgetCourant != modifierProfilFrame)
    {
        widgetCourant->deleteLater();
        ModifierProfilFrame *modifierProfilFrame = new ModifierProfilFrame();
        modifierProfilFrame->setUser(user);
        modifierProfilFrame->update();
        widgetCourant = modifierProfilFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Modifier mon Profil");
    }
}
