#include "fonctions.h"

QSqlDatabase dB()
{
    QString servername = "127.0.0.1";
    QString dbname = "exam";
    QString username = "root";
    QString password = "t0msris90";

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");

    db.setDatabaseName(dbname);
    db.setHostName(servername);
    db.setUserName(username);
    db.setPassword(password);

    return db;
}
