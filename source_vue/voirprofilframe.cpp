#include "include_vue/voirprofilframe.h"
#include "ui_voirprofilframe.h"

VoirProfilFrame::VoirProfilFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::VoirProfilFrame)
{
    ui->setupUi(this);
}

VoirProfilFrame::~VoirProfilFrame()
{
    delete ui;
}
