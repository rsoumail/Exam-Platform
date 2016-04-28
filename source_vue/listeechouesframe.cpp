#include "mondossierframe.h"
#include "ui_listeechouesframe.h"

ListeEchouesFrame::ListeEchouesFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::ListeEchouesFrame)
{
    ui->setupUi(this);
}

ListeEchouesFrame::~ListeEchouesFrame()
{
    delete ui;
}
