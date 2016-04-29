#ifndef ADMINISTRATEURSCREEN_H
#define ADMINISTRATEURSCREEN_H

#include <QMainWindow>

namespace Ui {
class AdministrateurScreen;
}

class AdministrateurScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdministrateurScreen(QWidget *parent = 0);
    ~AdministrateurScreen();

private:
    Ui::AdministrateurScreen *ui;
};

#endif // ADMINISTRATEURSCREEN_H
