#include "mondossierframe.h"
#include "ui_dossierrejeteframe.h"

Dossierrejeteframe::Dossierrejeteframe(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Dossierrejeteframe)
{
    ui->setupUi(this);
}

Dossierrejeteframe::~Dossierrejeteframe()
{
    delete ui;
}
