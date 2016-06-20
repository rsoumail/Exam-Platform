#include <QCoreApplication>

#include "uploadmanager.h"

// constructor
UploadManager::UploadManager()
{
    // signal finish(), appel uploadFinished()
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(uploadFinished(QNetworkReply*)));
}

void UploadManager::execute(QString chemin_fichier, int type_fichier)
{
        this->FILE_TYPE = type_fichier;
        QUrl url = QUrl::fromUserInput(UploadManager::URL_SERVEUR + chemin_fichier);

        // lance la requete
        doUpload(url);
}

// Constructs a QList of QNetworkReply
void UploadManager::doUpload(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply *reply = manager.get(request);

#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList<QSslError>)));
#endif

    // List of reply
    currentUploads.append(reply);
}

QString UploadManager::saveFileName(const QUrl &url)
{
    QString path = url.path();
    QString basename = QFileInfo(path).fileName();
    QString savename;
    if(this->FILE_TYPE == UploadManager::CV_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + CV_CHEMIN + basename;
    }
    if(this->FILE_TYPE == UploadManager::ACTE_NAISSANCE_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + ACTE_NAISSANCE_CHEMIN + basename;
    }
    if(this->FILE_TYPE == UploadManager::PHOTO_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + PHOTO_CHEMIN + basename;
    }
    if(this->FILE_TYPE == UploadManager::DIPLOME_FILE)
    {
      savename = REPERTOIRE_FICHIER_CLIENT + DIPLOME_CHEMIN + basename;
    }

    if (savename.isEmpty())
        savename = "upload";

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

void UploadManager::uploadFinished(QNetworkReply *reply)
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

    currentUploads.removeAll(reply);
    reply->deleteLater();

}

bool UploadManager::saveToDisk(const QString &filename, QIODevice *reply)
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

void UploadManager::sslErrors(const QList<QSslError> &sslErrors)
{
#ifndef QT_NO_SSL
    foreach (const QSslError &error, sslErrors)
        fprintf(stderr, "Erreur SSL: %s\n", qPrintable(error.errorString()));
#else
    Q_UNUSED(sslErrors);
#endif
}


{

@QNetworkAccessManager *am = new QNetworkAccessManager(this);
QString path("E:\QT_playing\TestingHttpRequests\debug\Chrysanthemum.jpg");
QNetworkRequest request(QUrl("http://192.168.0.194/testuploads.php")); //our server with php-script

    QString bound="margin"; //name of the boundary
//according to rfc 1867 we need to put this string here:
QByteArray data(QString("--" + bound + "\r\n").toAscii());
data.append("Content-Disposition: form-data; name="action"\r\n\r\n");
data.append("index.php\r\n");
data.append("--" + bound + "\r\n"); //according to rfc 1867
data.append("Content-Disposition: form-data; name="uploaded"; filename="Chrysanthemum.jpg"\r\n"); //name of the input is "uploaded" in my form, next one is a file name.
data.append("Content-Type: image/jpeg\r\n\r\n"); //data type
QFile file(path);
if (!file.open(QIODevice::ReadOnly))
return;
data.append(file.readAll()); //let's read the file
data.append("\r\n");
data.append("--" + bound + "--\r\n"); //closing boundary according to rfc 1867
request.setRawHeader(QString("Content-Type").toAscii(),QString("multipart/form-data; boundary=" + bound).toAscii());
request.setRawHeader(QString("Content-Length").toAscii(), QString::number(data.length()).toAscii());
this->reply = am->post(request,data);
qDebug() << data.data();
connect(this->reply, SIGNAL(finished()), this, SLOT(replyFinished()));@
}
