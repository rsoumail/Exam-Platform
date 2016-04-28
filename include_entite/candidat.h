#include "organisateur.h"
#include "concours.h"
#include <fstream>
#include <list>

using namespace std;


class Candidat: public Utilisateur {

private:

public:
    Candidat();
    Candidat(int, QString, QString, QString, QString, QString , QString , QString , QString , QString, QString, QString, Groupe);
    Candidat(const Candidat&);
    Candidat& operator=(const Candidat&);
    friend ostream& operator<<(ostream&, const Candidat&);
    friend istream& operator>>(istream&, Candidat&);
    ~Candidat();

};
