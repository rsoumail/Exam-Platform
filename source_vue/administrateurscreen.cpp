#include "administrateurscreen.h"
#include "ui_administrateurscreen.h"
#include "connexion.h"
#include <QDesktopWidget>

AdministrateurScreen::AdministrateurScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdministrateurScreen)
{
    ui->setupUi(this);
    widgetCourant = creeCompteFrame ;
    creeCompteFrame->setUser(user);
    ui->horizontalLayout->addWidget(widgetCourant);
    createActions();
    this->windowTitleChanged("Création de compte");
}

AdministrateurScreen::~AdministrateurScreen()
{
    delete ui;
}

Administrateur AdministrateurScreen::getUser() const
{
    return user;
}

void AdministrateurScreen::setUser(const Administrateur &value)
{
    user = value;
}


void AdministrateurScreen::on_creer_compte_triggered()
{
    if(widgetCourant != creeCompteFrame)
    {
        widgetCourant->deleteLater();
        CreeCompteFrame *creeCompteFrame = new CreeCompteFrame();
        creeCompteFrame->setUser(user);
        widgetCourant = creeCompteFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Création de compte");
    }
}

void AdministrateurScreen::on_lister_compte_triggered()
{
    if(widgetCourant != adminListeCompteFrame)
    {
        widgetCourant->deleteLater();
        AdminListeCompteFrame *adminListeCompteFrame = new AdminListeCompteFrame();
        adminListeCompteFrame->setUser(user);
        widgetCourant = adminListeCompteFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Liste des comptes");
    }
}

void AdministrateurScreen::on_creer_concours_triggered()
{
    if(widgetCourant != adminCreerConcoursFrame)
    {
        widgetCourant->deleteLater();
        AdminCreerConcoursFrame *adminCreerConcoursFrame = new AdminCreerConcoursFrame();
        adminCreerConcoursFrame->setUser(user);
        adminCreerConcoursFrame->setSave_or_update(0);
        widgetCourant = adminCreerConcoursFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Création de concours");
    }
}

void AdministrateurScreen::on_lister_concours_triggered()
{
    if(widgetCourant != adminListeConcoursFrame)
    {
        widgetCourant->deleteLater();
        AdminListeConcoursFrame *adminListeConcoursFrame = new AdminListeConcoursFrame();
        adminListeConcoursFrame->setUser(user);
        widgetCourant = adminListeConcoursFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Liste des concours");
    }
}

void AdministrateurScreen::on_voir_profil_triggered()
{
    if(widgetCourant != voirProfilFrame)
    {
        widgetCourant->deleteLater();
        VoirProfilFrame *voirProfilFrame = new VoirProfilFrame();
        voirProfilFrame->setUser(user);
        voirProfilFrame->update();
        widgetCourant = voirProfilFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Votre profil");
    }
}

void AdministrateurScreen::on_modifier_profil_triggered()
{
    if(widgetCourant != modifierProfilFrame)
    {
        widgetCourant->deleteLater();
        ModifierProfilFrame *modifierProfilFrame = new ModifierProfilFrame();
        modifierProfilFrame->setUser(user);
        modifierProfilFrame->update();
        widgetCourant = modifierProfilFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Modification du profil");
    }
}

CreeCompteFrame *AdministrateurScreen::getCreeCompteFrame() const
{
    return creeCompteFrame;
}

void AdministrateurScreen::setCreeCompteFrame(CreeCompteFrame *value)
{
    creeCompteFrame = value;
}

void AdministrateurScreen::deconnexion()
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

void AdministrateurScreen::createActions()
{
    pSignalMapper = new QSignalMapper(this);
    connect(ui->menuD_connexion, SIGNAL(aboutToShow()), this, SLOT(deconnexion()));

}
