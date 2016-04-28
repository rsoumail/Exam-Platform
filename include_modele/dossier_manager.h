#include <QSql>
#include <list>
#include "organisateur_manager.h"
using namespace std;
class DossierManager
{

  private:
    QSqlDatabase db;
    

  public:
    DossierManager();
    int save(const Dossier&);
    int update(const Dossier&);
    int count();
    Dossier unique(int id);
    list<Dossier> all();

};
