#ifndef VOIRPROFILFRAME_H
#define VOIRPROFILFRAME_H

#include <QFrame>
#include "dossieraccepteframe.h"

namespace Ui {
class VoirProfilFrame;
}

class VoirProfilFrame : public QFrame
{
    Q_OBJECT

public:
    explicit VoirProfilFrame(QWidget *parent = 0);
    ~VoirProfilFrame();

    Utilisateur getUser() const;
    void setUser(const Utilisateur &value);
    void update();


private slots:

private:
    Ui::VoirProfilFrame *ui;
    Utilisateur user;

};

#endif // VOIRPROFILFRAME_H
