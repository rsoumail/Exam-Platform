#include <fstream>
#include <QString>

using namespace std;

class Concours{

private:
    int id_;
    QString annee_;
    int age_limite_;
    QString date_limite_;
    QString date_resultats_;
    int statut_;

public:
    Concours();
    Concours(QString, int, QString);
    Concours(const Concours&);
    Concours& operator=(const Concours&);
    friend ostream& operator<<(ostream&, const Concours&);
    friend istream& operator>>(istream&, Concours&);
    void setId(int);
    void setAge_limite(int);
    void setAnnee(QString);
    void setDate_limite(QString);
    void setDate_resultats(QString);
    void setStatut(int);
    ~Concours();

    int id() const;
    QString annee() const;
    int age_limite() const;
    QString date_limite() const;
    QString date_resultats() const;
    int statut() const;
};
