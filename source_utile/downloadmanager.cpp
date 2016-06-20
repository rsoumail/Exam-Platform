#include <QCoreApplication>

#include "downloadmanager.h"

// constructor
DownloadManager::DownloadManager()
{
    // signal finish(), appel downloadFinished()
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(downloadFinished(QNetworkReply*)));
}

void DownloadManager::execute(QString chemin_fichier, int type_fichier)
{
        this->FILE_TYPE = type_fichier;
        QUrl url = QUrl::fromUserInput(DownloadManager::URL_SERVEUR + chemin_fichier);

        // lance la requete
        doDownload(url);
    }
}

// Constructs a QList of QNetworkReply
void DownloadManager::doDownload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList<QSslError>)));
#endif

    // List of reply
    currentDownloads.append(reply);
}

QString DownloadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();
    QString savename;
    if(this->FILE_TYPE == DownloadManager::CV_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + CV_CHEMIN + basename;
    }
    if(this->FILE_TYPE == DownloadManager::ACTE_NAISSANCE_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + ACTE_NAISSANCE_CHEMIN + basename;
    }
    if(this->FILE_TYPE == DownloadManager::PHOTO_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + PHOTO_CHEMIN + basename;
    }
    if(this->FILE_TYPE == DownloadManager::DIPLOME_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + DIPLOME_CHEMIN + basename;
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
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Téléchargement de %s echoué: %s\n",
                url.toEncoded().constData(),
                qPrintable(reply->errorString()));
    } else {
        QString filename = saveFileName(url);
        if (saveToDisk(filename, reply))
            printf("Téléchargement de %s reussi (enrégistré sous %s)\n",
                   url.toEncoded().constData(), qPrintable(filename));
    }

    currentDownloads.removeAll(reply);
    reply->deleteLater();

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


