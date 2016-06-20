#include <QCoreApplication>
#include <QUrlQuery>
#include <QHttpMultiPart>
#include <QFile>

#include "uploadmanager.h"

// constructor
UploadManager::UploadManager()
{
    // signal finish(), appel uploadFinished()
         this-> URL_SERVEUR  = "http://localhost:8000/index.php";
    connect(&manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(uploadFinished(QNetworkReply*)));
}

void UploadManager::execute(QString chemin_fichier, QString type_fichier, QString nom_fichier, QString extension_fichier)
{
        this->FILE_TYPE = type_fichier;
        QUrl url = QUrl::fromUserInput(this->URL_SERVEUR);

        // lance la requete
        doUpload(url, chemin_fichier, nom_fichier, extension_fichier);
}

// Constructs a QList of QNetworkReply
void UploadManager::doUpload(QUrl &url, QString chemin_fichier, QString nom_fichier, QString extension_fichier)
{
    //QUrlQuery query;
   // query.addQueryItem("type", FILE_TYPE);
    //query.addQueryItem("icone",nom_fichier);
    //url.setQuery(query);
    //query.addQueryItem("");

    QHttpMultiPart *multipart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart text_part;
    text_part.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("text/plain; charset=\"UTF-8\""));
    text_part.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"type\""));
    text_part.setBody(QByteArray(FILE_TYPE.toUtf8()));
    QHttpPart image_part;
    if(extension_fichier == "jpg")
        image_part.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("image/jpg; charset=\"UTF-8\""));
    else if(extension_fichier == "png")
        image_part.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("image/png; charset=\"UTF-8\""));
    image_part.setHeader(QNetworkRequest::ContentDispositionHeader,QVariant("form-data; name=\"file\"; filename=\""+nom_fichier+"\""));
    QFile *file = new QFile(chemin_fichier);
    if(!file->open(QIODevice::ReadOnly))
        return;
    image_part.setBodyDevice(file);
    qDebug() << "taille" << file->size();
    //image_part.setBodyDevice(file);
    file->setParent(multipart);
    multipart->append(text_part);
    multipart->append(image_part);


    QNetworkRequest request(url);
    QNetworkReply *reply = manager.post(request,multipart);
    multipart->setParent(reply);
    qDebug() << multipart->boundary();


#ifndef QT_NO_SSL
    connect(reply, SIGNAL(sslErrors(QList<QSslError>)), SLOT(sslErrors(QList<QSslError>)));
#endif

    // List of reply
    currentUploads.append(reply);
}

void UploadManager::uploadFinished(QNetworkReply *reply)
{
    QUrl url = reply->url();
    if (reply->error()) {
        fprintf(stderr, "Envoi de %s echoué:\n",
                url.toEncoded().constData());
    } else {
            printf("Envoie de %s reussi \n",
                   url.toEncoded().constData());
            qDebug () << reply->readAll();
    }

    currentUploads.removeAll(reply);
    reply->deleteLater();


    if (currentUploads.isEmpty()){
        this->disconnect(&manager, SIGNAL(finished(QNetworkReply*)),
                         this, SLOT(uploadFinished(QNetworkReply*)));
    this->destroyed();}

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
