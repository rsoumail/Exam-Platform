#include "organisateurscreen.h"
#include "ui_organisateurscreen.h"
#include <QFileDialog>
#include "connexion.h"
#include <QDesktopWidget>

OrganisateurScreen::OrganisateurScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OrganisateurScreen)
{
    ui->setupUi(this);
    widgetCourant = orgInsFrame ;
    ui->horizontalLayout->addWidget(widgetCourant);
    createActions();
    this->windowTitleChanged("Liste des Inscriptions à validés");
}

OrganisateurScreen::~OrganisateurScreen()
{
    delete ui;
}

void OrganisateurScreen::on_actionFiche_notes_triggered()
{ 
    QString nom_fichier = QFileDialog::getSaveFileName(this, tr("Génération de fichier de notes"),
                               QDir::currentPath(),
                               tr(".xls (*.xls)"));
    QFile fichier(nom_fichier);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream sortie(&fichier);
    QString nu("Numéro");
    sortie << nu << ";" << QString::fromUtf8("Nom") << ";" << QString::fromUtf8("Prénom") << ";" << QString::fromUtf8("Mathématiques") << ";" << QString::fromUtf8("Physique")  << ";" << QString::fromUtf8("Français")  << ";" << QString::fromUtf8("Culture générale") << endl;
    DossierManager manager;
    QList<Dossier> l = manager.all_valide();
    for(int i=0;i<l.size();i++){
        CandidatureManager managerC;
        Candidat candidat = managerC.unique(l.at(i).candidature().id()).candidat();
        sortie << candidat.id() << ";" << candidat.nom() << ";" << candidat.prenom() << endl;
    }
    fichier.close();
}

void OrganisateurScreen::on_actionImporter_Notes_triggered()
{
    QString nom_fichier = QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", ".xls (*.xls)");
    QFile fichier(nom_fichier);
    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream entree(&fichier);
        QString line;
        QStringList listeChamps;
        line = entree.readLine();
        while(!entree.atEnd())
        {
          line = entree.readLine();
          listeChamps = line.split(",");
          QString id_candidat_str = listeChamps.at(0);
          int id_candidat = id_candidat_str.toInt();
          CandidatureManager candidatureManager;
          Candidature candidature =  candidatureManager.actif(id_candidat);
          QString math_str = listeChamps.at(3);
          double math = math_str.toDouble();
          candidature.setNote_math(math);
          QString physique_str = listeChamps.at(4);
          double physique = physique_str.toDouble();
          candidature.setNote_physique(physique);
          QString francais_str = listeChamps.at(5);
          double francais = francais_str.toDouble();
          candidature.setNote_francais(francais);
          QString culture_str = listeChamps.at(6);
          double culture = culture_str.toDouble();
          candidature.setNote_culture_generale(culture);
          CandidatureManager candidatureManager2;
          candidatureManager2  .update(candidature);
        }
        fichier.close();
    }
}

void OrganisateurScreen::on_actionNon_Valides_triggered()
{
    if(widgetCourant != orgInsFrame)
    {
        widgetCourant->deleteLater();
        OrganisateurInscriptionFrame *orgInsFrame = new OrganisateurInscriptionFrame();
        widgetCourant = orgInsFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Liste des inscriptions");
    }
}

void OrganisateurScreen::on_actionAccptes_triggered()
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

void OrganisateurScreen::on_actionRejetes_triggered()
{
    if(widgetCourant != dossierrejeteframe)
    {
        widgetCourant->deleteLater();
        Dossierrejeteframe *dossierrejeteframe = new Dossierrejeteframe();
        widgetCourant = dossierrejeteframe;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Dossiers Réjétés");
    }
}

void OrganisateurScreen::on_actionVoir_triggered()
{
    if(widgetCourant != voirProfilFrame)
    {
        widgetCourant->deleteLater();
        VoirProfilFrame *voirProfilFrame = new VoirProfilFrame();
        voirProfilFrame->setUser(user);
        voirProfilFrame->update();
        widgetCourant = voirProfilFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Vôtre profil");
    }
}

void OrganisateurScreen::on_actionModifier_triggered()
{
    if(widgetCourant != modifierProfilFrame)
    {
        widgetCourant->deleteLater();
        ModifierProfilFrame *modifierProfilFrame = new ModifierProfilFrame();
        modifierProfilFrame->setUser(user);
        modifierProfilFrame->update();
        widgetCourant = modifierProfilFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Modification de votre profil");
    }
}

void OrganisateurScreen::on_actionAfficher_triggered()
{
    if(widgetCourant != orgAffFrame)
    {
        widgetCourant->deleteLater();
        OrganisateurAfficherNotesFrame *orgAffFrame = new OrganisateurAfficherNotesFrame();
        widgetCourant = orgAffFrame;
        ui->horizontalLayout->addWidget(widgetCourant);
        this->setWindowTitle("Notes");
    }
}

OrganisateurInscriptionFrame *OrganisateurScreen::getOrgInsFrame() const
{
    return orgInsFrame;
}

void OrganisateurScreen::setOrgInsFrame(OrganisateurInscriptionFrame *value)
{
    orgInsFrame = value;
}

Organisateur OrganisateurScreen::getUser() const
{
    return user;
}

void OrganisateurScreen::setUser(const Organisateur &value)
{
    user = value;
}


void OrganisateurScreen::deconnexion()
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

void OrganisateurScreen::createActions()
{
    pSignalMapper = new QSignalMapper(this);
    connect(ui->menuDeconnexion, SIGNAL(aboutToShow()), this, SLOT(deconnexion()));

}

void OrganisateurScreen::on_actionVoir_les_admis_triggered()
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

void OrganisateurScreen::on_actionVoir_les_recal_s_triggered()
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
