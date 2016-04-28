#include "creecompteframe.h"
#include "ui_creecompteframe.h"

CreeCompteFrame::CreeCompteFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::CreeCompteFrame)
{
    ui->setupUi(this);
}

CreeCompteFrame::~CreeCompteFrame()
{
    delete ui;
}
