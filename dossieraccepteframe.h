#ifndef DOSSIERACCEPTEFRAME_H
#define DOSSIERACCEPTEFRAME_H

#include <QFrame>

namespace Ui {
class DossierAccepteFrame;
}

class DossierAccepteFrame : public QFrame
{
    Q_OBJECT

public:
    explicit DossierAccepteFrame(QWidget *parent = 0);
    ~DossierAccepteFrame();

private:
    Ui::DossierAccepteFrame *ui;
};

#endif // DOSSIERACCEPTEFRAME_H
