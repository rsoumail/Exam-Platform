#ifndef HTTPDOWNLOADER_H
#define HTTPDOWNLOADER_H

#include <QObject>

#include <QHttpMultiPart>
#include <qhttpmultipart.h>
#include <QFile>

class HttpDownLoader : public QObject
{
    Q_OBJECT
public:
    explicit HttpDownLoader(QObject *parent = 0);

    void Do_Download();

signals:

public slots:
    //void stateChanged (int state);
    //void responseHeaderReceived (const QHttpResponseHeader& resp);
};

#endif // HTTPDOWNLOADER_H
