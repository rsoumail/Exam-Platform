#ifndef ORGANISATEURAFFICHERNOTESFRAME_H
#define ORGANISATEURAFFICHERNOTESFRAME_H

#include <QFrame>

namespace Ui {
class OrganisateurAfficherNotesFrame;
}

class OrganisateurAfficherNotesFrame : public QFrame
{
    Q_OBJECT

public:
    explicit OrganisateurAfficherNotesFrame(QWidget *parent = 0);
    ~OrganisateurAfficherNotesFrame();

private:
    Ui::OrganisateurAfficherNotesFrame *ui;
};

#endif // ORGANISATEURAFFICHERNOTESFRAME_H
