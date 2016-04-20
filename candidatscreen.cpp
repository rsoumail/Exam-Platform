#include "candidatscreen.h"
#include "ui_candidatscreen.h"

CandidatScreen::CandidatScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CandidatScreen)
{
    ui->setupUi(this);
}

CandidatScreen::~CandidatScreen()
{
    delete ui;
}
