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
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentDownloads;

public:
    DownloadManager();
    void doDownload(const QUrl &url);
    QString saveFileName(const QUrl &url);
    bool saveToDisk(const QString &filename, QIODevice *data);
    QString FILE_TYPE;
    QString URL_SERVEUR;
    #define CV_FILE ("1")
    #define ACTE_NAISSANCE_FILE ("2")
    #define PHOTO_FILE ("3")
    #define DIPLOME_FILE ("4")
    #define CV_CHEMIN ("Fichiers/CV/")
    #define ACTE_NAISSANCE_CHEMIN ("Fichiers/Actes_naissance/")
    #define PHOTO_CHEMIN ("Fichiers/Photos/")
    #define DIPLOME_CHEMIN ("Fichiers/Diplomes/")
    #define REPERTOIRE_FICHIER_CLIENT ("Client/")


public slots:
    void execute(QString, QString);
    void downloadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &errors);
};


#endif // DOWNLOADMANAGER_H
