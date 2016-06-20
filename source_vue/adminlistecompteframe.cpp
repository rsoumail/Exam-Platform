#include "include_vue/adminlistecompteframe.h"
#include "ui_adminlistecompteframe.h"
#include <QStandardItemModel>

AdminListeCompteFrame::AdminListeCompteFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AdminListeCompteFrame)
{
    ui->setupUi(this);
    lister();

}

AdminListeCompteFrame::~AdminListeCompteFrame()
{
    delete ui;
}

Administrateur AdminListeCompteFrame::getUser() const
{
    return user;
}

void AdminListeCompteFrame::setUser(const Administrateur &value)
{
    user = value;
}

void AdminListeCompteFrame::lister()
{

    AdministrateurManager manager1;
    QList<Administrateur> l1 = manager1.all();
    CandidatManager manager2;
    QList<Candidat> l2 = manager2.all();
    OrganisateurManager manager3;
    QList<Organisateur> l3 = manager3.all();
    QStringList header;
    header << "N" << "Pseudo" << "Nom" << "Prénom" << "Date Naissance" << "Sexe" << "Civilité" << "Nationalité" << "Adresse" << "Téléphone" << "Email" << "Groupe" ;
    QStandardItemModel *model= new QStandardItemModel((l1.size()+l2.size()+l3.size()),12,this);
            model->setHorizontalHeaderLabels(header);
            ui->table->setModel(model);
            ui->table->horizontalHeader()->setStretchLastSection(true);
            ui->table->resizeRowsToContents();
            ui->table->verticalHeader()->hide();
            ui->table->setSortingEnabled(false);
            ui->table->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table->setSelectionMode(QAbstractItemView::SingleSelection);
            for(int i=0;i<l1.size();i++){
                QString num = QString::number(l1.at(i).id());
                QStandardItem * id= new QStandardItem(num);
                QStandardItem * pseudo= new QStandardItem(l1.at(i).pseudo());
                QStandardItem * nom= new QStandardItem(l1.at(i).nom());
                QStandardItem * prenom= new QStandardItem(l1.at(i).prenom());
                QStandardItem * date_naissance= new QStandardItem(l1.at(i).date_naissance());
                QStandardItem * sexe;
                if(l1.at(i).sexe() == "f")
                    sexe= new QStandardItem("Féminin");
                else
                    sexe= new QStandardItem("Masculin");
                QStandardItem * civilite= new QStandardItem(l1.at(i).civilite());
                QStandardItem * nationalite= new QStandardItem(l1.at(i).nationalite());
                QStandardItem * adresse= new QStandardItem(l1.at(i).adresse());
                QStandardItem * telephone= new QStandardItem(l1.at(i).telephone());
                QStandardItem * email= new QStandardItem(l1.at(i).email());
                QStandardItem * groupe= new QStandardItem(l1.at(i).groupe().nom());
                model->setItem(i,0,id);
                model->setItem(i,1,pseudo);
                model->setItem(i,2,nom);
                model->setItem(i,3,prenom);
                model->setItem(i,4,date_naissance);
                model->setItem(i,5,sexe);
                model->setItem(i,6,civilite);
                model->setItem(i,7,nationalite);
                model->setItem(i,8,adresse);
                model->setItem(i,9,telephone);
                model->setItem(i,10,email);
                model->setItem(i,11,groupe);
                ui->table->resizeRowsToContents();
                ui->table->resizeColumnsToContents();
            }
            int lignecompte2 = l1.size();
            for(int i=0;i<l2.size();i++){
                QString num = QString::number(l2.at(i).id());
                QStandardItem * id= new QStandardItem(num);
                QStandardItem * pseudo= new QStandardItem(l2.at(i).pseudo());
                QStandardItem * nom= new QStandardItem(l2.at(i).nom());
                QStandardItem * prenom= new QStandardItem(l2.at(i).prenom());
                QStandardItem * date_naissance= new QStandardItem(l2.at(i).date_naissance());
                QStandardItem * sexe;
                if(l2.at(i).sexe() == "f")
                    sexe= new QStandardItem("Féminin");
                else
                    sexe= new QStandardItem("Masculin");
                QStandardItem * civilite= new QStandardItem(l2.at(i).civilite());
                QStandardItem * nationalite= new QStandardItem(l2.at(i).nationalite());
                QStandardItem * adresse= new QStandardItem(l2.at(i).adresse());
                QStandardItem * telephone= new QStandardItem(l2.at(i).telephone());
                QStandardItem * email= new QStandardItem(l2.at(i).email());
                QStandardItem * groupe= new QStandardItem(l2.at(i).groupe().nom());
                model->setItem(i+lignecompte2,0,id);
                model->setItem(i+lignecompte2,1,pseudo);
                model->setItem(i+lignecompte2,2,nom);
                model->setItem(i+lignecompte2,3,prenom);
                model->setItem(i+lignecompte2,4,date_naissance);
                model->setItem(i+lignecompte2,5,sexe);
                model->setItem(i+lignecompte2,6,civilite);
                model->setItem(i+lignecompte2,7,nationalite);
                model->setItem(i+lignecompte2,8,adresse);
                model->setItem(i+lignecompte2,9,telephone);
                model->setItem(i+lignecompte2,10,email);
                model->setItem(i+lignecompte2,11,groupe);
                ui->table->resizeRowsToContents();
                ui->table->resizeColumnsToContents();
            }
            int lignecompte3 = l2.size();
            for(int i=0;i<l3.size();i++){
                QString num = QString::number(l3.at(i).id());
                QStandardItem * id= new QStandardItem(num);
                QStandardItem * pseudo= new QStandardItem(l3.at(i).pseudo());
                QStandardItem * nom= new QStandardItem(l3.at(i).nom());
                QStandardItem * prenom= new QStandardItem(l3.at(i).prenom());
                QStandardItem * date_naissance= new QStandardItem(l3.at(i).date_naissance());
                QStandardItem * sexe;
                if(l3.at(i).sexe() == "f")
                    sexe= new QStandardItem("Féminin");
                else
                    sexe= new QStandardItem("Masculin");
                QStandardItem * civilite= new QStandardItem(l3.at(i).civilite());
                QStandardItem * nationalite= new QStandardItem(l3.at(i).nationalite());
                QStandardItem * adresse= new QStandardItem(l3.at(i).adresse());
                QStandardItem * telephone= new QStandardItem(l3.at(i).telephone());
                QStandardItem * email= new QStandardItem(l3.at(i).email());
                QStandardItem * groupe= new QStandardItem(l3.at(i).groupe().nom());
                model->setItem(i+lignecompte3,0,id);
                model->setItem(i+lignecompte3,1,pseudo);
                model->setItem(i+lignecompte3,2,nom);
                model->setItem(i+lignecompte3,3,prenom);
                model->setItem(i+lignecompte3,4,date_naissance);
                model->setItem(i+lignecompte3,5,sexe);
                model->setItem(i+lignecompte3,6,civilite);
                model->setItem(i+lignecompte3,7,nationalite);
                model->setItem(i+lignecompte3,8,adresse);
                model->setItem(i+lignecompte3,9,telephone);
                model->setItem(i+lignecompte3,10,email);
                model->setItem(i+lignecompte3,11,groupe);
                ui->table->resizeRowsToContents();
                ui->table->resizeColumnsToContents();
            }
}
