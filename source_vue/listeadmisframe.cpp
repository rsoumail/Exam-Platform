#include "mondossierframe.h"
#include "ui_listeadmisframe.h"

LIsteAdmisFrame::LIsteAdmisFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::LIsteAdmisFrame)
{
    ui->setupUi(this);
}

LIsteAdmisFrame::~LIsteAdmisFrame()
{
    delete ui;
}
