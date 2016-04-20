#ifndef CANDIDATSCREEN_H
#define CANDIDATSCREEN_H

#include <QMainWindow>

namespace Ui {
class CandidatScreen;
}

class CandidatScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit CandidatScreen(QWidget *parent = 0);
    ~CandidatScreen();

private:
    Ui::CandidatScreen *ui;
};

#endif // CANDIDATSCREEN_H
