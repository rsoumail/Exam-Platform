#include "demandescandidatureframe.h"
#include "ui_demandescandidatureframe.h"

DemandesCandidatureFrame::DemandesCandidatureFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::DemandesCandidatureFrame)
{
    ui->setupUi(this);
}

DemandesCandidatureFrame::~DemandesCandidatureFrame()
{
    delete ui;
}
