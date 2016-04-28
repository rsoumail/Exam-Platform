#include <fstream>
#include "candidat.h"
class Candidature{

private:
    int id_;
    double note_math_;
    double note_physique_;
    double note_francais_;
    double note_culture_generale_;
    double moyenne_;
    Candidat candidat_;
    Concours concours_;
    int statut_;

public:
    Candidature();
    Candidature(Candidat, Concours);
    Candidature(const Candidature&);
    Candidature& operator=(const Candidature&);
    friend ostream& operator<<(ostream&, const Candidature&);
    friend istream& operator>>(istream&, Candidature&);
    void setId(int);
    void setNote_math(double);
    void setNote_physique(double);
    void setNote_francais(double);
    void setNote_culture_generale(double);
    void setCandidat(const Candidat&);
    void setConcours(const Concours&);
    void setStatut(int);

    ~Candidature();

    int id() const;
    double note_math() const;
    double note_physique() const;
    double note_francais() const;
    double note_culture_generale() const;
    double moyenne() const;
    void setMoyenne(double moyenne);
    Candidat candidat() const;
    Concours concours() const;
    int statut() const;
};
