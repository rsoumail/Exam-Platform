#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include "register.h"
#include "candidatscreen.h"

namespace Ui {
class Connexion;
}

class Connexion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = 0);
    ~Connexion();

private slots:
 void on_register_link_clicked();

 void on_pushButton_clicked();

private:
    Ui::Connexion *ui;
    Register *r = new Register();
    CandidatScreen *cs = new CandidatScreen();
};

#endif // CONNEXION_H
