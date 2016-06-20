#ifndef MODIFIERPROFILFRAME_H
#define MODIFIERPROFILFRAME_H

#include <QFrame>
#include "voirprofilframe.h"

namespace Ui {
class ModifierProfilFrame;
}

class ModifierProfilFrame : public QFrame
{
    Q_OBJECT

public:
    explicit ModifierProfilFrame(QWidget *parent = 0);
    ~ModifierProfilFrame();

    Utilisateur getUser() const;
    void setUser(const Utilisateur &value);

    void update();

private slots:
    void on_btn_inscription_clicked();

private:
    Ui::ModifierProfilFrame *ui;
    Utilisateur user;
};

#endif // MODIFIERPROFILFRAME_H
