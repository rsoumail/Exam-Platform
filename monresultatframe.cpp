#include "monresultatframe.h"
#include "ui_monresultatframe.h"

MonResultatFrame::MonResultatFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::MonResultatFrame)
{
    ui->setupUi(this);
}

MonResultatFrame::~MonResultatFrame()
{
    delete ui;
}
