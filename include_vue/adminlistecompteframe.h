#ifndef ADMINLISTECOMPTEFRAME_H
#define ADMINLISTECOMPTEFRAME_H

#include <QFrame>

namespace Ui {
class AdminListeCompteFrame;
}

class AdminListeCompteFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AdminListeCompteFrame(QWidget *parent = 0);
    ~AdminListeCompteFrame();

private:
    Ui::AdminListeCompteFrame *ui;
};

#endif // ADMINLISTECOMPTEFRAME_H
