#include <QString>
#include "candidature.h"
class Dossier{

private:
    int id_;
    QString cv_;
    QString photo_;
    QString diplome_;
    int statut_;
    Candidature candidature_;

public:
    Dossier();
    Dossier(Candidature&);
    Dossier(const Dossier&);
    Dossier& operator=(const Dossier&);
    friend ostream& operator<<(ostream&, const Dossier&);
    friend istream& operator>>(istream&, Dossier&);
    void setId(int value);
    void setCv(QString);
    void setPhoto(QString);
    void setDiplome(QString);
    void setStatut(int value);
    void setCandidature(const Candidature&);
    ~Dossier();

    int id() const;
    QString cv() const;
    QString photo() const;
    QString diplome() const;
    int statut() const;
    Candidature candidature() const;
};
