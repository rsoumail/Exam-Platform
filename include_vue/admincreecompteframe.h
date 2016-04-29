#ifndef ADMINCREECOMPTEFRAME_H
#define ADMINCREECOMPTEFRAME_H

#include <QFrame>

namespace Ui {
class AdminCreeCompteFrame;
}

class AdminCreeCompteFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AdminCreeCompteFrame(QWidget *parent = 0);
    ~AdminCreeCompteFrame();

private:
    Ui::AdminCreeCompteFrame *ui;
};

#endif // ADMINCREECOMPTEFRAME_H
