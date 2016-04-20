#include "connexion.h"
#include "register.h"
#include "candidatscreen.h"
#include "mondossierframe.h"
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
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

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

    QString servername = "127.0.0.1";
    QString dbname = "exam";
    QString username = "examadmin";
    QString password = "examkiadmin";


    db.setDatabaseName(dbname);
    db.setHostName(servername);
    db.setUserName(username);
    db.setPassword(password);

    return a.exec();
}
