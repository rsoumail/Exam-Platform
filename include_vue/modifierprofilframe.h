#ifndef MODIFIERPROFILFRAME_H
#define MODIFIERPROFILFRAME_H

#include <QFrame>

namespace Ui {
class ModifierProfilFrame;
}

class ModifierProfilFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ModifierProfilFrame(QWidget *parent = 0);
    ~ModifierProfilFrame();

private:
    Ui::ModifierProfilFrame *ui;
};

#endif // MODIFIERPROFILFRAME_H
