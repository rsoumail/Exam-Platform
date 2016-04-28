#include "utilisateur.h"
#include <fstream>
#include <list>

using namespace std;


class Administrateur: public Utilisateur {

private:


public:
    Administrateur();
    Administrateur(int, QString, QString, QString, QString, QString , QString , QString , QString , QString, QString, QString, Groupe);
    Administrateur(const Administrateur&);
    Administrateur& operator=(const Administrateur&);
    friend ostream& operator<<(ostream&, const Administrateur&);
    friend istream& operator>>(istream&, Administrateur&);
    ~Administrateur();

};


