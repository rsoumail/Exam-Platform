#include "monresultatframe.h"
#include "ui_monresultatframe.h"

MonResultatFrame::MonResultatFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MonResultatFrame)
{
    ui->setupUi(this);
}

MonResultatFrame::~MonResultatFrame()
{
    delete ui;
}

Candidat MonResultatFrame::getUser() const
{
    return user;
}

void MonResultatFrame::setUser(const Candidat &value)
{
    user = value;
}

void MonResultatFrame::update()
{
    ConcoursManager manager;
    Concours concour_actif = manager.actif();
    CandidatureManager candidatureManager;
    Candidature candidature = candidatureManager.actif(getUser().id());
    if(candidature.concours().annee() == concour_actif.annee())
    {
        DossierManager dossierManager;
        Dossier dossier = dossierManager.unique(candidature.id_dossier());
        if(dossier.statut() == 1)
        {
            ui->label_nom->setText(getUser().nom());
            ui->label_prenom->setText(getUser().prenom());
            ui->label_math->setText(QString::number(candidature.note_math()));
            ui->label_physique->setText(QString::number(candidature.note_physique()));
            ui->label_francais->setText(QString::number(candidature.note_francais()));
            ui->label_culture->setText(QString::number(candidature.note_culture_generale()));
            double moyenne = (candidature.note_math() + candidature.note_physique() + candidature.note_francais() +candidature.note_culture_generale()) / 4.0;
            ui->label_moyenne->setText(QString::number(moyenne));
            if(moyenne >= 10.0)
                ui->label_resultat->setText("Admis");
            else
                ui->label_resultat->setText("Récalé");

        }
    }
}
