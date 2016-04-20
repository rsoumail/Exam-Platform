#ifndef MONRESULTATFRAME_H
#define MONRESULTATFRAME_H

#include <QFrame>

namespace Ui {
class MonResultatFrame;
}

class MonResultatFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MonResultatFrame(QWidget *parent = 0);
    ~MonResultatFrame();

private:
    Ui::MonResultatFrame *ui;
};

#endif // MONRESULTATFRAME_H
