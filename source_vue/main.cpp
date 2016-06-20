#include "connexion.h"
#include "register.h"
#include "candidatscreen.h"
#include "mondossierframe.h"
#include "administrateurscreen.h"
#include <QApplication>
#include <QStyle>
#include <QDesktopWidget>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion w;
    Register r;
    CandidatScreen sc;
    MonDossierFrame mdf;
    AdministrateurScreen adminScreen;

    w.setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            w.size(),
            qApp->desktop()->availableGeometry()
        )
    );


    w.setFixedSize(w.width(), w.height());

    w.setWindowFlags(Qt::WindowCloseButtonHint);

    w.show();
    return a.exec();
}
