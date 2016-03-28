#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>

namespace Ui {
class Connexion;
}

class Connexion : public QMainWindow
{
    Q_OBJECT

public:
    explicit Connexion(QWidget *parent = 0);
    ~Connexion();

private:
    Ui::Connexion *ui;
};

#endif // CONNEXION_H
