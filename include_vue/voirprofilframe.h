#ifndef VOIRPROFILFRAME_H
#define VOIRPROFILFRAME_H

#include <QFrame>

namespace Ui {
class VoirProfilFrame;
}

class VoirProfilFrame : public QFrame
{
    Q_OBJECT

public:
    explicit VoirProfilFrame(QWidget *parent = 0);
    ~VoirProfilFrame();

private:
    Ui::VoirProfilFrame *ui;
};

#endif // VOIRPROFILFRAME_H
