#ifndef ADMINCREERCONCOURSFRAME_H
#define ADMINCREERCONCOURSFRAME_H

#include <QFrame>
#include "adminlistecompteframe.h"

namespace Ui {
class AdminCreerConcoursFrame;
}

class AdminCreerConcoursFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AdminCreerConcoursFrame(QWidget *parent = 0);
    ~AdminCreerConcoursFrame();

    Administrateur getUser() const;
    void setUser(const Administrateur &value);

    int getSave_or_update() const;
    void setSave_or_update(int value);

    Concours getConcours() const;
    void setConcours(const Concours &value);

private slots:
    void on_btn_enregistrer_clicked();

private:
    Ui::AdminCreerConcoursFrame *ui;
    Administrateur user;
    int save_or_update;
    Concours concours;
    ConcoursManager concoursManager;
};

#endif // ADMINCREERCONCOURSFRAME_H
