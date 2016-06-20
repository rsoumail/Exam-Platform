#ifndef ADMINLISTECOMPTEFRAME_H
#define ADMINLISTECOMPTEFRAME_H

#include <QFrame>
#include "creecompteframe.h"

namespace Ui {
class AdminListeCompteFrame;
}

class AdminListeCompteFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AdminListeCompteFrame(QWidget *parent = 0);
    ~AdminListeCompteFrame();

    Administrateur getUser() const;
    void setUser(const Administrateur &value);
    void lister();

private:
    Ui::AdminListeCompteFrame *ui;
    Administrateur user;
};

#endif // ADMINLISTECOMPTEFRAME_H
