#include "mondossierframe.h"
#include "ui_mondossierframe.h"
#include <QFileDialog>

MonDossierFrame::MonDossierFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MonDossierFrame)
{
    ui->setupUi(this);
}

MonDossierFrame::~MonDossierFrame()
{
    delete ui;
}

void MonDossierFrame::on_btn_acte_naissance_clicked()
{
    QString acte_naissance =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg)");
    ui->champ_acte_naissance->setText(acte_naissance);
}


void MonDossierFrame::on_btn_cv_clicked()
{
    QString cv =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.pdf *.jpg)");
    ui->champ_cv->setText(cv);
}


void MonDossierFrame::on_btn_photo_clicked()
{
    QString photo =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg)");
    ui->champ_photo->setText(photo);
}

void MonDossierFrame::on_btn_diplome_clicked()
{
    QString diplome =
        QFileDialog::getOpenFileName(this, "Selectionné un fichier", "directoryToOpen", "Images (*.png *.jpg *.pdf)");
    ui->champ_diplome->setText(diplome);
}
