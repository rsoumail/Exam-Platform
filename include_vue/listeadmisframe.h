#ifndef LISTEADMISFRAME_H
#define LISTEADMISFRAME_H

#include <QFrame>
#include "listeechouesframe.h"
namespace Ui {
class LIsteAdmisFrame;
}

class LIsteAdmisFrame : public QFrame
{
    Q_OBJECT

public:
    explicit LIsteAdmisFrame(QWidget *parent = 0);
    ~LIsteAdmisFrame();

private:
    Ui::LIsteAdmisFrame *ui;
};

#endif // LISTEADMISFRAME_H
