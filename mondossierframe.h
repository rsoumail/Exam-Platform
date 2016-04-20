#ifndef MONDOSSIERFRAME_H
#define MONDOSSIERFRAME_H

#include <QFrame>

namespace Ui {
class MonDossierFrame;
}

class MonDossierFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MonDossierFrame(QWidget *parent = 0);
    ~MonDossierFrame();

private:
    Ui::MonDossierFrame *ui;
};

#endif // MONDOSSIERFRAME_H
