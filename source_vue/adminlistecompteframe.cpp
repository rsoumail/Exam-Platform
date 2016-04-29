#include "include_vue/adminlistecompteframe.h"
#include "ui_adminlistecompteframe.h"

AdminListeCompteFrame::AdminListeCompteFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AdminListeCompteFrame)
{
    ui->setupUi(this);
}

AdminListeCompteFrame::~AdminListeCompteFrame()
{
    delete ui;
}
