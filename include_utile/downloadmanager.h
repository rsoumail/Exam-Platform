#ifndef DOWNLOADMANAGER_H
#define DOWNLOADMANAGER_H

#include <QFile>
#include <QFileInfo>
#include <QList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSslError>
#include <QStringList>
#include <QTimer>
#include <QUrl>

#include <stdio.h>


class QSslError;

class DownloadManager: public QObject
{
    Q_OBJECT
    static const int CV_FILE = 1;
    static const int ACTE_NAISSANCE_FILE = 2;
    static const int PHOTO_FILE = 3;
    static const int DIPLOME_FILE = 4;
    static const QString CV_CHEMIN = "Fichiers/CV/";
    static const QString ACTE_NAISSANCE_CHEMIN = "Fichiers/Actes_naissance/";
    static const QString PHOTO_CHEMIN = "Fichiers/Photos/";
    static const QString DIPLOME_CHEMIN = "Fichiers/Diplomes/";
    static const QString URL_SERVEUR = "http://localhost:8000/";
    static const QString REPERTOIRE_FICHIER_CLIENT = "Client/";
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentDownloads;

public:
    DownloadManager();
    void doDownload(const QUrl &url);
    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    int FILE_TYPE;

public slots:
    void execute(QString, int);
    void downloadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &errors);
};


#endif // DOWNLOADMANAGER_H
