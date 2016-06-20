#include "include_vue/organisteurvalidationframe.h"
#include "ui_organisteurvalidationframe.h"

OrganisteurValidationFrame::OrganisteurValidationFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::OrganisteurValidationFrame)
{
    ui->setupUi(this);
}

OrganisteurValidationFrame::~OrganisteurValidationFrame()
{
    delete ui;
}

Dossier OrganisteurValidationFrame::getDossier_a_modifier() const
{
    return dossier_a_modifier;
}

void OrganisteurValidationFrame::setDossier_a_modifier(const Dossier &value)
{
    dossier_a_modifier = value;
}
