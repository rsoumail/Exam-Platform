#include "administrateur.h"
#include <fstream>
#include <list>

using namespace std;


class Organisateur: public Utilisateur {

  private:

  public:
    Organisateur();
    Organisateur(int, QString, QString, QString, QString, QString , QString , QString , QString , QString, QString, QString, Groupe);
    Organisateur(const Organisateur&);
    Organisateur& operator=(const Organisateur&);
    friend ostream& operator<<(ostream&, const Organisateur&);
    friend istream& operator>>(istream&, Organisateur&);
    ~Organisateur();

};

