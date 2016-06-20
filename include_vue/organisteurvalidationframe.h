#ifndef ORGANISTEURVALIDATIONFRAME_H
#define ORGANISTEURVALIDATIONFRAME_H

#include <QFrame>
#include "organisateuraffichernotesframe.h"

namespace Ui {
class OrganisteurValidationFrame;
}

class OrganisteurValidationFrame : public QFrame
{
    Q_OBJECT

public:
    explicit OrganisteurValidationFrame(QWidget *parent = 0);
    ~OrganisteurValidationFrame();

    Dossier getDossier_a_modifier() const;
    void setDossier_a_modifier(const Dossier &value);

private:
    Ui::OrganisteurValidationFrame *ui;
    Dossier dossier_a_modifier;
};

#endif // ORGANISTEURVALIDATIONFRAME_H
