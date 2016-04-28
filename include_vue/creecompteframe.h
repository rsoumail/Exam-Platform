#ifndef CREECOMPTEFRAME_H
#define CREECOMPTEFRAME_H

#include <QFrame>

namespace Ui {
class CreeCompteFrame;
}

class CreeCompteFrame : public QFrame
{
    Q_OBJECT

public:
    explicit CreeCompteFrame(QWidget *parent = 0);
    ~CreeCompteFrame();

private:
    Ui::CreeCompteFrame *ui;
};

#endif // CREECOMPTEFRAME_H
