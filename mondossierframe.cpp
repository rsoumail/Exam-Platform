#include "mondossierframe.h"
#include "ui_mondossierframe.h"

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
