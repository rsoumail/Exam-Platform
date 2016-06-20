#include "include_vue/organisateuraffichernotesframe.h"
#include "ui_organisateuraffichernotesframe.h"
#include <QStandardItemModel>

OrganisateurAfficherNotesFrame::OrganisateurAfficherNotesFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OrganisateurAfficherNotesFrame)
{
    ui->setupUi(this);
    ConcoursManager concoursManager;
    Concours concour_actif = concoursManager.actif();
    CandidatureManager manager;
    QList<Candidature> l = manager.all_accepte(concour_actif.id());
    QStringList header;
    header << "Numéro" << "Nom" << "Prénom" << "Mathématiques" << "Physique" << "Francais" << "Culture Générale" << "Moyenne" ;
    QStandardItemModel *model= new QStandardItemModel(l.size(),8,this);
            model->setHorizontalHeaderLabels(header);
            ui->table_notes->setModel(model);
            ui->table_notes->horizontalHeader()->setStretchLastSection(true);
            ui->table_notes->resizeRowsToContents();
            ui->table_notes->verticalHeader()->hide();
            ui->table_notes->setSortingEnabled(false);
            ui->table_notes->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table_notes->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table_notes->setSelectionMode(QAbstractItemView::SingleSelection);
            for(int i=0;i<l.size();i++){
                QString numero = QString::number(l.at(i).id());
                QStandardItem * id= new QStandardItem(numero);
                QStandardItem * nom= new QStandardItem(l.at(i).candidat().nom());
                QStandardItem * prenom= new QStandardItem(l.at(i).candidat().prenom());
                QString ma = QString::number(l.at(i).note_math());
                QStandardItem * math= new QStandardItem(ma);
                QString phy = QString::number(l.at(i).note_physique());
                QStandardItem * physique= new QStandardItem(phy);
                QString fr = QString::number(l.at(i).note_francais());
                QStandardItem * francais= new QStandardItem(fr);
                QString cul = QString::number(l.at(i).note_culture_generale());
                QStandardItem * culture= new QStandardItem(cul);
                double moyen = (l.at(i).note_math() + l.at(i).note_physique() + l.at(i).note_francais() +l.at(i).note_culture_generale())/ 4.0;
                QString moy = QString::number(moyen);
                QStandardItem * moyenne= new QStandardItem(moy);
                model->setItem(i,0,id);
                model->setItem(i,1,nom);
                model->setItem(i,2,prenom);
                model->setItem(i,3,math);
                model->setItem(i,4,physique);
                model->setItem(i,5,francais);
                model->setItem(i,6,culture);
                model->setItem(i,7,moyenne);
                ui->table_notes->resizeRowsToContents();
                ui->table_notes->resizeColumnsToContents();
            }

}

OrganisateurAfficherNotesFrame::~OrganisateurAfficherNotesFrame()
{
    delete ui;
}
