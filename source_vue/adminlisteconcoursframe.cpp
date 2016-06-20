#include "include_vue/adminlisteconcoursframe.h"
#include "ui_adminlisteconcoursframe.h"
#include "fonctions.h"
#include <QStandardItemModel>

AdminListeConcoursFrame::AdminListeConcoursFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AdminListeConcoursFrame)
{
    ui->setupUi(this);

    ConcoursManager manager;
    QList<Concours> l = manager.all();
    QStringList header;
    header << "N" << "Année" << "Age Limite" << "Date Limite" << "Date Resultats" << "Statut";
    QStandardItemModel *model= new QStandardItemModel(l.size(),6,this);
            model->setHorizontalHeaderLabels(header);
            ui->table_liste_concours->setModel(model);
            ui->table_liste_concours->horizontalHeader()->setStretchLastSection(true);
            ui->table_liste_concours->resizeRowsToContents();
            ui->table_liste_concours->verticalHeader()->hide();
            ui->table_liste_concours->setSortingEnabled(false);
            ui->table_liste_concours->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table_liste_concours->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table_liste_concours->setSelectionMode(QAbstractItemView::SingleSelection);
            for(int i=0;i<l.size();i++){
                QString num = QString::number(l.at(i).id());
                QStandardItem * id= new QStandardItem(num);
                QStandardItem * annee= new QStandardItem(l.at(i).annee());
                QString age_li = QString::number(l.at(i).age_limite());
                QStandardItem * age_limite= new QStandardItem(age_li);
                QStandardItem * date_limite= new QStandardItem(l.at(i).date_limite());
                QStandardItem * date_resultat= new QStandardItem(l.at(i).date_resultats());
                QStandardItem * statut;
                if(l.at(i).statut() == 0)
                    statut= new QStandardItem("Terminé");
                else
                    statut= new QStandardItem("En cours");

                model->setItem(i,0,id);
                model->setItem(i,1,annee);
                model->setItem(i,2,age_limite);
                model->setItem(i,3,date_limite);
                model->setItem(i,4,date_resultat);
                model->setItem(i,5,statut);
            }

    //connect(ui->table_liste_concours, SIGNAL(clicked(const QModelIndex&)), this, SLOT(recordSelected(model)));


}

AdminListeConcoursFrame::~AdminListeConcoursFrame()
{
    delete ui;
}

Administrateur AdminListeConcoursFrame::getUser() const
{
    return user;
}

void AdminListeConcoursFrame::setUser(const Administrateur &value)
{
    user = value;
}

void AdminListeConcoursFrame::recordSelected(QSqlTableModel *model)
{
       QModelIndex index = ui->table_liste_concours->currentIndex();
       QSqlRecord record;
       int i = index.row();
       record = model->record(i);
       qDebug() << record;
}


void AdminListeConcoursFrame::on_table_liste_concours_clicked(const QModelIndex &index)
{
    QSqlRecord record;
    int i = index.row();
    //record = ui->table_liste_concours->model()->data(index);
    qDebug() << ui->table_liste_concours->model()->data(index);
}
