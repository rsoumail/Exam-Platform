#ifndef MONDOSSIERFRAME_H
#define MONDOSSIERFRAME_H

#include <QFrame>

namespace Ui {
class MonDossierFrame;
}

class MonDossierFrame : public QFrame
{
    Q_OBJECT

public:
    explicit MonDossierFrame(QWidget *parent = 0);
    ~MonDossierFrame();

private slots:
    void on_btn_acte_naissance_clicked();

    void on_btn_cv_clicked();


    void on_btn_photo_clicked();

    void on_btn_diplome_clicked();

private:
    Ui::MonDossierFrame *ui;
};

#endif // MONDOSSIERFRAME_H
