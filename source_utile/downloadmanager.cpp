#include <QCoreApplication>
#include "downloadmanager.h"

// constructor
DownloadManager::DownloadManager()
{
    // signal finish(), appel downloadFinished()
    this->URL_SERVEUR  = "http://localhost:8000/";
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished(QNetworkReply*)));
    connect(&manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::execute(QString chemin_fichier, QString type_fichier)
{
        this->FILE_TYPE = type_fichier;
        QUrl url = QUrl::fromUserInput(URL_SERVEUR.toUtf8());
        // lance la requete
        doDownload(url);
}

// Constructs a QList of QNetworkReply
void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);


#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this,  SLOT(sslErrors(QList<QSslError>)));
#endif

    // List of reply
    currentDownloads.append(reply);

}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();
    QString savename;
    QString repertoire(REPERTOIRE_FICHIER_CLIENT);
    if(this->FILE_TYPE == CV_FILE)
    {
      savename = repertoire.append(CV_CHEMIN).append(basename);
    }
    if(this->FILE_TYPE == ACTE_NAISSANCE_FILE)
    {
      savename = repertoire.append(ACTE_NAISSANCE_CHEMIN).append(basename);
    }
    if(this->FILE_TYPE == PHOTO_FILE)
    {
      savename = repertoire.append(PHOTO_CHEMIN ).append(basename);
    }
    if(this->FILE_TYPE == DIPLOME_FILE)
    {
      savename = repertoire.append(DIPLOME_CHEMIN ).append(basename);
    }

    if (savename.isEmpty())
        savename = "download";

    if (QFile::exists(savename)) {
        // si un fichier pourtant le meme nom existait deja
        int i = 0;
        savename += '.';
        while (QFile::exists(savename + QString::number(i)))
            ++i;

        savename += QString::number(i);
    }

    return savename;
}

void DownloadManager::downloadFinished(QNetworkReply *reply)
{
    qDebug() << "fished";
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Download of %s failed: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
            printf("Download of %s succeeded (saved to %s)\n",
                   url.toEncoded().constData(), qPrintable(filename));
    }

    currentDownloads.removeAll(reply);
    reply->deleteLater();

  /*if(currentDownloads.isEmpty()){
        this->disconnect(&manager, SIGNAL(finished(QNetworkReply*)),
                         this, SLOT(downloadFinished(QNetworkReply*)));
  }*/

}

bool DownloadManager::saveToDisk(const QString &filename, QIODevice *reply)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        fprintf(stderr, "Impossible d' ouvrir %s pour sauvegarder: %s\n",
                qPrintable(filename),
                qPrintable(file.errorString()));
        return false;
    }

    file.write(reply->readAll());
    file.close();

    return true;
}

void DownloadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#ifndef QT_NO_SSL
    foreach (const QSslError &error, sslErrors)
        fprintf(stderr, "Erreur SSL: %s\n", qPrintable(error.errorString()));
#else
    Q_UNUSED(sslErrors);
#endif
}


