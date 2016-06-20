#ifndef ADMINLISTECONCOURSFRAME_H
#define ADMINLISTECONCOURSFRAME_H

#include <QFrame>
#include "admincreerconcoursframe.h"

namespace Ui {
class AdminListeConcoursFrame;
}

class AdminListeConcoursFrame : public QFrame
{
    Q_OBJECT

public:
    explicit AdminListeConcoursFrame(QWidget *parent = 0);
    ~AdminListeConcoursFrame();

    Administrateur getUser() const;
    void setUser(const Administrateur &value);

private slots:
    void recordSelected(QSqlTableModel *);

    void on_table_liste_concours_clicked(const QModelIndex &index);

private:
    Ui::AdminListeConcoursFrame *ui;
    Administrateur user;

};

#endif // ADMINLISTECONCOURSFRAME_H
