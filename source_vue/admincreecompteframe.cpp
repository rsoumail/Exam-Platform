#include "include_vue/admincreecompteframe.h"
#include "ui_admincreecompteframe.h"

AdminCreeCompteFrame::AdminCreeCompteFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::AdminCreeCompteFrame)
{
    ui->setupUi(this);
}

AdminCreeCompteFrame::~AdminCreeCompteFrame()
{
    delete ui;
}
