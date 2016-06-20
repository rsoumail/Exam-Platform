#include "mondossierframe.h"
#include "ui_listeadmisframe.h"
#include <QStandardItemModel>
#include "fonctions.h"

LIsteAdmisFrame::LIsteAdmisFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::LIsteAdmisFrame)
{
    ui->setupUi(this);
    CandidatureManager manager;
    QList<Candidature> l = manager.liste_admis();
    QStringList header;
    header << "Numéro" << "Nom" << "Prénom" << "Mathématiques" << "Physique" << "Francais" << "Culture Générale" << "Moyenne" << "Décision" ;
    QStandardItemModel *model= new QStandardItemModel(l.size(),9,this);
            model->setHorizontalHeaderLabels(header);
            ui->table_admis->setModel(model);
            ui->table_admis->horizontalHeader()->setStretchLastSection(true);
            ui->table_admis->resizeColumnsToContents();
            ui->table_admis->resizeRowsToContents();
            ui->table_admis->verticalHeader()->hide();
            ui->table_admis->setSortingEnabled(false);
            ui->table_admis->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table_admis->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table_admis->setSelectionMode(QAbstractItemView::SingleSelection);
            for(int i=0;i<l.size();i++){
                    double moyen = (l.at(i).note_math() + l.at(i).note_physique() + l.at(i).note_francais() + l.at(i).note_culture_generale())/ 4.0;
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
                    QString moy = QString::number(moyen);
                    QStandardItem * moyenne= new QStandardItem(moy);
                    QStandardItem * resultat= new QStandardItem("Admis");
                    model->setItem(i,0,id);
                    model->setItem(i,1,nom);
                    model->setItem(i,2,prenom);
                    model->setItem(i,3,math);
                    model->setItem(i,4,physique);
                    model->setItem(i,5,francais);
                    model->setItem(i,6,culture);
                    model->setItem(i,7,moyenne);
                    model->setItem(i,8,resultat);
                    ui->table_admis->resizeRowsToContents();
                    ui->table_admis->resizeColumnsToContents();
          }

}

LIsteAdmisFrame::~LIsteAdmisFrame()
{
    delete ui;
}

void LIsteAdmisFrame::on_click_impression()
{
    imprimer(ui->table_admis);
}
