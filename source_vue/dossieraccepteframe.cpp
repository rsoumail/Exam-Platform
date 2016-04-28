#include "mondossierframe.h"
#include "ui_dossieraccepteframe.h"

DossierAccepteFrame::DossierAccepteFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DossierAccepteFrame)
{
    ui->setupUi(this);



}

DossierAccepteFrame::~DossierAccepteFrame()
{
    delete ui;
}
