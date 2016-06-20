#include "include_vue/organisateurinscriptionframe.h"
#include "ui_organisateurinscriptionframe.h"
#include <QStandardItemModel>
#include "filedownloader.h"

OrganisateurInscriptionFrame::OrganisateurInscriptionFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OrganisateurInscriptionFrame)
{
    ui->setupUi(this);
    lister();
}

void OrganisateurInscriptionFrame::onTableCellClicked(const QModelIndex &index)
{
    int ligne = index.row();
    QString id_str = index.sibling(ligne, 0).data().toString();
    int id = id_str.toInt();
    ui->table_inscriptions->hide();
    ui->groupBox->show();
    DossierManager dossierManager;
    dossier_a_modidfier = dossierManager.unique(id);
    ui->champ_nom_3->setText(index.sibling(ligne, 1).data().toString());
    ui->champ_prenom_3->setText(index.sibling(ligne, 2).data().toString());

    QUrl imageUrl("http://localhost:8000/Fichiers/Photos/"+dossier_a_modidfier.photo());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

OrganisateurInscriptionFrame::~OrganisateurInscriptionFrame()
{
    delete ui;
}


void OrganisateurInscriptionFrame::on_btn_retour_2_clicked()
{
    ui->table_inscriptions->show();
    ui->groupBox->hide();
}

void OrganisateurInscriptionFrame::on_bnt_voir_photo_clicked()
{
    QUrl imageUrl("http://localhost:8000/Fichiers/Photos/"+dossier_a_modidfier.photo());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void OrganisateurInscriptionFrame::on_btn_voir_acte_naissance_3_clicked()
{
    QUrl imageUrl("http://localhost:8000/Fichiers/Actes_naissance/"+dossier_a_modidfier.acte_naissance());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void OrganisateurInscriptionFrame::on_btn_voir_cv_3_clicked()
{
    QUrl imageUrl("http://localhost:8000/Fichiers/CV/"+dossier_a_modidfier.cv());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void OrganisateurInscriptionFrame::on_btn_voir_diplome_3_clicked()
{
    QUrl imageUrl("http://localhost:8000/Fichiers/Diplomes/"+dossier_a_modidfier.diplome());
    m_pImgCtrl = new FileDownloader(imageUrl, this);

    connect(m_pImgCtrl, SIGNAL (downloaded()), this, SLOT (loadImage()));
}

void OrganisateurInscriptionFrame::on_btn_accepte_2_clicked()
{
    dossier_a_modidfier.setA_traiter(0);
    dossier_a_modidfier.setStatut(1);
    DossierManager manager;
    manager.update(dossier_a_modidfier);
    ui->table_inscriptions->show();
    lister();
}

void OrganisateurInscriptionFrame::on_btn_rejete_2_clicked()
{
    dossier_a_modidfier.setA_traiter(0);
    dossier_a_modidfier.setStatut(0);
    DossierManager manager;
    manager.update(dossier_a_modidfier);
    ui->table_inscriptions->show();
    lister();
}

void OrganisateurInscriptionFrame::lister()
{
    this->setWindowTitle("Vérification des dossiers");
    ui->groupBox->hide();
    DossierManager manager;
    QList<Dossier> l = manager.all_non_traiter();
    QStringList header;
    header << "Numéro dossier" << "Nom" << "Prénom" << "Age" << "Acte de naissance" << "CV" << "Diplôme" << "Photo";
    QStandardItemModel *model= new QStandardItemModel(l.size(),8,this);
            model->setHorizontalHeaderLabels(header);
            ui->table_inscriptions->setModel(model);
            ui->table_inscriptions->horizontalHeader()->setStretchLastSection(true);
            ui->table_inscriptions->resizeColumnsToContents();
            ui->table_inscriptions->resizeRowsToContents();
            ui->table_inscriptions->verticalHeader()->hide();
            ui->table_inscriptions->setSortingEnabled(false);
            ui->table_inscriptions->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->table_inscriptions->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->table_inscriptions->setSelectionMode(QAbstractItemView::SingleSelection);
            for(int i=0;i<l.size();i++){
                QString num = QString::number(l.at(i).id());
                QStandardItem * id= new QStandardItem(num);
                QStringList lcv = l.at(i).cv().split("/");
                QStandardItem * cv= new QStandardItem(lcv.at(lcv.size()-1));
                QStringList lphoto = l.at(i).photo().split("/");
                QStandardItem * photo= new QStandardItem(lphoto.at(lphoto.size()-1));
                QStringList ldip = l.at(i).diplome().split("/");
                QStandardItem * diplome= new QStandardItem(ldip.at(ldip.size()-1));
                QStringList lacte = l.at(i).acte_naissance().split("/");
                QStandardItem * acte_naissance= new QStandardItem(lacte.at(lacte.size()-1));
                Candidature candidature = l.at(i).candidature();
                Candidat candidat = candidature.candidat();
                QStandardItem * nom= new QStandardItem(candidat.nom());
                QStandardItem * prenom= new QStandardItem(candidat.prenom());
                QStringList datetab = candidat.date_naissance().split("/");
                Concours concours = candidature.concours();
                QString annee = datetab.at(datetab.size()-1);
                int a = concours.annee().toInt() - annee.toInt();
                QString ag = QString::number(a);
                QStandardItem * age= new QStandardItem(ag);
                model->setItem(i,0,id);
                model->setItem(i,1,nom);
                model->setItem(i,2,prenom);
                model->setItem(i,3,age);
                model->setItem(i,4,acte_naissance);
                model->setItem(i,5,cv);
                model->setItem(i,6,diplome);
                model->setItem(i,7,photo);
                ui->table_inscriptions->resizeColumnsToContents();
                ui->table_inscriptions->resizeRowsToContents();
            }
}

void OrganisateurInscriptionFrame::loadImage()
{
     QImage image;
     image.loadFromData(m_pImgCtrl->downloadedData());
     image = image.scaledToWidth(ui->label_visionneuse_2->width(), Qt::SmoothTransformation);
     image = image.scaledToHeight(ui->label_visionneuse_2->height(), Qt::SmoothTransformation);
     ui->label_visionneuse_2->setPixmap(QPixmap::fromImage(image));
}
