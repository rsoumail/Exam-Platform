#ifndef UPLOADMANAGER_H
#define UPLOADMANAGER_H

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

class UploadManager: public QObject
{
    Q_OBJECT
    QNetworkAccessManager manager;
    QList<QNetworkReply *> currentUploads;

public:
    UploadManager();
    void doUpload(QUrl &url, QString, QString, QString);
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
 //   #define URL_SERVEUR("http://localhost:8000/index.php")


public slots:
    void execute(QString chemin_fichier, QString type_fichier, QString nom_fichier, QString extension_fichier);
    void uploadFinished(QNetworkReply *reply);
    void sslErrors(const QList<QSslError> &errors);

private:

};


#endif // UPLOADMANAGER_H

