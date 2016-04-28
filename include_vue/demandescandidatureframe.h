#ifndef DEMANDESCANDIDATUREFRAME_H
#define DEMANDESCANDIDATUREFRAME_H

#include <QFrame>

namespace Ui {
class DemandesCandidatureFrame;
}

class DemandesCandidatureFrame : public QFrame
{
    Q_OBJECT

public:
    explicit DemandesCandidatureFrame(QWidget *parent = 0);
    ~DemandesCandidatureFrame();

private:
    Ui::DemandesCandidatureFrame *ui;
};

#endif // DEMANDESCANDIDATUREFRAME_H
