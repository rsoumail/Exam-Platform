#include "register.h"
#include "connexion.h"
#include "ui_register.h"
#include <QDesktopWidget>

Register::Register(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);


}

Register::~Register()
{
    delete ui;
}


void Register::on_btn_connexion_clicked()
{
    Connexion *connexion = new Connexion();
    this->close();
    connexion->setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            connexion->size(),
            qApp->desktop()->availableGeometry()
        )
    );


    connexion->setFixedSize(connexion->width(), connexion->height());

    connexion->setWindowFlags(Qt::WindowCloseButtonHint);
    connexion->show();
}
