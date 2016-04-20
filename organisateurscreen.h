#ifndef ORGANISATEURSCREEN_H
#define ORGANISATEURSCREEN_H

#include <QMainWindow>

namespace Ui {
class OrganisateurScreen;
}

class OrganisateurScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit OrganisateurScreen(QWidget *parent = 0);
    ~OrganisateurScreen();

private:
    Ui::OrganisateurScreen *ui;
};

#endif // ORGANISATEURSCREEN_H
