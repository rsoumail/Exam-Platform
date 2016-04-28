#include <QtSql>
#include <list>
#include "dossier_manager.h"

using namespace std;

class ConcoursManager
{

  private:
    QSqlDatabase db;
    

  public:
    ConcoursManager();
    int save(const Concours&);
    int update(const Concours&);
    int count();
    Concours unique(int);
    list<Concours> all();

};
