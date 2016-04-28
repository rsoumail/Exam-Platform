#ifndef DOSSIERREJETEFRAME_H
#define DOSSIERREJETEFRAME_H

#include <QFrame>
#include "listeadmisframe.h"
namespace Ui {
class Dossierrejeteframe;
}

class Dossierrejeteframe : public QFrame
{
    Q_OBJECT

public:
    explicit Dossierrejeteframe(QWidget *parent = 0);
    ~Dossierrejeteframe();

private:
    Ui::Dossierrejeteframe *ui;
};

#endif // DOSSIERREJETEFRAME_H
