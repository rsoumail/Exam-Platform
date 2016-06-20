#include "include_vue/organisateuraffichernotesframe.h"
#include "ui_organisateuraffichernotesframe.h"

OrganisateurAfficherNotesFrame::OrganisateurAfficherNotesFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OrganisateurAfficherNotesFrame)
{
    ui->setupUi(this);
}

OrganisateurAfficherNotesFrame::~OrganisateurAfficherNotesFrame()
{
    delete ui;
}
