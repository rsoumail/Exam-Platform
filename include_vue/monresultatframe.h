#ifndef MONRESULTATFRAME_H
#define MONRESULTATFRAME_H

#include <QFrame>
#include "mondossierframe.h"
namespace Ui {
class MonResultatFrame;
}

class MonResultatFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MonResultatFrame(QWidget *parent = 0);
    ~MonResultatFrame();

    Candidat getUser() const;
    void setUser(const Candidat &value);

    void update();

private:
    Ui::MonResultatFrame *ui;
    Candidat user;
};

#endif // MONRESULTATFRAME_H
