#include "personne.h"
#include "groupe.h"

class Utilisateur:public Personne{

  protected:
    int id_;
    QString pseudo_;
    QString password_;
    Groupe groupe_;

  public:
    Utilisateur();
    Utilisateur(int, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, QString, Groupe);
    Utilisateur(const Utilisateur&);
    Utilisateur& operator=(const Utilisateur&);
    friend ostream& operator<<(ostream&, const Utilisateur&);
    friend istream& operator>>(istream&, Utilisateur&);
    ~Utilisateur();

    QString pseudo() const;
    void setPseudo(const QString &pseudo);
    QString password() const;
    void setPassword(const QString &password);
    Groupe groupe() const;
    void setGroupe(const Groupe &groupe);
    int id() const;
    void setId(int id);
};
