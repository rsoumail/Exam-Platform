#ifndef CREECOMPTEFRAME_H
#define CREECOMPTEFRAME_H

#include <QFrame>
#include "modifierprofilframe.h"

namespace Ui {
class CreeCompteFrame;
}

class CreeCompteFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CreeCompteFrame(QWidget *parent = 0);
    ~CreeCompteFrame();

    Administrateur getUser() const;
    void setUser(const Administrateur &value);

private slots:
    void on_btn_inscription_clicked();

private:
    Ui::CreeCompteFrame *ui;
    Administrateur user;
};

#endif // CREECOMPTEFRAME_H
